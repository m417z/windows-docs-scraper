# IDebugControl3::GetNumberEvents

## Description

The **GetNumberEvents** method returns the number of [events](https://learn.microsoft.com/windows-hardware/drivers/debugger/events) for the current target, if the number of events is fixed.

## Parameters

### `Events` [out]

Receives the number of events stored in the target. If the target offers multiple events, *Events* will be set to the number of events available. Otherwise, *Events* will be set to one.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful, and *Events* contains the total number of events possible for the target. |
| **S_FALSE** | The method was successful, but *Events* contains only the total number of events possible at the current time. Targets that support variable execution might have different sets of events available at different points during the target's execution. |

## Remarks

Crash dump files contain a static list of events; each event represents a snapshot of the target at a particular point in time. If the current target is a crash dump file, this method sets *Events* to the number of stored events and returns S_OK.

Live targets generate events dynamically and do not necessarily have a known set of events. If the current target is a live target with unconstrained number of events, this method sets *Events* to the number of events currently available and returns S_FALSE.

For more information, see the topic [Event Information](https://learn.microsoft.com/windows-hardware/drivers/debugger/event-information).

## See also

[GetCurrentEventIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getcurrenteventindex)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[SetNextEventIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setnexteventindex)