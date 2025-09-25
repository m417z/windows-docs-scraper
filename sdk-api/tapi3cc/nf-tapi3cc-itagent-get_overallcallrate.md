# ITAgent::get_OverallCallRate

## Description

The
**get_OverallCallRate** method gets an agent's call rate across all sessions. 10 *Calls per agent hour (where agent hour represents the time that an agent was active in one or more agent sessions).

The measurement period over which this information is calculated is switch- and/or implementation-specific. (See
[get_MeasurementPeriod](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagent-get_measurementperiod).)

## Parameters

### `pcyCallrate` [out]

Call rate.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pcyCallrate* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## Remarks

The **CURRENCY** type is used here instead of **FLOAT** for Visual Basic and Java compatibility.

## See also

[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent)