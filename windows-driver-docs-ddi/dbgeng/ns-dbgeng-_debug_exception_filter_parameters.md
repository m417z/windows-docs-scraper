# _DEBUG_EXCEPTION_FILTER_PARAMETERS structure

## Description

The DEBUG_EXCEPTION_FILTER_PARAMETERS structure contains the parameters for an exception filter.

## Members

### `ExecutionOption`

The [break status](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-filter-xxx) of the exception filter, including the terminator. For possible values, see **DEBUG_FILTER_XXX**.

### `ContinueOption`

The [handling status](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-filter-xxx) of the exception filter. For possible values, see **DEBUG_FILTER_XXX**.

### `TextSize`

The size, in characters, of the name (including the terminator) of the exception filter. If the filter is an arbitrary exception filter, it does not have a name and **TextSize** is zero.

### `CommandSize`

The size, in characters, of the command (including the terminator) to execute upon the first chance of the exception.

### `SecondCommandSize`

The size, in characters, of the command (including the terminator) to execute upon the second chance of the exception.

### `ExceptionCode`

The exception code for the exception filter.

## See also

[GetExceptionFilterParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getexceptionfilterparameters)

[SetExceptionFilterParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setexceptionfilterparameters)