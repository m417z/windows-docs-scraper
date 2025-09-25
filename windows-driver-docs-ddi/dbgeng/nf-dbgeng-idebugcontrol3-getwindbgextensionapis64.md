# IDebugControl3::GetWindbgExtensionApis64

## Description

The **GetWindbgExtensionApis64** method returns a structure that facilitates using the WdbgExts API.

## Parameters

### `Api` [in, out]

Receives a WINDBG_EXTENSION_APIS64 structure. This structure contains the functions used by the WdbgExts API. The **nSize** member of this structure must be set to the size of the structure before it is passed to this method.

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | The value of *Api*->**nSize** does not equal the size of the structure WINDBG_EXTENSION_APIS64. |

## Remarks

If you are including Wdbgexts.h in your extension code, you should call this method during the initialization of the extension DLL (see [DebugExtensionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nc-dbgeng-pdebug_extension_initialize)).

Many WdbgExts functions are really macros. To ensure that these macros work correctly, the structure received by the *Api* parameter should be stored in a global variable named **ExtensionApis**.

The WINDBG_EXTENSION_APIS64 structure returned by this method serves the same purpose as the one provided to the callback function [WinDbgExtensionDllInit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-pwindbg_extension_dll_init) (used by WdbgExts extensions).

For a list of the functions provided by the WdbgExts API, see [WdbgExts Functions](https://learn.microsoft.com/windows-hardware/drivers/debugger/wdbgexts-functions).