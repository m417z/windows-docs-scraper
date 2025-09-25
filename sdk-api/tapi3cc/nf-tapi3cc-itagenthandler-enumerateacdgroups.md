# ITAgentHandler::EnumerateACDGroups

## Description

The
**EnumerateACDGroups** method enumerates ACD groups currently associated with the agent handler. This method is provided for C and C++ applications. Automation client applications, such as those written in Visual Basic, must use the
[get_ACDGroups](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagenthandler-get_acdgroups) method. The number of groups returned is based upon replies from the ACD proxy application. Each proxy application will return a list of groups according to its own internal privilege/security decisions.

## Parameters

### `ppEnumACDGroup` [out]

Pointer to
[IEnumACDGroup](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumacdgroup) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppEnumACDGroup* parameter is not a valid pointer. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## Remarks

TAPI calls the **AddRef** method on the
[IEnumACDGroup](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumacdgroup) interface returned by **ITAgentHandler::EnumerateACDGroups**. The application must call **Release** on the
**IEnumACDGroup** interface to free resources associated with it.

## See also

[IEnumACDGroup](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumacdgroup)

[ITAgentHandler](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagenthandler)