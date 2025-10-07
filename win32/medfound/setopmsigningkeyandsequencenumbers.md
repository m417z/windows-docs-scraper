# SetOPMSigningKeyAndSequenceNumbers function

> [!IMPORTANT]
> This function is used by [Output Protection Manager](https://learn.microsoft.com/windows/win32/medfound/output-protection-manager) (OPM) to access functionality in the display driver. Applications should not call this function.

Sets the signing key and two sequence numbers on a protected output object.

## Parameters

*opoOPMProtectedOutput* \[in\]

A handle to the protected output object. This handle is obtained by calling [**CreateOPMProtectedOutputs**](https://learn.microsoft.com/windows/win32/medfound/createopmprotectedoutputs).

*pParameters* \[out\]

A pointer to a [**DXGKMDT\_OPM\_ENCRYPTED\_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_encrypted_parameters) structure that contains a 256-byte array. For more information about how to initialize this array, see [DxgkDdiOPMSetSigningKeyAndSequenceNumbers](https://msdn.microsoft.com/library/aa906703.aspx).

## Return value

If the method succeeds, it returns **STATUS\_SUCCESS**. Otherwise, it returns an **NTSTATUS** error code.

## Remarks

Applications should call [**IOPMVideoOutput::FinishInitialization**](https://learn.microsoft.com/windows/desktop/api/opmapi/nf-opmapi-iopmvideooutput-finishinitialization) instead of calling this function.

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

