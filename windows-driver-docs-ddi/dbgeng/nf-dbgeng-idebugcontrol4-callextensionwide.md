# IDebugControl4::CallExtensionWide

## Description

The **CallExtensionWide** method calls a debugger extension.

## Parameters

### `Handle` [in]

Specifies the handle of the extension library that contains the extension to call. If *Handle* is zero, the engine will walk the extension library chain searching for the extension.

### `Function` [in]

Specifies the name of the extension to call.

### `Arguments` [in, optional]

Specifies the arguments to pass to the extension. *Arguments* is a string that will be parsed by the extension, just like the extension will parse arguments passed to it when called as an extension command.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

If *Handle* is zero, the engine searches each extension library until it finds one that contains the extension; the extension will then be called. If the extension returns DEBUG_EXTENSION_CONTINUE_SEARCH, the search will continue.

For more information on using extension libraries, see [Calling Extensions and Extension Functions](https://learn.microsoft.com/windows-hardware/drivers/debugger/calling-extensions-and-extension-functions).

## See also

[AddExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-addextension)

[GetExtensionByPath](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getextensionbypath)

[GetExtensionFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getextensionfunction)

[IDebugControl4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol4)