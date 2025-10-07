# MFCreateCaptureEngine function

\[MFCreateCaptureEngine is not supported and may be altered or unavailable in the future. \]

Creates an instance of the capture engine.

## Parameters

*ppCaptureEngine* \[out\]

Receives a pointer to the [**IMFCaptureEngine**](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcaptureengine) interface. The caller must release the interface.

## Return value

If the function succeeds, it returns S\_OK. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function has no associated import library and is not declared in a public header file. You must use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to MFCaptureEngine.dll.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 R2 \[desktop apps only\]<br> |
| DLL<br> | MFCaptureEngine.dll |

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/win32/medfound/media-foundation-functions)

