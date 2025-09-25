# IDebugSymbols2::GetModuleParameters

## Description

The **GetModuleParameters** method returns parameters for [modules](https://learn.microsoft.com/windows-hardware/drivers/debugger/modules) in the target.

## Parameters

### `Count` [in]

Specifies the number of modules whose parameters are desired.

### `Bases` [in, optional]

Specifies an array of locations in the target's virtual address space representing the base address of the modules whose parameters are desired. The size of this array is the value of *Count*. If *Bases* is **NULL**, the *Start* parameter is used to specify the modules by index.

### `Start` [in]

Specifies the index of the first module whose parameters are desired. If *Bases* is not **NULL**, this parameter is ignored.

### `Params` [out]

Receives the parameters. The size of this array is the value of *Count*. See [DEBUG_MODULE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_module_parameters).

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. However, if *Bases* is not **NULL**, it is possible that not all of the modules were found, in which case partial results are returned. |
| **E_INVALIDARG** | When *Bases* is **NULL**, this value indicates that the target contains fewer than the sum of *Count* and *Start* modules. Partial results are returned. |

## Remarks

In the cases when partial results are returned, the entries in the array *Params* corresponding to modules that could not be found have their **Base** field set to DEBUG_INVALID_OFFSET. See [DEBUG_MODULE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_module_parameters).

For more information about modules, see [Modules](https://learn.microsoft.com/windows-hardware/drivers/debugger/modules).

## See also

[DEBUG_MODULE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_module_parameters)

[IDebugSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)