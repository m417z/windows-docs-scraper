# IDebugControl3::GetCurrentSystemUpTime

## Description

The **GetCurrentSystemUpTime** method returns the number of seconds the current target's computer has been running since it was last started.

## Parameters

### `UpTime` [out]

Receives the number of seconds the computer has been running, or **0** if the engine is unable to determine the running time.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The value of the variable *UpTime* is either the desired information or is **0**. |

## Remarks

For more information, see [Target Information](https://learn.microsoft.com/windows-hardware/drivers/debugger/target-information).

## See also

[GetCurrentTimeDate](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getcurrenttimedate)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)