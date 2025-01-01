use std::{
    ffi::{c_schar, CString}, process::ExitCode
};

use autocxx::prelude::*;


use p4fun_rust::{ffi, ffi2, SuperclassHack};


fn main() -> ExitCode {
    let ui = ffi::ClientUser::new(autocxx::c_int(0), autocxx::c_int(-1)).within_unique_ptr();
    let mut client = ffi2::ClientApi::new().within_unique_ptr();
    let mut msg = ffi::StrBuf::new().within_unique_ptr();
    let e = ffi::Error::new().within_unique_ptr();
    

    return unsafe {
        ffi::P4Libraries::Initialize(autocxx::c_int(15), e.as_mut_ptr());

        if e.Test() != autocxx::c_int(0) {
            e.Fmt(msg.pin_mut(), autocxx::c_int(0x02));
            eprintln!(
                "{}",
                CString::from_raw(msg.pin_mut().as_superclass_hack::<ffi::StrPtr>().Text())
                    .to_string_lossy()
            );
            return ExitCode::from(1);
        }

        client.pin_mut().Init(e.as_mut_ptr());

        if e.Test() != autocxx::c_int(0) {
            e.Fmt(msg.pin_mut(), autocxx::c_int(0x02));
            eprintln!(
                "{}",
                CString::from_raw(msg.pin_mut().as_superclass_hack::<ffi::StrPtr>().Text())
                    .to_string_lossy()
            );
            return ExitCode::from(1);
        }

        // Run the command "argv[1] argv[2...]"

        let args: Vec<String> = std::env::args().collect();

        let command = CString::new(args[1].clone()).unwrap().into_raw();

        let mut c_args: Vec<*mut c_schar> = args
            .into_iter()
            .skip(2)
            .map(|arg| CString::new(arg).unwrap())
            .map(|cstr| cstr.into_raw())
            .collect();

        client
            .pin_mut()
            .HackSetArgv(c_args.len() as i32, c_args.as_mut_ptr());
        client.pin_mut().Run(command, ui.as_mut_ptr());

        // don't reclaim memory strings raw memory, p4lib memmoved it already, you will get a double free error if you try
        //let _ = CString::from_raw(command); 
        //let _ : Vec<CString> = c_args.into_iter().map(|arg| CString::from_raw(arg)).collect();

        client.pin_mut().Final(e.as_mut_ptr());

        if e.Test() != autocxx::c_int(0) {
            e.Fmt(msg.pin_mut(), autocxx::c_int(0x02));
            eprintln!(
                "{}",
                CString::from_raw(msg.pin_mut().as_superclass_hack::<ffi::StrPtr>().Text())
                    .to_string_lossy()
            );
            return ExitCode::from(1);
        }

        ffi::P4Libraries::Shutdown(autocxx::c_int(15), e.as_mut_ptr());
        if e.Test() != autocxx::c_int(0) {
            e.Fmt(msg.pin_mut(), autocxx::c_int(0x02));
            eprintln!(
                "{}",
                CString::from_raw(msg.pin_mut().as_superclass_hack::<ffi::StrPtr>().Text())
                    .to_string_lossy()
            );
            return ExitCode::from(1);
        }
        ExitCode::SUCCESS
    };
}
