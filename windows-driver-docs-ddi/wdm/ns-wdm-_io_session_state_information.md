# _IO_SESSION_STATE_INFORMATION structure

## Description

The **IO_SESSION_STATE_INFORMATION** structure contains information about the state of a user session.

## Members

### `SessionId`

 The session ID. This member contains the [Terminal Services](https://learn.microsoft.com/windows/win32/termserv/terminal-services-portal) session identifier of a user session. The [IoGetContainerInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetcontainerinformation) routine sets this member to the session ID of the session that is represented by the session object that the *ContainerObject* parameter of **IoGetContainerInformation** points to.

### `SessionState`

The current state of the user session that is identified by *SessionId*. This member is set to one of the following [IO_SESSION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_session_state) enumeration constants:

* **IoSessionStateCreated**
* **IoSessionStateInitialized**
* **IoSessionStateConnected**
* **IoSessionStateDisconnected**
* **IoSessionStateDisconnectedLoggedOn**
* **IoSessionStateLoggedOn**
* **IoSessionStateLoggedOff**
* **IoSessionStateTerminated**

### `LocalSession`

Indicates whether the user session identified by *SessionId* is a local session. If **TRUE**, the user is logged on locally. If **FALSE**, the user is logged on remotely. This member is valid only if the session is connected. The following **IO_SESSION_STATE** enumeration constants represent session states in which the session is connected:

* **IoSessionStateConnected**
* **IoSessionStateLoggedOn**
* **IoSessionStateLoggedOff**

## Remarks

To obtain information about a user session, a driver calls the **IoGetContainerInformation** routine. This routine's *Buffer* parameter points to an **IO_SESSION_STATE_INFORMATION** structure that contains information about the session state.

## See also

[IO_SESSION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_session_state)

[IoGetContainerInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetcontainerinformation)