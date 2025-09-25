# ITAgent::CreateSession

## Description

The
**CreateSession** method creates a new agent session for the input ACD group and address.

## Parameters

### `pACDGroup` [in]

Pointer to
[ITACDGroup](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itacdgroup) interface.

### `pAddress` [in]

Pointer to
[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress) object available for receiving ACD calls.

### `ppAgentSession` [out]

Pointer to
[ITAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentsession) interface for object created.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppAgentSession* parameter is not a valid pointer. |
| **E_UNEXPECTED** | Failed to open a line for the target Address. |
| **E_INVALIDARG** | The *pACDGroup* or *pAddress* argument is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## Remarks

TAPI calls the **AddRef** method on the
[ITAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentsession) interface returned by **ITAgent::CreateSession**. The application must call **Release** on the
**ITAgentSession** interface to free resources associated with it.

Some telephone environments require a personal identification number to open a session. See
[CreateSessionWithPIN](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagent-createsessionwithpin).

## See also

[IEnumAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumagentsession)

[ITACDGroup](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itacdgroup)

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)

[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent)

[ITAgent::CreateSessionWithPIN](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagent-createsessionwithpin)

[ITAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentsession)