# IWTSSBPlugin::WTSSBX_SessionChangeNotification

## Description

[The [IWTSSBPlugin](https://learn.microsoft.com/windows/desktop/api/tssbx/nn-tssbx-iwtssbplugin) interface is
not supported after Windows Server 2008 R2. Starting with Windows Server 2012 please use the
[ITsSbPlugin](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbplugin) interface.]

Notifies the plug-in that a change, such as a logon, logoff, disconnect, or reconnect, occurred in the session.

## Parameters

### `NotificationType` [in]

A [WTSSBX_NOTIFICATION_TYPE](https://learn.microsoft.com/windows/win32/api/tssbx/ne-tssbx-wtssbx_notification_type) type that specifies the type of change that occurred.

### `MachineId` [in]

The ID of the server on which the session change occurred.

### `NumOfSessions` [in]

The number of elements in the *SessionInfo* array.

### `SessionInfo` [in]

An array of [WTSSBX_SESSION_INFO](https://learn.microsoft.com/windows/win32/api/tssbx/ns-tssbx-wtssbx_session_info) structures that contain information about sessions. Only the members that have changed are reported in this structure. The others are set to zero.

## Return value

Returns **S_OK** if successful.

## Remarks

The **WTSSBX_SessionChangeNotification** method can report up to 25 sessions each time it is called. If Terminal Services Session Broker (TS Session Broker) needs to report more than 25 sessions, it calls this method multiple times until it reports all of its sessions.

Your implementation of this method must return **S_OK** immediately if successful.

## See also

[ITsSbPlugin](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbplugin)

[IWTSSBPlugin](https://learn.microsoft.com/windows/desktop/api/tssbx/nn-tssbx-iwtssbplugin)