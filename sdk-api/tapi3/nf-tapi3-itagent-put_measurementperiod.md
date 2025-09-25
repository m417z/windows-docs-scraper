# ITAgent::put_MeasurementPeriod

## Description

The
**put_MeasurementPeriod** method sets the period (in seconds) for which the switch and/or implementation stores and calculates information. This also resets any cumulative counts to zero.

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
| **LINEERR_** | See [lineSetAgentMeasurementPeriod](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetagentmeasurementperiod) for error codes returned from this TAPI 2.1 function. |

## Remarks

The **ITAgent::put_MeasurementPeriod** method is a COM wrapper for the TAPI 2.1
[lineSetAgentMeasurementPeriod](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetagentmeasurementperiod) function.

This method will accept negative values for the measurement period, but this will normally result in unreliable statistics.

## See also

[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent)

[get_MeasurementPeriod](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagent-get_measurementperiod)