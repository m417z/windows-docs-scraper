# IDebugControl3::GetCurrentEventIndex

## Description

The **GetCurrentEventIndex** method returns the index of the current event within the current list of events for the current target, if such a list exists.

## Parameters

### `Index` [out]

Receives the index of the current event in the target. The index will be a number between zero and one less than the number of events returned by [GetNumberEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getnumberevents). The index of the first event is zero.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

Targets that do not have fixed sets of events will always return zero to *Index*.

## See also

[GetNumberEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getnumberevents)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[SetNextEventIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setnexteventindex)