# ITAgentSession::get_ACDGroup

## Description

The
**get_ACDGroup** method gets the ACD group associated with this session.

## Parameters

### `ppACDGroup` [out]

Pointer to
[ITACDGroup](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itacdgroup) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppACDGroup* parameter is not a valid pointer. |
| **LINEERR_** | See [lineGetAgentSessionInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentsessioninfo) for error codes returned from this TAPI 2.1 function. |

## Remarks

This method wraps the TAPI 2.1
[lineGetAgentSessionInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentsessioninfo) function.

TAPI calls the **AddRef** method on the
[ITACDGroup](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itacdgroup) interface returned by **ITAgentSession::get_ACDGroup**. The application must call **Release** on the
**ITACDGroup** interface to free resources associated with it.

## See also

[ITAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentsession)

[lineGetAgentSessionInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentsessioninfo)