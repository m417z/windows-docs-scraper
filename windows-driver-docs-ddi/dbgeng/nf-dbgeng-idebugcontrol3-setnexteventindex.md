# IDebugControl3::SetNextEventIndex

## Description

The **SetNextEventIndex** method sets the next event for the current target by selecting the event from the static list of events for the target, if such a list exists.

## Parameters

### `Relation` [in]

Specifies how to interpret *Value* when setting the index of the next event. Possible values are: DEBUG_EINDEX_FROM_START, DEBUG_EINDEX_FROM_END, and DEBUG_EINDEX_FROM_CURRENT.

### `Value` [in]

Specifies the index of the next event relative to the first, last, or current event. The interpretation of *Value* depends on the value of *Relation*, as follows.

| Value of *Relation* | Next Event Index |
| --- | --- |
| DEBUG_EINDEX_FROM_START | *Value*. |
| DEBUG_EINDEX_FROM_END | Number of events minus *Value*. |
| DEBUG_EINDEX_FROM_CURRENT | The current event index plus *Value*. |

The resulting index must be greater than zero and one less than the number of events returned by [GetNumberEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getnumberevents).

### `NextIndex` [out]

Receives the index of the next event. If *NextIndex* is **NULL**, this information is not returned.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

If the specified event is the same as the current event, this method does nothing. Otherwise, this method sets the execution status of the target to DEBUG_STATUS_GO (and notifies the event callbacks). When [WaitForEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-waitforevent) is called, the engine will generate the specified event for the event callbacks and set it as the current event.

This method is only useful if the target offers a list of events.

## See also

[GetCurrentEventIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getcurrenteventindex)

[GetNumberEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getnumberevents)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)