# REAL_TIME_NOTIFICATION_SETTING_OUTPUT structure

## Description

The [REAL_TIME_NOTIFICATION_SETTING_OUTPUT](https://learn.microsoft.com/windows/win32/api/mstcpip/ns-mstcpip-real_time_notification_setting_output) structure provides the output settings from a query for the **REAL_TIME_NOTIFICATION_CAPABILITY** transport setting for a TCP socket that is used with [ControlChannelTrigger](https://learn.microsoft.com/uwp/api/windows.networking.sockets.controlchanneltrigger) to receive background network notifications in a Windows Store app.

## Members

### `ChannelStatus`

The channel status for a socket that is used with the [ControlChannelTrigger](https://learn.microsoft.com/uwp/api/windows.networking.sockets.controlchanneltrigger).

## Remarks

The [REAL_TIME_NOTIFICATION_SETTING_OUTPUT](https://learn.microsoft.com/windows/win32/api/mstcpip/ns-mstcpip-real_time_notification_setting_output) structure is supported on Windows 8, and Windows Server 2012, and later versions of the operating system.

 If the [TRANSPORT_SETTING_ID](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-transport_setting_id) in the *lpvInBuffer* parameter passed to the [SIO_QUERY_TRANSPORT_SETTING](https://learn.microsoft.com/windows/win32/winsock/sio-query-transport-setting)
IOCTL has the **Guid** member set to **REAL_TIME_NOTIFICATION_CAPABILITY**, then this is a request to query the real time notification settings for the TCP socket used with [ControlChannelTrigger](https://learn.microsoft.com/windows/win32/api/mstcpip/ns-mstcpip-real_time_notification_setting_output) to receive background network notifications in a Windows Store app. If the [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) or [LPWSPIoctl](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff566296(v=vs.85)) call is successful, this IOCTL returns a [REAL_TIME_NOTIFICATION_SETTING_OUTPUT](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-real_time_notification_setting_input) structure with the current status.

## See also

[CONTROL_CHANNEL_TRIGGER_STATUS](https://learn.microsoft.com/windows/desktop/api/mswsock/ne-mswsock-rio_notification_completion_type)

[ControlChannelTrigger](https://learn.microsoft.com/uwp/api/windows.networking.sockets.controlchanneltrigger)

[REAL_TIME_NOTIFICATION_SETTING_INPUT](https://learn.microsoft.com/windows/win32/api/mstcpip/ns-mstcpip-real_time_notification_setting_input)

[SIO_APPLY_TRANSPORT_SETTING](https://learn.microsoft.com/windows/win32/winsock/sio-apply-transport-setting)

[SIO_QUERY_TRANSPORT_SETTING](https://learn.microsoft.com/windows/win32/winsock/sio-query-transport-setting)