# ITAgent::get_TotalWrapUpTime

## Description

The
**get_TotalWrapUpTime** method gets the number of seconds spent on ACD call wrap-up (after-call work) by this agent (across all sessions).

The measurement period over which this information is calculated is switch and/or implementation-specific. (See
[get_MeasurementPeriod](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagent-get_measurementperiod).)

## Parameters

### `plWrapUpTime` [out]

Total wrap-up time.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plWrapUpTime* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## See also

[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent)