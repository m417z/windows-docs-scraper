# ITTAPICallCenter::EnumerateAgentHandlers

## Description

The
**EnumerateAgentHandlers** method enumerates agent handlers that are currently associated with the call center. Provided for C and C++ applications. Automation client applications, such as those written in Visual Basic, must use the
[get_AgentHandlers](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-ittapicallcenter-get_agenthandlers) method.

## Parameters

### `ppEnumHandler` [out]

Pointer to
[IEnumAgentHandler](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumagenthandler) enumerator.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppEnumHandler* parameter is not a valid pointer. |
| **E_INVALIDARG** | The TAPI object has not been initialized. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

TAPI calls the **AddRef** method on the
[IEnumAgentHandler](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumagenthandler) interface returned by **tapi3.ittapicallcenter_enumerateagenthandlers**. The application must call **Release** on the
**IEnumAgentHandler** interface to free resources associated with it.

## See also

[IEnumAgentHandler](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumagenthandler)

[ITTAPICallCenter](https://learn.microsoft.com/windows/desktop/api/tapi3cc/nn-tapi3cc-ittapicallcenter)

[TAPI Object](https://learn.microsoft.com/windows/desktop/Tapi/tapi-object)