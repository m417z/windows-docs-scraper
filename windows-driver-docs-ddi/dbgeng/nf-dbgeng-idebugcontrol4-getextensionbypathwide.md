# IDebugControl4::GetExtensionByPathWide

## Description

The **GetExtensionByPathWide** method returns the handle for an already loaded extension library.

## Parameters

### `Path` [in]

Specifies the fully qualified path and file name of the extension library.

### `Handle` [out]

Receives the handle of the extension library.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

Extension libraries are loaded into the [host engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/debugging-session-and-execution-model), which is where this method looks for the requested extension library. *Path* is a path and file name for the host engine.

For more information on using extension libraries, see [Calling Extensions and Extension Functions](https://learn.microsoft.com/windows-hardware/drivers/debugger/calling-extensions-and-extension-functions).

## See also

[AddExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-addextension)

[IDebugControl4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol4)