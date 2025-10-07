# GetCertificate function

> [!IMPORTANT]
> This function is used by [Output Protection Manager](https://learn.microsoft.com/windows/win32/medfound/output-protection-manager) (OPM) to access functionality in the display driver. Applications should not call this function.

Gets a certificate for a display driver.

## Parameters

*pstrDeviceName* \[in\]

A pointer to a [**UNICODE\_STRING**](https://learn.microsoft.com/windows/win32/api/subauth/ns-subauth-unicode_string) structure that contains the name of the display device, as returned by the [**GetMonitorInfo**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getmonitorinfoa) function.

*ctPVPCertificateType* \[in\]

The type of certificate, specified as a member of the **DXGKMDT\_CERTIFICATE\_TYPE** enumeration.

*pbCertificate* \[out\]

A pointer to a buffer that receives the certificate.

*ulCertificateLength* \[out\]

The size of the *pbCertificate* buffer, in bytes. To get the size of the certificate, call [**GetCertificateSize**](https://learn.microsoft.com/windows/win32/medfound/getcertificatesize).

## Return value

If the method succeeds, it returns **STATUS\_SUCCESS**. Otherwise, it returns an **NTSTATUS** error code.

## Remarks

Applications should call the [**IOPMVideoOutput::StartInitialization**](https://learn.microsoft.com/windows/desktop/api/opmapi/nf-opmapi-iopmvideooutput-startinitialization) method instead of this function.

This function has no associated import library. To call this function, you must use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Gdi32.dll.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Gdi32.dll |

## See also

[OPM Functions](https://learn.microsoft.com/windows/win32/medfound/opm-functions)

[Output Protection Manager](https://learn.microsoft.com/windows/win32/medfound/output-protection-manager)

