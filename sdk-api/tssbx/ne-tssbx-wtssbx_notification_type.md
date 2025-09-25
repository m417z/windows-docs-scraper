# WTSSBX_NOTIFICATION_TYPE enumeration

## Description

Contains values that indicate the type of status change that occurred on a Remote Desktop Session Host (RD Session Host) server or a user session. Remote Desktop Connection Broker (RD Connection Broker) uses this enumeration type in the [WTSSBX_MachineChangeNotification](https://learn.microsoft.com/windows/desktop/api/tssbx/nf-tssbx-iwtssbplugin-wtssbx_machinechangenotification) and [WTSSBX_SessionChangeNotification](https://learn.microsoft.com/windows/desktop/api/tssbx/nf-tssbx-iwtssbplugin-wtssbx_sessionchangenotification) methods to notify the plug-in about changes that have occurred.

## Constants

### `WTSSBX_NOTIFICATION_REMOVED:0x1`

RD Connection Broker received a Removed notification. This indicates that a user has logged off an RD Session Host server or that an RD Session Host server left a farm in RD Connection Broker.

### `WTSSBX_NOTIFICATION_CHANGED:0x2`

RD Connection Broker received a Changed notification. This indicates that the session state of the RD Session Host server changed or that an RD Session Host server setting, such as the IP address or the maximum session limit, changed.

### `WTSSBX_NOTIFICATION_ADDED:0x4`

RD Connection Broker received an Added notification. This indicates that a user logged into an RD Session Host server or that an RD Session Host server joined a farm in RD Connection Broker.

### `WTSSBX_NOTIFICATION_RESYNC:0x8`

RD Connection Broker received a Resync notification. This indicates that an RD Session Host server joined a farm in RD Connection Broker and the new RD Session Host server is now synchronizing its session information with the RD Connection Broker server.

## See also

[IWTSSBPlugin](https://learn.microsoft.com/windows/desktop/api/tssbx/nn-tssbx-iwtssbplugin)