# IDebugSymbols3::GetModuleByModuleName2

## Description

The **GetModuleByModuleName2** method searches through the process's [modules](https://learn.microsoft.com/windows-hardware/drivers/debugger/modules) for one with the specified name.

## Parameters

### `Name` [in]

Specifies the name of the desired module.

### `StartIndex` [in]

Specifies the index to start searching from.

### `Flags` [in]

Specifies a bit-set containing options used when searching for the module with the specified name. *Flags* may contain the following bit-flags:

| Flag | Effect |
| --- | --- |
| DEBUG_GETMOD_NO_LOADED_MODULES | Do not search the loaded modules. |
| DEBUG_GETMOD_NO_UNLOADED_MODULES | Do not search the unloaded modules. |

### `Index` [out, optional]

Receives the index of the first module with the name *Name*. If *Index* is **NULL**, this information is not returned.

### `Base` [out, optional]

Receives the location in the target's memory address space of the base of the module. If *Base* is **NULL**, this information is not returned.

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One of the arguments passed in was invalid. |

## Remarks

Starting at the specified index, these methods return the first module they find with the specified name. If the target has more than one module with this name, then subsequent modules can be found by repeated calls to these methods with higher values of *StartIndex*.

For more information about modules, see [Modules](https://learn.microsoft.com/windows-hardware/drivers/debugger/modules).

## See also

[GetModuleByModuleName](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getmodulebymodulename)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)