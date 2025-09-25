# CONTROL_CHANNEL_TRIGGER_STATUS enumeration

## Description

The [CONTROL_CHANNEL_TRIGGER_STATUS](https://learn.microsoft.com/windows/desktop/api/mswsock/ne-mswsock-rio_notification_completion_type) enumeration specifies the status from a query for the **REAL_TIME_NOTIFICATION_CAPABILITY** transport setting for a TCP socket that is used with [ControlChannelTrigger](https://learn.microsoft.com/uwp/api/windows.networking.sockets.controlchanneltrigger) to receive background network notifications in a Windows Store app.

## Constants

### `CONTROL_CHANNEL_TRIGGER_STATUS_INVALID:0`

Status is invalid.

### `CONTROL_CHANNEL_TRIGGER_STATUS_SOFTWARE_SLOT_ALLOCATED:1`

A software slot was allocated for the [ControlChannelTrigger](https://learn.microsoft.com/uwp/api/windows.networking.sockets.controlchanneltrigger).

### `CONTROL_CHANNEL_TRIGGER_STATUS_HARDWARE_SLOT_ALLOCATED:2`

A hardware slot was allocated for the [ControlChannelTrigger](https://learn.microsoft.com/uwp/api/windows.networking.sockets.controlchanneltrigger).

### `CONTROL_CHANNEL_TRIGGER_STATUS_POLICY_ERROR:3`

A status policy error.

### `CONTROL_CHANNEL_TRIGGER_STATUS_SYSTEM_ERROR:4`

A status system error.

### `CONTROL_CHANNEL_TRIGGER_STATUS_TRANSPORT_DISCONNECTED:5`

The TCP transport is disconnected.

### `CONTROL_CHANNEL_TRIGGER_STATUS_SERVICE_UNAVAILABLE:6`

Service is unavailable.

## Remarks

The [CONTROL_CHANNEL_TRIGGER_STATUS](https://learn.microsoft.com/windows/desktop/api/mswsock/ne-mswsock-rio_notification_completion_type) structure is supported on Windows 8, and Windows Server 2012, and later versions of the operating system.

A [CONTROL_CHANNEL_TRIGGER_STATUS](https://learn.microsoft.com/windows/desktop/api/mswsock/ne-mswsock-rio_notification_completion_type) enumeration value is returned as output from the [SIO_QUERY_TRANSPORT_SETTING](https://learn.microsoft.com/windows/win32/winsock/sio-query-transport-setting)
IOCTL to a query the **REAL_TIME_NOTIFICATION_CAPABILITY** transport setting for a TCP socket that is used with [ControlChannelTrigger](https://learn.microsoft.com/uwp/api/windows.networking.sockets.controlchanneltrigger) to receive background network notifications in a Windows Store app.

## See also

[ControlChannelTrigger](https://learn.microsoft.com/uwp/api/windows.networking.sockets.controlchanneltrigger)

[REAL_TIME_NOTIFICATION_SETTING_OUTPUT](https://learn.microsoft.com/windows/win32/api/mstcpip/ns-mstcpip-real_time_notification_setting_output)

[SIO_APPLY_TRANSPORT_SETTING](https://learn.microsoft.com/windows/win32/winsock/sio-apply-transport-setting)

[SIO_QUERY_TRANSPORT_SETTING](https://learn.microsoft.com/windows/win32/winsock/sio-query-transport-setting)