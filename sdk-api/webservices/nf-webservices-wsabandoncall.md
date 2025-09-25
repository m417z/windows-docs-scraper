# WsAbandonCall function

## Description

Abandons a specified call on the specified [service proxy](https://learn.microsoft.com/windows/desktop/wsw/service-proxy).

## Parameters

### `serviceProxy` [in]

Pointer to a [WS_SERVICE_PROXY](https://learn.microsoft.com/windows/desktop/wsw/ws-service-proxy) structure representing the service proxy on which to abandon the call.

### `callId` [in]

ID of the call to abandon.
(See the Remarks section.)

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_OPERATION** | The current state of the service proxy is not valid for this operation. |
| **E_INVALIDARG** | A **NULL** service proxy was passed to the function. |

## Remarks

Calls are identified by a call ID. This call ID is associated with the call by the WS_CALL_PROPERTY_CALL_ID value of the [WS_CALL_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_call_property_id) enumeration.

If the call ID is 0, all pending calls on the service proxy are abandoned.
For more information,
see the following topics:

* [Client Side Service Operations](https://learn.microsoft.com/windows/desktop/wsw/client-side-service-operations)
* [CallAbandonExample](https://learn.microsoft.com/windows/desktop/wsw/callabandonexample)

Be aware that the actual I/O associated with the call is not canceled. The service proxy keeps the resources to complete the call even though the call was abandoned.

This results in a consumption of resources that is aggravated if an application continues to abandon calls, as can happen when the server is slow to respond to the
client, and the client application abandons one call only to make the same call again.