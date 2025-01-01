use std::pin::Pin;

use autocxx::prelude::*;

// hack to make autocxx's generated code useable in other modules
pub mod pub_ffi {
    pub use super::ffi::*;
}

include_cpp! {
    #include "clientapi.h"
    #include "helper.h"
    safety!(unsafe_ffi)
    generate!("ClientUser")
    generate!("ClientApi")
    generate!("StrPtr")
    generate!("StrBuf")
    generate!("Error")
    generate!("P4Libraries")
    generate!("P4LibrariesInits")
}

#[cxx::bridge]
pub mod ffi2 {
    unsafe extern "C++" {
        include!("clientapi.h");
        type ClientApi = crate::bindings::ffi::ClientApi;
        #[rust_name = "HackSetArgv"]
        unsafe fn SetArgv(self: Pin<&mut ClientApi>, argc: i32, argv: *const *mut c_char);
    }
}

// https://voidcomputing.hu/blog/autocxx/#calling-a-superclass-method
pub trait SuperclassHack {
    #[allow(invalid_reference_casting)]
    fn as_superclass_hack<T>(self: Pin<&mut Self>) -> Pin<&mut T>
    where
        Self: AsRef<T>,
    {
        let converted_ref = (*self).as_ref();
        let immutable_ptr = converted_ref as *const T;
        let mutable_ptr = immutable_ptr as *mut T;
        unsafe { Pin::new_unchecked(&mut *mutable_ptr) }
    }
}

impl SuperclassHack for crate::bindings::ffi::StrBuf {}