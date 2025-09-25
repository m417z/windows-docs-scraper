# ITAgent::get_ID

## Description

The
**get_ID** method gets an agent's ID.

## Parameters

### `ppID` [out]

Pointer to **BSTR** containing agent ID.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **TAPI_E_CALLCENTER_NO_AGENT_ID** | ITAgent was not created using [ITAgentHandler::CreateAgentWithID](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagenthandler-createagentwithid), but with [ITAgentHandler::CreateAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagenthandler-createagent). No ID exists. |
| **E_POINTER** | The *ppID* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

This method is provided for interfacing with legacy switch solutions.

The application must free the memory allocated for the *ppID* parameter through
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) when the variable is no longer needed.

## See also

[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent)