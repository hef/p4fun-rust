== Creating Rust Bindings for libp4 Work in Progress == 

In binding rust to libp4 code, there are some crates doing most of the heavy lifting.

* [cc](https://crates.io/crates/cc) compile c/c++ in build.rs
* [cxx](https://crates.io/crates/cxx) "manually" build up a rust/c++ interop layer.  This expects you to write both c++ and rust to grow interfaces towards eachother.  This is very useful as an escape hatch when autocxx doesn't get something right, or needs massaging.
* [autocxx](https://crates.io/crates/cxx) Automatically create bindings for rust from existing c++.  There is an autocxx-build component for codegen.  


== Approach ==

I wanted to port the p4api.cc sample code to rust as a proof of concept of calling libp4 code from rust.

Instead of using a prebuilt p4lib, I just grabbed p4source-2024.2.2697822 and used the [cc](https://crates.io/crates/cc) crate to compile c++ and C in `build.rs`.  I suspect this approach would be easier to support in the long run.  I took `p4source/api/p4api.cc` and started porting it to rust.  I added the generate!() macros for `ClientUser` and `ClientApi` and just kept resolving errors in compilation and linking.  For missing symbols, I mostly just used the `#[link]` directive on `extern C{}` blocks to link against system libs.  I think this could be done in build.rs with some cargo directives.

Dealing with SetArgV was a little complicated, autocxx won't generate bindings methods for double pointers in their signature, and in p4api.cc, the call to SetArgv uses offsets into the Argv array as the start of the array.  I ended up just mapping into appropriate types of appropriately sized arrays and that worked out.  Using `CString::into_raw` was interesting, I expected to need to reclaim the memory after, but the p4 lib consumed it.

When I hit a missing symbol, I just googled it to see where the symbol should be defined, and just added a link.  I did this in a platform dependent way for os x, so this needs to be revisisted.

Once I solved the compilation and link problems, the runtime "just worked".  I haven't tested it extensively, so ymmv.
 

== Unsolved ==

* So far, this only builds for OSX.  I believe supporting other linux and windows is possible.
* ranlib produces a lot of "has no symbol" warnings.  I didn't find a way to add args to ranlib in `cc`
* It would be nice to use an existing openssl crate and gzip crate to reduce host platform dependencies.
* the linker warnings `was built for newer 'macOS' version (15.2) than being linked (10.12)` shows up a lot, I should figure out what that implies, and what to do about it.

== Thoughts ==

* It's weird that you can't call superclass methods in autocxx generated code, even if they would be exposed in c++, hence the need for the SuperclassHack to expose StrPtr methods on StrBuf.
* * It should be possible to just add methods manually using `#[cxx::bridge]` and would have a nicer api than the casting I'm currently doing.
* While it's nice that autocxx creates a dummy placeholder for methods it can't reflect into rust correctly, it's unfortuneate that there isn't a good way to blocklist just the bad method so that I could implement in manually. This is why I had to name the SetArgV method to HackSetArgV
** the autocxx docs suggest just whitelisting every other method and manually implementing the problematic ones.  I didn't want to do that for a proof of concept because there are a lot fo them.
* The perforce lib has tooling to use a stub ssl implementation and disable ssl. I wonder if I could exploit that to use e.g. [rustls](https://docs.rs/rustls/latest/rustls/) instead of openssl.
* A previous attempt to create rust bindings to libp4 failed because ClientApi used to have pure virtual methods on a base class, and `autocxx` couldn't handle that.  I didn't dig around `cxx::bridge` at the time to see if it could be worked around.  For this attempts I was expecting to need to create a wrapper c++ class for ClientApi, but didn't have to because perforce changed ClientApi interface to not have pure virtual stuff in it anymore.
