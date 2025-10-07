# GetCOPPCompatibleOPMInformation function

> [!IMPORTANT]
> This function is used by [Output Protection Manager](https://learn.microsoft.com/windows/win32/medfound/output-protection-manager) (OPM) to access functionality in the display driver. Applications should not call this function.

Sends a Certified Output Protection Protocol (COPP) status request to a protected output object.

## Parameters

*opoOPMProtectedOutput* \[in\]

A handle to the protected output object. This handle is obtained by calling [**CreateOPMProtectedOutputs**](https://learn.microsoft.com/windows/win32/medfound/createopmprotectedoutputs).

*pParameters* \[in\]

A pointer to a **DXGKMDT\_OPM\_COPP\_COMPATIBLE\_GET\_INFO\_PARAMETERS** structure that contains input data for the status request.

*pRequestedInformation* \[out\]

A pointer to a **DXGKMDT\_OPM\_REQUESTED\_INFORMATION** structure that receives the results of the status request.

## Return value

If the method succeeds, it returns **STATUS\_SUCCESS**. Otherwise, it returns an **NTSTATUS** error code.

## Remarks

Applications should call [**IOPMVideoOutput::COPPCompatibleGetInformation**](https://learn.microsoft.com/windows/desktop/api/opmapi/nf-opmapi-iopmvideooutput-coppcompatiblegetinformation) instead of calling this function.

The protected output object must be created with COPP semantics. See [**CreateOPMProtectedOutputs**](https://learn.microsoft.com/windows/win32/medfound/createopmprotectedoutputs).

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

