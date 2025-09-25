# IDebugSymbols2::GetModuleByOffset

## Description

The **GetModuleByOffset** method searches through the target's [modules](https://learn.microsoft.com/windows-hardware/drivers/debugger/modules) for one whose memory allocation includes the specified location.

## Parameters

### `Offset` [in]

Specifies a location in the target's virtual address space which is inside the desired module's memory allocation -- for example, the address of a symbol belonging to the module.

### `StartIndex` [in]

Specifies the index to start searching from.

### `Index` [out, optional]

Receives the index of the module. If *Index* is **NULL**, this information is not returned.

### `Base` [out, optional]

Receives the location in the target's memory address space of the base of the module. If *Base* is **NULL**, this information is not returned.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

Starting at the specified index, this method returns the first module it finds whose memory allocation address range includes the specified location. If the target has more than one module whose memory address range includes this location, then subsequent modules can be found by repeated calls to this method with higher values of *StartIndex*.

For more information about modules, see [Modules](https://learn.microsoft.com/windows-hardware/drivers/debugger/modules).

## See also

[GetModuleByIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getmodulebyindex)

[GetModuleByOffset2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getmodulebyoffset2)

[IDebugSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)