# DRMLoadLibrary function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMLoadLibrary** function loads a handle to an approved library, as determined by the credentials.

## Parameters

### `hEnv` [in]

A handle to an environment, created by [DRMInitEnvironment](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drminitenvironment).

### `eSpecification` [in]

The library provider type.

### `wszLibraryProvider` [in]

Name and optional path to the DLL. Every DLL must have a unique name. If similarly named DLLs are loaded, even if they are in different paths, only the first item will be included in the manifest and checked.

### `wszCredentials` [in]

Reserved, must be **NULL**. The DLL that is loaded must be referenced in the application manifest loaded by [DRMInitEnvironment](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drminitenvironment).

### `phLibrary` [out]

A handle to the library.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This function is a secure version of the **LoadLibrary** function, however it does not support the extra options of **LoadLibraryEx**. The returned handle corresponds to the HMODULE output by LoadLibrary. To close the handle returned, call [DRMCloseHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosehandle), not **FreeLibrary**. By default, the current directory is the only location this function searches for a library. Any other directory must be specified by either a full path, or a path relative to the current directory. Use [DRMGetProcAddress](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetprocaddress), the secure version of the **GetProcAddress** function, to get function addresses in loaded libraries.

Dependencies of the loaded DLL will also be loaded, provided they are included in the plug-in credentials and are properly signed. If the DLL has already been loaded, the function will return S_OK and return a pointer to the same handle.

**Note** If an application attempts to load a second library with the name of a previously loaded library, this new library will not be checked against the manifest, even if it is from a different path. Use only uniquely named libraries to avoid this circumvention of manifest checking.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMGetProcAddress](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetprocaddress)