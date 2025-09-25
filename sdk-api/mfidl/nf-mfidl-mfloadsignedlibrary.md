# MFLoadSignedLibrary function

## Description

Loads a dynamic link library that is signed for the protected environment.

## Parameters

### `pszName` [in]

The name of the dynamic link library to load. This dynamic link library must be signed for the protected environment.

### `ppLib` [out]

Receives a pointer to the [IMFSignedLibrary](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsignedlibrary) interface for the library.

## Remarks

A singlemodule load count is maintained on the dynamic link library (as it is with [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya)). This load count is freed when the final release is called on the [IMFSignedLibrary](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsignedlibrary) object.

#### Examples

The following example demonstrates how to load a signed library and retrieve the address of a function in that library.

```cpp
IMFSignedLibrary *pLib;
hr = MFLoadSignedLibrary(TEST_PELOAD_FILE, &pLib);
if (SUCCEEDED(hr))
{
    PVOID functionAddress;
    hr = pLib->GetProcedureAddress("myFunctionName", &functionAddress);
}
//  Unload the library
pLib->Release();

```

## See also

[GetProcedureAddress](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsignedlibrary-getprocedureaddress)

[IMFSignedLibrary](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsignedlibrary)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)