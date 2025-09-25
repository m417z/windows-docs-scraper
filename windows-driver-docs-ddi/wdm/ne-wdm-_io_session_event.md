# _IO_SESSION_EVENT enumeration

## Description

The **IO_SESSION_EVENT** enumeration indicates the type of session event for which a driver is receiving notification.

## Constants

### `IoSessionEventIgnore`

### `IoSessionEventCreated`

The user session was created.

### `IoSessionEventTerminated`

The user session terminated.

### `IoSessionEventConnected`

The user session was connected.

### `IoSessionEventDisconnected`

The user session was disconnected.

### `IoSessionEventLogon`

The user logged on to the session.

### `IoSessionEventLogoff`

The user logged off of the session.

### `IoSessionEventMax`

Specifies the maximum value in this enumeration type.

## Remarks

When the I/O manager calls the driver's [IO_SESSION_NOTIFICATION_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_session_notification_function) function, it sets the *Event* parameter of this function to an **IO_SESSION_EVENT** enumeration constant (other than **IoSessionEventMax**).

A session event causes a transition from one session state to another. For more information about session state transitions, see [IO_SESSION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_session_state).

## See also

[IO_SESSION_NOTIFICATION_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_session_notification_function)

[IO_SESSION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_session_state)