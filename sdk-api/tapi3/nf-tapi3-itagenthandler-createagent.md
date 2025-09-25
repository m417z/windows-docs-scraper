# ITAgentHandler::CreateAgent

## Description

The
**CreateAgent** method creates an Agent object.

## Parameters

### `ppAgent` [out]

Pointer to the
[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppAgent* parameter is not a valid pointer. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## Remarks

TAPI calls the **AddRef** method on the
[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent) interface returned by **ITAgentHandler::CreateAgent**. The application must call **Release** on the
**ITAgent** interface to free resources associated with it.

## See also

[CreateAgentWithID](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagenthandler-createagentwithid)

[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent)

[ITAgentHandler](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagenthandler)