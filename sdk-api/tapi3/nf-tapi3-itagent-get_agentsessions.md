# ITAgent::get_AgentSessions

## Description

The
**get_AgentSessions** method creates a collection of current agent sessions. This method is provided for Automation client applications, such as those written in Visual Basic. C and C++ applications must use the
[EnumerateAgentSessions](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagent-enumerateagentsessions) method.

## Parameters

### `pVariant` [out]

Pointer to **VARIANT** containing an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of
[ITAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentsession) interface pointers (agent session objects).

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pVariant* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

TAPI calls the **AddRef** method on the
[ITAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentsession) interface returned by **ITAgent::get_AgentSessions**. The application must call **Release** on the
**ITAgentSession** interface to free resources associated with it.

## See also

[EnumerateAgentSessions](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagent-enumerateagentsessions)

[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent)

**ITAgentSession**

[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection)