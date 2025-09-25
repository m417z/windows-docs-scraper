# CHANNEL_INIT_EVENT_FN callback function

## Description

An application-defined callback
function that Remote Desktop Services calls to notify the client DLL of virtual channel events.

The **PCHANNEL_INIT_EVENT_FN** type defines a pointer to this callback function.
**VirtualChannelInitEvent** is a placeholder for the application-defined or
library-defined function name.

## Parameters

### `pInitHandle` [in]

Handle to the client connection. This is the handle returned in the *ppInitHandle* parameter of the
[VirtualChannelInit](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelinit) function.

### `event` [in]

Indicates the event that caused the notification. This parameter can be one of the following values.

#### CHANNEL_EVENT_INITIALIZED (0)

The Remote Desktop Connection (RDC) client initialization has been completed. The *pData* parameter is **NULL**.

#### CHANNEL_EVENT_CONNECTED (1)

A connection has been established with an RD Session Host server that supports virtual channels. The
*pData* parameter is a pointer to a **null**-terminated string with the name of the server.

#### CHANNEL_EVENT_V1_CONNECTED (2)

A connection has been established with an RD Session Host server that does not support virtual channels. The
*pData* parameter is **NULL**.

#### CHANNEL_EVENT_DISCONNECTED (3)

The connection to the RD Session Host server has been disconnected. The *pData* parameter is **NULL**.

#### CHANNEL_EVENT_TERMINATED (4)

The client has been terminated. The *pData* parameter is **NULL**.

#### CHANNEL_EVENT_REMOTE_CONTROL_START (5)

A remote control operation has been started. The *pData* parameter is **NULL**.

#### CHANNEL_EVENT_REMOTE_CONTROL_STOP (6)

A remote control operation has been terminated. The *pData* parameter is a pointer to a
**null**-terminated string containing the name of the server.

### `pData` [in]

Pointer to additional data for the event. The type of data depends on the event, as described previously
in the event descriptions.

### `dataLength` [in]

Specifies the size, in bytes, of the data in the *pData* buffer.

## Return value

This function does not return a value.

## Remarks

The client DLL uses the
[VirtualChannelInit](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelinit) function to
register its **VirtualChannelInitEvent** function with Remote Desktop Services.

This function is reentrant on a per-handle basis. The function may be called while it is executing, but not
on the same handle more than once.

This function is called only after
[VirtualChannelEntry](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelentry) has completed.

**CHANNEL_EVENT_CONNECTED** and **CHANNEL_EVENT_DISCONNECTED** event notifications will not be sent if the
connection is transferred to another session. However, the server-side plug-in that is administering the session
to which the connection is transferred will receive a reconnection notification. A server-side tool such as
Tscon.exe can be used to transfer connections. Refer to
[Monitoring Session
Connections and Disconnections](https://learn.microsoft.com/windows/desktop/TermServ/monitoring-session-connections-and-disconnections) for more information on reconnection notifications.

If the user-mode plug-in must be notified that it has been reconnected (for example, if it must reset its
state), the server-side plug-in should send a notification message to the client. This notification should
use the protocol that the plug-ins use to communicate with each other.

## See also

[VirtualChannelInit](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelinit)