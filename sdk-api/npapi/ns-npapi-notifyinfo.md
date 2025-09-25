# NOTIFYINFO structure

## Description

The **NOTIFYINFO** structure contains status information about a network connect or disconnect operation. It is used by the
[AddConnectNotify](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-addconnectnotify) and
[CancelConnectNotify](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-cancelconnectnotify) functions.

## Members

### `dwNotifyStatus`

This will be either NOTIFY_PRE or NOTIFY_POST to indicate whether this notification is sent before or after the connection or disconnection is performed.

### `dwOperationStatus`

This is set to WN_SUCCESS when **dwNotifyStatus** is NOTIFY_PRE.

If **dwNotifyStatus** is set to NOTIFY_POST, **dwOperationStatus** contains the return status code from the function performing the operation:
[NPAddConnection](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npaddconnection) or
[NPCancelConnection](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npcancelconnection).

### `lpContext`

Used by the application receiving the notification in order to keep a context for the operation between the pre-notification and the post-notification calls. In other words, it enables the notification application to match the advance notification call to the corresponding after-the-fact notification call for a particular event. The **lpContext** member is a **NULL** pointer when the notification function is called for advance notification. The notification function can return with **lpContext** still **NULL**, indicating that it is not interested in further notification for this specific operation. In this case, the notification function will not be called again with after-the-fact notification for this operation. If the advance notification function call returns a non-**NULL** value in **lpContext**, this value is passed in when the notification function is called for the after-the-fact notification for that same operation.