# ITAgent::CreateSessionWithPIN

## Description

The
**CreateSessionWithPIN** method creates a new agent session for the input ACD group and address, with Personal Identification Number (PIN).

## Parameters

### `pACDGroup` [in]

Pointer to
[ITACDGroup](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itacdgroup) interface.

### `pAddress` [in]

Pointer to
[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress) interface for object available for receiving ACD calls.

### `pPIN` [in]

Pointer to a **BSTR** representation of agent's PIN.

### `ppAgentSession` [out]

Pointer to session created.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **TAPI_E_CALLCENTER_NO_AGENT_ID** | Agent not created by [CreateAgentWithID](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagenthandler-createagentwithid). |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |
| **E_INVALIDARG** | *pPIN* is **NULL**. |
| **E_POINTER** | The *pPIN* or *ppAgentSession* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for *pPIN* and use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variable is no longer needed.

TAPI calls the **AddRef** method on the
[ITAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentsession) interface returned by **ITAgent::CreateSessionWithPIN**. The application must call **Release** on the
**ITAgentSession** interface to free resources associated with it.

## See also

[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent)

[ITAgent::CreateSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagent-createsession)

[ITAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentsession)