# IDebugControl3::GetSpecificFilterParameters

## Description

The **GetSpecificFilterParameters** method returns the parameters for specific event filters.

## Parameters

### `Start` [in]

Specifies the index of the first specific event filter whose parameters will be returned.

### `Count` [in]

Specifies the number of specific event filters to return parameters for.

### `Params` [out]

Receives the parameters for the specific event filters. *Params* is an array of elements of type [DEBUG_SPECIFIC_FILTER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_specific_filter_parameters).

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information about [event filters](https://learn.microsoft.com/windows-hardware/drivers/debugger/event-filters), see [Event Filters](https://learn.microsoft.com/windows-hardware/drivers/debugger/event-filters).

## See also

[GetExceptionFilterParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getexceptionfilterparameters)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[SetSpecificFilterParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setspecificfilterparameters)

[sx, sxd, sxe, sxi, sxn (Set Exceptions)](https://learn.microsoft.com/windows-hardware/drivers/debugger/sx--sxd--sxe--sxi--sxn--sxr--sx---set-exceptions-)