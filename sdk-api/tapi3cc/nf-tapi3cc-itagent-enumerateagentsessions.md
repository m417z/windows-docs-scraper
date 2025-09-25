# ITAgent::EnumerateAgentSessions

## Description

The
**EnumerateAgentSessions** method enumerates the current agent sessions. This method is provided for C and C++ applications. Automation client applications, such as those written in Visual Basic, must use the
[get_AgentSessions](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagent-get_agentsessions) method.

## Parameters

### `ppEnumAgentSession` [out]

Pointer to an
[IEnumAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumagentsession) agent session enumerator.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The **ppEnumAgentSession** parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

TAPI calls the **AddRef** method on the
[IEnumAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumagentsession) interface returned by **ITAgent::EnumerateAgentSessions**. The application must call **Release** on the
**IEnumAgentSession** interface to free resources associated with it.

## See also

[IEnumAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumagentsession)

[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent)

[ITAgent::CreateSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagent-createsession)

[ITAgent::CreateSessionWithPIN](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagent-createsessionwithpin)

[ITAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentsession)

[get_AgentSessions](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagent-get_agentsessions)