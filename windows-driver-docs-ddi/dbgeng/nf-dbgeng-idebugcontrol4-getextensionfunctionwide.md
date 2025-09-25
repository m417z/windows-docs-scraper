# IDebugControl4::GetExtensionFunctionWide

## Description

The **GetExtensionFunctionWide** method returns a pointer to an extension function from an extension library.

## Parameters

### `Handle` [in]

Specifies the handle of the extension library that contains the extension function. If *Handle* is zero, the engine will walk the extension library chain searching for the extension function.

### `FuncName` [in]

Specifies the name of the extension function to return. When searching the extension libraries for the function, the debugger engine will prepend "_EFN_" to the name. For example, if *FuncName* is "SampleFunction", the engine will search the extension libraries for "_EFN_SampleFunction".

### `Function` [out]

Receives the extension function.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

Extension libraries are loaded into the host engine and extension functions cannot be called remotely. The current client must not be a debugging client, it must belong to the host engine.

The extension function can have any function prototype. In order for any program to call this extension function, the extension function should be cast to the correct prototype.

For more information on using extension functions, see [Calling Extensions and Extension Functions](https://learn.microsoft.com/windows-hardware/drivers/debugger/calling-extensions-and-extension-functions).

## See also

[AddExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-addextension)

[CallExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-callextension)

[GetExtensionByPath](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getextensionbypath)

[IDebugControl4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol4)