# VIRTUALCHANNELOPEN callback function

## Description

Opens the client end of a virtual channel.

Remote Desktop Services provides a pointer to a
**VirtualChannelOpen** function in the
[CHANNEL_ENTRY_POINTS](https://learn.microsoft.com/windows/desktop/api/cchannel/ns-cchannel-channel_entry_points) structure passed to your
[VirtualChannelEntry](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelentry) entry point.

## Parameters

### `pInitHandle` [in]

Handle to the client connection. This is the handle returned in the *ppInitHandle* parameter of the
[VirtualChannelInit](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelinit) function.

### `pOpenHandle` [out]

Pointer to a variable that receives a handle that identifies the open virtual channel in subsequent calls to the
[VirtualChannelWrite](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelwrite) and
[VirtualChannelClose](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelclose) functions.

### `pChannelName` [in]

Pointer to a null-terminated ANSI character string containing the name of the virtual channel to open. The name must have been registered when the client called the
**VirtualChannelInit** function.

### `pChannelOpenEventProc` [in]

Pointer to an application-defined
[VirtualChannelOpenEvent](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-channel_open_event_fn) function that Remote Desktop Services calls to notify the client DLL of events for this virtual channel.

## Return value

If the function succeeds, the return value is CHANNEL_RC_OK.

If an error occurs, the function returns one of the following values.

## Remarks

The client DLL cannot call this function until the client has established a connection with an RD Session Host
server. Your [VirtualChannelInitEvent](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-channel_init_event_fn)
function receives a CHANNEL_EVENT_CONNECTED notification when an RD Session Host server connection is established.

## See also

[VirtualChannelClose](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelclose)

[VirtualChannelInit](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelinit)

[VirtualChannelInitEvent](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-channel_init_event_fn)

[VirtualChannelOpenEvent](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-channel_open_event_fn)

[VirtualChannelWrite](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelwrite)