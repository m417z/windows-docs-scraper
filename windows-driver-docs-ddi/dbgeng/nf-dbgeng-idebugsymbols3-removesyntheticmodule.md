# IDebugSymbols3::RemoveSyntheticModule

## Description

The **RemoveSyntheticModule** method removes a synthetic module from the module list the debugger maintains for the current process.

## Parameters

### `Base` [in]

Specifies the location in the process's virtual address space of the base of the synthetic module.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | No synthetic module was found at the specified location. This is returned if a synthetic module at this location was previously removed or discarded. |

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

If all the modules are reloaded - for example, by calling [Reload](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-reload) with the *Module* parameter set to the empty string - all synthetic modules will be discarded.

For more information about synthetic modules, see Synthetic Modules.

## See also

[AddSyntheticModule](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-addsyntheticmodule)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)

[RemoveSyntheticSymbol](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-removesyntheticsymbol)