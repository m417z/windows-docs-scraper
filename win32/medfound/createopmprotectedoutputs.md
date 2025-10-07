# CreateOPMProtectedOutputs function

> [!IMPORTANT]
> This function is used by [Output Protection Manager](https://learn.microsoft.com/windows/win32/medfound/output-protection-manager) (OPM) to access functionality in the display driver. Applications should not call this function.

Creates protected output objects for a display device.

## Parameters

*pstrDeviceName* \[in\]

A pointer to a [**UNICODE\_STRING**](https://learn.microsoft.com/windows/win32/api/subauth/ns-subauth-unicode_string) structure that contains the name of the display device, as returned by the [**GetMonitorInfo**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getmonitorinfoa) function.

*vos* \[in\]

A member of the **DXGKMDT\_OPM\_VIDEO\_OUTPUT\_SEMANTICS** enumeration, specifying whether the protected output will have Certified Output Protection Protocol (COPP) semantics or OPM semantics.

*dwOPMProtectedOutputArraySize* \[in\]

The number of elements in the *pohOPMProtectedOutputArray* array.

*pdwNumOPMProtectedOutputsInArray* \[out\]

Receives the number of items that the function copies to the *pohOPMProtectedOutputArray* array.

*pohOPMProtectedOutputArray* \[out\]

An array that receives handles to the protected output objects. Each handle must be released by calling [**DestroyOPMProtectedOutput**](https://learn.microsoft.com/windows/win32/medfound/destroyopmprotectedoutput).

## Return value

If the method succeeds, it returns **STATUS\_SUCCESS**. Otherwise, it returns an **NTSTATUS** error code.

## Remarks

Instead of using this function, applications should call one of the following functions:

- [**OPMGetVideoOutputsFromIDirect3DDevice9Object**](https://learn.microsoft.com/windows/desktop/api/opmapi/nf-opmapi-opmgetvideooutputsfromidirect3ddevice9object)
- [**OPMGetVideoOutputsFromHMONITOR**](https://learn.microsoft.com/windows/desktop/api/opmapi/nf-opmapi-opmgetvideooutputsfromhmonitor)

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

