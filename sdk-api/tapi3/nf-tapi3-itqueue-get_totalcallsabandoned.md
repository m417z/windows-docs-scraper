# ITQueue::get_TotalCallsAbandoned

## Description

The
**get_TotalCallsAbandoned** method gets the number of abandoned calls during the current measurement period. The measurement period is switch or implementation specific. (See
[get_MeasurementPeriod](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itqueue-get_measurementperiod).)

## Parameters

### `plCalls` [out]

Pointer to the number of calls abandoned.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plCalls* is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## See also

[ITQueue](https://learn.microsoft.com/windows/desktop/api/tapi3cc/nn-tapi3cc-itqueue)