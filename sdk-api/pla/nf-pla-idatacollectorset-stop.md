# IDataCollectorSet::Stop

## Description

Manually stops the data collector set.

## Parameters

### `Synchronous` [in]

Data collection runs in a separate process. This value determines when the method returns.

Set to VARIANT_TRUE to have the method return after the data collector set is stopped or fails to stop. The return value indicates whether the set successfully stopped or failed to stop.

Set to VARIANT_FALSE to return after the method sends a request to the set to stop. The return value indicates whether the request was successfully sent to the set. An event is written to the event log if the set fails to stop.

## Return value

Returns S_OK if successful. The following table shows a possible error value.

| Return code/value | Description |
| --- | --- |
| **PLA_E_DCS_NOT_RUNNING**<br><br>0x80300104 | The data collector set is not running. |

## Remarks

This method saves the data already collected when the set is stopped.

Note that if the *Synchronous* parameter is VARIANT_TRUE, the method will not return until data management and tasks that run after collection are complete.

## See also

[IDataCollectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorset)

[IDataCollectorSet::Schedules](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_schedules)

[IDataCollectorSet::Start](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-start)