# ITAgent::get_NumberOfIncomingCalls

## Description

The
**get_NumberOfIncomingCalls** method gets the number of incoming non-ACD calls handled by this agent.

The measurement period over which this information is calculated is switch- and/or implementation-specific. (See
[get_MeasurementPeriod](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagent-get_measurementperiod).)

## Parameters

### `plCalls` [out]

Total number of incoming calls.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plCalls* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## See also

[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent)