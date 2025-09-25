# IDebugControl2::SetExceptionFilterParameters

## Description

The **SetExceptionFilterParameters** method changes the [break status](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-filter-xxx) and [handling status](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-filter-xxx) for some exception filters.

## Parameters

### `Count` [in]

Specifies the number of exception filters to change the parameters for.

### `Params` [in]

Specifies an array of exception filter parameters of type [DEBUG_EXCEPTION_FILTER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_exception_filter_parameters). Only the **ExecutionOption**, **ContinueOption**, and **ExceptionCode** fields of these parameters are used. The **ExceptionCode** field is used to identify the [exception](https://learn.microsoft.com/windows-hardware/drivers/) whose exception filter will be changed. **ExceptionOption** specifies the new break status and **ContinueOption** specifies the new handling status.

If the value of the **ExceptionOption** field is DEBUG_FILTER_REMOVE and the exception filter is an arbitrary exception filter, the exception filter will be removed.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_OUTOFMEMORY** | The maximum number of arbitrary exception filters <br><br>has been exceeded. |

## Remarks

For each of the exception filter parameters in *Params*, if the exception, identified by exception code, already has a filter (specific or arbitrary), that filter will be changed. Otherwise, a new arbitrary exception filter will be added for the exception.

For more information about [event filters](https://learn.microsoft.com/windows-hardware/drivers/debugger/event-filters), see [Event Filters](https://learn.microsoft.com/windows-hardware/drivers/debugger/event-filters).

## See also

[GetExceptionFilterParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getexceptionfilterparameters)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[SetSpecificFilterParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setspecificfilterparameters)

[sx, sxd, sxe, sxi, sxn (Set Exceptions)](https://learn.microsoft.com/windows-hardware/drivers/debugger/sx--sxd--sxe--sxi--sxn--sxr--sx---set-exceptions-)