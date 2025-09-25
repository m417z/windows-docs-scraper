# _IO_SESSION_CONNECT_INFO structure

## Description

The **IO_SESSION_CONNECT_INFO** structure provides information about a user session.

## Members

### `SessionId`

Session ID. This member contains the [Terminal Services](https://learn.microsoft.com/windows/win32/termserv/terminal-services-portal) session identifier of the user session for which the driver is receiving this notification.

### `LocalSession`

Indicates whether the user session is a local session or a remote session. If **TRUE**, the user is logged on locally. If **FALSE**, the user is logged on remotely.

## Remarks

If a driver is registered to receive notifications of events in a user session, and if this session enters the *connected* state, the I/O manager calls the driver's [IO_SESSION_NOTIFICATION_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_session_notification_function) function. For this call, the I/O manager sets the function's *Event* parameter to **IoSessionEventConnected**. Additionally, the I/O manager sets the function's *NotificationPayload* parameter to point to an **IO_SESSION_CONNECT_INFO** structure that contains information about the user session. For more information about **IoSessionEventConnected**, see [IO_SESSION_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_session_event).

## See also

[IO_SESSION_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_session_event)

[IO_SESSION_NOTIFICATION_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_session_notification_function)