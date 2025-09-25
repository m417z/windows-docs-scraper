# REAL_TIME_NOTIFICATION_SETTING_INPUT structure

## Description

The **REAL_TIME_NOTIFICATION_SETTING_INPUT** structure provides input settings to apply for the **REAL_TIME_NOTIFICATION_CAPABILITY** transport setting for a TCP socket that is used with [ControlChannelTrigger](https://learn.microsoft.com/uwp/api/windows.networking.sockets.controlchanneltrigger) to receive background network notifications in a Windows Store app.

## Members

### `TransportSettingId`

The transport setting ID.

### `BrokerEventGuid`

The realtime notification broker event GUID for this transport ID.

## Remarks

The **REAL_TIME_NOTIFICATION_SETTING_INPUT** structure is supported on Windows 8, and Windows Server 2012, and later versions of the operating system.

 If the [TRANSPORT_SETTING_ID](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-transport_setting_id) in the *lpvInBuffer* parameter passed to the [SIO_APPLY_TRANSPORT_SETTING](https://learn.microsoft.com/windows/win32/winsock/sio-apply-transport-setting)
IOCTL has the **Guid** member set to **REAL_TIME_NOTIFICATION_CAPABILITY**, then this is a request to query the real time notification settings for the TCP socket used with [ControlChannelTrigger](https://learn.microsoft.com/uwp/api/windows.networking.sockets.controlchanneltrigger) to receive background network notifications in a Windows Store app. The *lpvInBuffer* parameter should point to a **REAL_TIME_NOTIFICATION_SETTING_INPUT** structure used as input to the **SIO_APPLY_TRANSPORT_SETTING**
IOCTL to apply the transport setting.

## See also

[ControlChannelTrigger](https://learn.microsoft.com/uwp/api/windows.networking.sockets.controlchanneltrigger)

[REAL_TIME_NOTIFICATION_SETTING_OUTPUT](https://learn.microsoft.com/windows/win32/api/mstcpip/ns-mstcpip-real_time_notification_setting_output)

[SIO_APPLY_TRANSPORT_SETTING](https://learn.microsoft.com/windows/win32/winsock/sio-apply-transport-setting)

[SIO_QUERY_TRANSPORT_SETTING](https://learn.microsoft.com/windows/win32/winsock/sio-query-transport-setting)

[TRANSPORT_SETTING_ID](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-transport_setting_id)