# _DEBUG_SPECIFIC_FILTER_PARAMETERS structure

## Description

The DEBUG_SPECIFIC_FILTER_PARAMETERS structure contains the parameters for a [specific event filter](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-filter-xxx).

## Members

### `ExecutionOption`

The [break status](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-filter-xxx) of the specific event filter. For possible values, see **DEBUG_FILTER_XXX**.

### `ContinueOption`

The [handling status](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-filter-xxx) of the specific event filter. For possible values, see **DEBUG_FILTER_XXX**.

### `TextSize`

The size, in characters (including the terminator), of the name of the specific event filter.

### `CommandSize`

The size, in characters, of the command (including the terminator), to execute when the event occurs.

### `ArgumentSize`

Specifies the size, in characters, of the specific event filter argument. This size includes the NULL terminator. If the specific event filter does not take an argument, **ArgumentSize** is zero.

**Note** If the filter does take an argument, but the argument is empty, **ArgumentSize** will be one, reflecting the NULL terminator.

## See also

[GetSpecificFilterParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getspecificfilterparameters)

[SetSpecificFilterParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setspecificfilterparameters)