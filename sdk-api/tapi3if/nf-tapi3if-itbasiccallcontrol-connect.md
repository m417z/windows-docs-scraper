# ITBasicCallControl::Connect

## Description

The
**Connect** method attempts to complete the connection of an outgoing call.

## Parameters

### `fSync` [in]

Boolean indicating whether connection is to be performed synchronously (VARIANT_TRUE) or asynchronously (VARIANT_FALSE).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **TAPI_E_INVALCALLSTATE** | [Call state](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_state) must be CS_IDLE. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

If the call is asynchronous, the application will receive information about the call's progress through the
[ITCallNotificationEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallnotificationevent) outgoing interface. The application must register the outgoing interface before calling
**Connect**.
**Connect** may return S_OK, but the actual connection may fail (and the application will be notified through the outgoing interface).

If the call is synchronous, this method will not return until the call is in the connected state or fails.

## See also

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[Complete a Session](https://learn.microsoft.com/windows/desktop/Tapi/complete-a-session-ovr)

[ITAddress::CreateCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-createcall)

[ITBasicCallControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasiccallcontrol)