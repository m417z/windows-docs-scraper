# ITAgentHandler::get_ACDGroups

## Description

The
**get_ACDGroups** method creates a collection of ACD groups currently associated with the agent handler. This method is provided for Automation client applications, such as those written in Visual Basic. C and C++ applications must use the
[EnumerateACDGroups](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagenthandler-enumerateacdgroups) method.

## Parameters

### `pVariant` [out]

Pointer to **VARIANT** containing an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of
[ITACDGroup](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itacdgroup) interface pointers (ACD group objects).

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pVariant* parameter is not a valid pointer. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## Remarks

TAPI calls the **AddRef** method on the
[ITACDGroup](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itacdgroup) interface returned by **ITAgentHandler::get_ACDGroups**. The application must call **Release** on the
**ITACDGroup** interface to free resources associated with it.

## See also

[EnumerateACDGroups](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagenthandler-enumerateacdgroups)

[ITACDGroup](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itacdgroup)

[ITAgentHandler](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagenthandler)

[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection)