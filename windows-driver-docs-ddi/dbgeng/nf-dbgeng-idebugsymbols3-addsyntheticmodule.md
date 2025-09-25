# IDebugSymbols3::AddSyntheticModule

## Description

The **AddSyntheticModule** method adds a synthetic module to the module list the debugger maintains for the [current process](https://learn.microsoft.com/windows-hardware/drivers/debugger/c).

## Parameters

### `Base` [in]

Specifies the location in the process's virtual address space of the base of the synthetic module.

### `Size` [in]

Specifies the size in bytes of the synthetic module.

### `ImagePath` [in]

Specifies the image name of the synthetic module. This is the name that will be returned as the name of the executable file for the synthetic module. The full path should be included if known.

### `ModuleName` [in]

Specifies the module name for the synthetic module.

### `Flags` [in]

Set to DEBUG_ADDSYNTHMOD_DEFAULT.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

The memory region of the synthetic module, described by the *Base* and *Size* parameters, must not overlap the memory region of any other module.

If all the modules are reloaded - for example, by calling [Reload](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-reload) with the *Module* parameter set to an empty string - all synthetic modules will be discarded.

For more information about synthetic modules, see [Synthetic Modules](https://learn.microsoft.com/windows-hardware/drivers/debugger/modules).

## See also

[AddSyntheticSymbol](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-addsyntheticsymbol)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)

[RemoveSyntheticModule](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-removesyntheticmodule)