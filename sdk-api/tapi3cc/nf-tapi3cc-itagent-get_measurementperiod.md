# ITAgent::get_MeasurementPeriod

## Description

The
**get_MeasurementPeriod** method gets the measurement period (in seconds) for which the switch and/or implementation stores and calculates information. For example,
[get_NumberOfACDCalls](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagent-get_numberofacdcalls) returns the number of calls the agent handled;
**get_MeasurementPeriod** indicates if this value referenced the calls handled in the last hour, day, month, etc.

## Parameters

### `plPeriod` [out]

Measurement period.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plPeriod* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## See also

[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent)

[put_MeasurementPeriod](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagent-put_measurementperiod)