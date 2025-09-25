# IDebugControl::RemoveExtension

## Description

The **RemoveExtension** method unloads an extension library.

## Parameters

### `Handle` [in]

Specifies the handle of the extension library to unload. This is the handle returned by [AddExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-addextension).

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

For more information on using extension libraries, see [Calling Extensions and Extension Functions](https://learn.microsoft.com/windows-hardware/drivers/debugger/calling-extensions-and-extension-functions).

## See also

[AddExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-addextension)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)