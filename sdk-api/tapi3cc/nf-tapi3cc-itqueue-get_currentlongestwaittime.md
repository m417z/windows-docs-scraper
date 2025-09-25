# ITQueue::get_CurrentLongestWaitTime

## Description

The
**get_CurrentLongestWaitTime** method gets the longest time a current call (still in the queue) has been waiting (in seconds) during the current measurement period. The measurement period is switch or implementation specific. (See
[get_MeasurementPeriod](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itqueue-get_measurementperiod).).

## Parameters

### `plWaitTime` [out]

Pointer to wait time.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plWaitTime* is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## See also

[ITQueue](https://learn.microsoft.com/windows/desktop/api/tapi3cc/nn-tapi3cc-itqueue)