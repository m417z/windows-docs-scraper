# _IO_SESSION_STATE enumeration

## Description

The **IO_SESSION_STATE** enumeration contains constants that indicate the current state of a user session.

## Constants

### `IoSessionStateCreated`

The session has been created.

### `IoSessionStateInitialized`

The session has been initialized but has not yet been created.

### `IoSessionStateConnected`

The session is connected but the user has not yet logged on.

### `IoSessionStateDisconnected`

The session has been disconnected.

### `IoSessionStateDisconnectedLoggedOn`

The session was disconnected while the user was logged on.

### `IoSessionStateLoggedOn`

The user is logged on to the session.

### `IoSessionStateLoggedOff`

The user has logged off of the session.

### `IoSessionStateTerminated`

The session has been terminated.

### `IoSessionStateMax`

Specifies the maximum value in this enumeration type.

## Remarks

When a driver calls the [IoGetContainerInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetcontainerinformation) routine to obtain information about a user session (*InformationClass* = **IoSessionStateInformation**), the I/O manager writes an [IO_SESSION_STATE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_session_state_information) structure to the buffer pointed to by the routine's *Buffer* parameter. The I/O manager sets the **SessionState** member of this structure to an **IO_SESSION_STATE** enumeration constant (other than **IoSessionStateMax**).

The following table shows the session state transitions. For each state transition, the table shows the following:

* The *from* state (a column label in a gray box)
* The *to* state (a row label in a gray box)
* The event that causes the transition (a table entry in a white box)

A blank white box indicates that no transition can occur directly from the associated *from* state to the corresponding *to* state.

![Table listing session state transitions ](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/images/sessionstate.png)
In the preceding table, the *from* and *to* states are represented by **IO_SESSION_STATE** enumeration constants, and the events are represented by [IO_SESSION_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_session_event) enumeration constants. For example, if the session state is **IoSessionStateConnected** (abbreviated as "Connected" in the table), an **IoSessionEventLogon** event (abbreviated as "Logon") causes a transition to the **IoSessionStateLoggedOn** state (abbreviated as "LoggedOn"). The starting state for a new session is **IoSessionStateInitialized** (abbreviated as "Initialized").

## See also

[IO_SESSION_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_session_event)

[IO_SESSION_STATE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_session_state_information)

[IoGetContainerInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetcontainerinformation)