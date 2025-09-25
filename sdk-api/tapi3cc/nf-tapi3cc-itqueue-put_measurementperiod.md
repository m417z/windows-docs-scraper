# ITQueue::put_MeasurementPeriod

## Description

The
**put_MeasurementPeriod** method sets the period (in seconds) for which the switch and/or implementation stores and calculates information.

## Parameters

### `lPeriod` [in]

Measurement period (in seconds).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | Value of *lPeriod* is zero. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |
| **LINEERR_** | See [lineSetQueueMeasurementPeriod](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetqueuemeasurementperiod) for error codes returned from this TAPI 2.1 function. |

## Remarks

The **ITQueue::put_MeasurementPeriod** method is a COM wrapper for the TAPI 2.1
[lineSetQueueMeasurementPeriod](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetqueuemeasurementperiod) function.

This method will accept negative values for the measurement period, but this will normally result in unreliable statistics.

## See also

[ITQueue](https://learn.microsoft.com/windows/desktop/api/tapi3cc/nn-tapi3cc-itqueue)

[get_MeasurementPeriod](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itqueue-get_measurementperiod)