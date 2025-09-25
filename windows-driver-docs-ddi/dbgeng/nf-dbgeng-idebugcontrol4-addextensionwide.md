# IDebugControl4::AddExtensionWide

## Description

The **AddExtensionWide** method loads an extension library into the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction).

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

For more information on using extension libraries, see [Calling Extensions and Extension Functions](https://learn.microsoft.com/windows-hardware/drivers/debugger/calling-extensions-and-extension-functions).

## See also

[GetExtensionByPath](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getextensionbypath)

[IDebugControl4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol4)

[RemoveExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-removeextension)