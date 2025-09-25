# ITAgentHandler::CreateAgentWithID

## Description

The
**CreateAgentWithID** method creates an Agent object based on an agent identifier. This identifier is a string identifying the agent on a legacy ACD system. If the system also requires a PIN or password for logging into groups, you use this method to set the PIN or password.

## Parameters

### `pID` [in]

Pointer to **BSTR** containing the agent identifier.

### `pPIN` [in]

Pointer to **BSTR** containing the agent PIN.

### `ppAgent` [out]

Pointer to
[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *pPIN* parameter is **NULL**. |
| **E_POINTER** | The *ppAgent* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## Remarks

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for the *pID* and *pPIN* parameters, and use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variables are no longer needed.

TAPI calls the **AddRef** method on the
[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent) interface returned by **ITAgentHandler::CreateAgentWithID**. The application must call **Release** on the
**ITAgent** interface to free resources associated with it.

## See also

[CreateAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagenthandler-createagent)

[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent)

[ITAgentHandler](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagenthandler)