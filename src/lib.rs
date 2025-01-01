
mod bindings;

pub use bindings::pub_ffi as ffi;
pub use bindings::ffi2 as ffi2;
pub use bindings::SuperclassHack;


#[link(name = "CoreFoundation", kind = "framework")]
extern "C" {}

#[link(name = "Security", kind = "framework")]
extern "C" {}

#[link(name = "crypto", kind = "dylib")]
extern "C" {}

#[link(name = "ssl", kind = "dylib")]
extern "C" {}

#[link(name = "z", kind = "dylib")]
extern "C" {}

