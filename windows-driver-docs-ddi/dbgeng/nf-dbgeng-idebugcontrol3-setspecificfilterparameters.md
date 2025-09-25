# IDebugControl3::SetSpecificFilterParameters

## Description

The **SetSpecificFilterParameters** method changes the [break status](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-filter-xxx) and [handling status](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-filter-xxx) for some specific event filters.

## Parameters

### `Start` [in]

Specifies the index of the first specific event filter whose parameters will be changed.

### `Count` [in]

Specifies the number of specific event filters whose parameters will be changed.

### `Params` [in]

Specifies an array of specific event filter parameters of type [DEBUG_SPECIFIC_FILTER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_specific_filter_parameters). Only the **ExecutionOption** and **ContinueOption** members are used. **ExceptionOption** specifies the new break status and **ContinueOption** specifies the new handling status.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information about [event filters](https://learn.microsoft.com/windows-hardware/drivers/debugger/event-filters), see [Event Filters](https://learn.microsoft.com/windows-hardware/drivers/debugger/event-filters).

## See also

[GetSpecificFilterParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getspecificfilterparameters)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[SetExceptionFilterParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setexceptionfilterparameters)

[sx, sxd, sxe, sxi, sxn (Set Exceptions)](https://learn.microsoft.com/windows-hardware/drivers/debugger/sx--sxd--sxe--sxi--sxn--sxr--sx---set-exceptions-)