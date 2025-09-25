# IDebugControl::GetExceptionFilterParameters

## Description

The **GetExceptionFilterParameters** method returns the parameters for exception filters specified by exception codes or by index.

## Parameters

### `Count` [in]

Specifies the number of exception filters for which to return parameters.

### `Codes` [in, optional]

Specifies an array of exception codes. The parameters for the exception filters with these exception codes will be returned. If *Codes* is **NULL**, *Start* is used instead.

### `Start` [in]

Specifies the index of the first exception filter. The parameters for the exception filters starting at *Start* will be returned. If *Codes* is not **NULL**, *Start* is ignored.

### `Params` [out]

Receives the parameters for the exception filters specified by *Codes* or *Start*. *Params* is an array of elements of type [DEBUG_EXCEPTION_FILTER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_exception_filter_parameters).

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