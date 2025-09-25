# IDebugControl2::AddExtension

## Description

The **AddExtension** method loads an extension library into the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction).

## Parameters

### `Path` [in]

Specifies the fully qualified path and file name of the extension library to load.

### `Flags` [in]

Set to zero.

### `Handle` [out]

Receives the handle of the loaded extension library.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

If the extension library has already been loaded, the handle to already loaded library is returned. The extension library is not loaded again.

The extension library is loaded into the host engine and *Path* contains a path and file name for this instance of the debugger engine.

AddExtension does not complete the process of loading and initializing the extension DLL. To make the extension available for use, make a subsequent call to the [GetExtensionFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol2-getextensionfunction).

For more information on using extension libraries, see [Calling Extensions and Extension Functions](https://learn.microsoft.com/windows-hardware/drivers/debugger/calling-extensions-and-extension-functions).

## See also

 [GetExtensionFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol2-getextensionfunction)

[GetExtensionByPath](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getextensionbypath)

[RemoveExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-removeextension)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)