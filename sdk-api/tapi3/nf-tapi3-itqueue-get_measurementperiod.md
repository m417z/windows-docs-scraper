# ITQueue::get_MeasurementPeriod

## Description

The
**get_MeasurementPeriod** method gets the measurement period (in seconds) for which the switch and/or implementation stores and calculates information. For example, the
[get_TotalCallsQueued](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itqueue-get_totalcallsqueued) method returns the number of calls queued;
**get_MeasurementPeriod** indicates if this value referenced the calls queued in an hour, a day, a month, etc.

## Parameters

### `plPeriod` [out]

Pointer to the measurement period.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plPeriod* is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## See also

[ITQueue](https://learn.microsoft.com/windows/desktop/api/tapi3cc/nn-tapi3cc-itqueue)

[put_MeasurementPeriod](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itqueue-put_measurementperiod)