# CHANNEL_ENTRY_POINTS structure

## Description

Contains pointers to the functions called by a client-side DLL to access virtual channels.Remote Desktop Services calls your
[VirtualChannelEntry](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelentry) function to pass this structure.

## Members

### `cbSize`

Size, in bytes, of this structure.

### `protocolVersion`

Protocol version. Remote Desktop Services sets this member to **VIRTUAL_CHANNEL_VERSION_WIN2000**.

### `pVirtualChannelInit`

Pointer to a
[VirtualChannelInit](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelinit) function.

### `pVirtualChannelOpen`

Pointer to a
[VirtualChannelOpen](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelopen) function.

### `pVirtualChannelClose`

Pointer to a
[VirtualChannelClose](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelclose) function.

### `pVirtualChannelWrite`

Pointer to a
[VirtualChannelWrite](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelwrite) function.

## See also

[VirtualChannelClose](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelclose)

[VirtualChannelEntry](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelentry)

[VirtualChannelInit](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelinit)

[VirtualChannelOpen](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelopen)

[VirtualChannelWrite](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelwrite)