# ITTAPICallCenter::get_AgentHandlers

## Description

The
**get_AgentHandlers** method creates a collection of agent handlers that are currently associated with the call center. Provided for Automation client applications, such as those written in Visual Basic. C and C++ applications must use the
[EnumerateAgentHandlers](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-ittapicallcenter-enumerateagenthandlers) method.

## Parameters

### `pVariant` [out]

Pointer to a **VARIANT** containing an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of
[ITAgentHandler](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagenthandler) interface pointers.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *pVariant* parameter is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pVariant* parameter is not a valid pointer. |

## Remarks

TAPI calls the **AddRef** method on the
[ITAgentHandler](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagenthandler) interface returned by **ITTAPICallCenter::get_AgentHandlers**. The application must call **Release** on the
**ITAgentHandler** interface to free resources associated with it.

## See also

[IEnumAgentHandler](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumagenthandler)

[ITAgentHandler](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagenthandler)

[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection)

[ITTAPICallCenter](https://learn.microsoft.com/windows/desktop/api/tapi3cc/nn-tapi3cc-ittapicallcenter)

[TAPI Object](https://learn.microsoft.com/windows/desktop/Tapi/tapi-object)