# IDebugControl2::GetCurrentTimeDate

## Description

The **GetCurrentTimeDate** method returns the time of the current target.

## Parameters

### `TimeDate` [out]

Receives the time and date. This is the number of seconds since the beginning of 1970, or **0** if the current time could not be determined.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The value of the variable *TimeDate* is either the desired information or is **0**. |

## Remarks

For live debugging sessions, this will be the current time as reported by the target's computer. For static debugging sessions, such as crash dump files, this will be the time the crash dump file was created.

For more information, see [Target Information](https://learn.microsoft.com/windows-hardware/drivers/debugger/target-information).

## See also

[GetCurrentSystemUpTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getcurrentsystemuptime)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)