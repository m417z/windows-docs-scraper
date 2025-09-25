# ITAgentSession::get_SessionStartTime

## Description

The
**get_SessionStartTime** method gets the time that the session was created.

## Parameters

### `pdateSessionStart` [out]

Pointer to session start time.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pdateSessionStart* parameter is not a valid pointer. |
| **LINEERR_** | See [lineGetAgentSessionInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentsessioninfo) for error codes returned from this TAPI 2.1 function. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## Remarks

This method wraps the TAPI 2.1
[lineGetAgentSessionInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentsessioninfo) function.

## See also

[ITAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentsession)

[lineGetAgentSessionInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentsessioninfo)