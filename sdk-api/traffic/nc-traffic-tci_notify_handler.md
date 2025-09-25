# TCI_NOTIFY_HANDLER callback function

## Description

The
*ClNotifyHandler* function is used by traffic control to notify the client of various traffic control–specific events, including the deletion of flows, changes in filter parameters, or the closing of an interface.

The
*ClNotifyHandler* callback function should be exposed by all clients using traffic control services.

## Parameters

### `ClRegCtx` [in]

Client registration context, provided to traffic control by the client with the client's call to the
[TcRegisterClient](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcregisterclient) function.

### `ClIfcCtx` [in]

Client interface context, provided to traffic control by the client with the client's call to the
[TcOpenInterface](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcopeninterfacea) function. Note that during a TC_NOTIFY_IFC_UP event, *ClIfcCtx* is not available and will be set to **NULL**.

### `Event` [in]

Describes the notification event. See the Remarks section for a list of notification events.

### `SubCode` [in]

Handle used to further qualify a notification event. See Note below for 64-bit for Windows programming issues.

### `BufSize` [in]

Size of the buffer included with the notification event, in bytes.

### `Buffer` [in]

Buffer containing the detailed event information associated with *Event* and *SubCode*.

## Remarks

Notification events may require the traffic control client to take particular action or respond appropriately, for example, removing filters or enumerating flows for affected interfaces.

The following table describes the various notification events.

| Event | SubCode | Buffer contents | Remarks |
| --- | --- | --- | --- |
| TC_NOTIFY_IFC_UP | None | Interface name of the new interface | A new traffic control interface is coming up, and the list of addresses is indicated. |
| TC_NOTIFY_IFC_CLOSE | Reason for close | Interface name of the closed interface | Indicates an interface that was opened by the client is being closed by the system. Note that the interface and its supported flows and filters are closed by the system upon return from the notification handler. The client does not need to close the interface, delete flows, or delete filters. |
| TC_NOTIFY_IFC_CHANGE | None | New parameter value | Used to notify clients that have registered for interface change notification through the *NotifyChange* parameter of the [TcQueryInterface](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcqueryinterface) function. |
| TC_NOTIFY_PARAM_CHANGED | Pointer to the GUID for a traffic control parameter queried using the [TcQueryInterface](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcqueryinterface) function. | New parameter value | This event is notified as a result of a change in a parameter previously queried with the *NotifyChange* flag set. |
| TC_NOTIFY_FLOW_CLOSE | *ClFlowCtx* |  | Indicates system closure of a client-created flow. The system deletes all associated filters. |

**Note** Use of the
*ClNotifyHandler* function requires administrative privilege.

## See also

[TcOpenInterface](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcopeninterfacea)

[TcQueryInterface](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcqueryinterface)

[TcRegisterClient](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcregisterclient)