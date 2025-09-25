# TRANSPORT_SETTING_ID structure

## Description

The **TRANSPORT_SETTING_ID** structure specifies the transport setting ID used by the [SIO_APPLY_TRANSPORT_SETTING](https://learn.microsoft.com/windows/win32/winsock/sio-apply-transport-setting) and [SIO_QUERY_TRANSPORT_SETTING](https://learn.microsoft.com/windows/win32/winsock/sio-query-transport-setting) IOCTLs to apply or query the transport setting for a socket.

## Members

### `Guid`

The transport setting ID.

## Remarks

The only transport setting defined for Windows 8 and Windows Server 2012 is for the **REAL_TIME_NOTIFICATION_CAPABILITY** capability on a TCP socket. For Windows 10 and Windows Server 2016, there is another transport setting defined as **ASSOCIATE_NAMERES_CONTEXT**.

The **TRANSPORT_SETTING_ID** structure is passed as input to the [SIO_APPLY_TRANSPORT_SETTING](https://learn.microsoft.com/windows/win32/winsock/sio-apply-transport-setting) and [SIO_QUERY_TRANSPORT_SETTING](https://learn.microsoft.com/windows/win32/winsock/sio-query-transport-setting)
IOCTLs. The **Guid** member determines what transport setting is applied or queried.

The only transport setting currently defines is for the **REAL_TIME_NOTIFICATION_CAPABILITY** capability on a TCP socket.

## See also

[ControlChannelTrigger](https://learn.microsoft.com/uwp/api/windows.networking.sockets.controlchanneltrigger)

[REAL_TIME_NOTIFICATION_SETTING_OUTPUT](https://learn.microsoft.com/windows/win32/api/mstcpip/ns-mstcpip-real_time_notification_setting_output)

[SIO_APPLY_TRANSPORT_SETTING](https://learn.microsoft.com/windows/win32/winsock/sio-apply-transport-setting)

[SIO_QUERY_TRANSPORT_SETTING](https://learn.microsoft.com/windows/win32/winsock/sio-query-transport-setting)