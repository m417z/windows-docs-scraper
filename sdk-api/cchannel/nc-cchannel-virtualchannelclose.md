# VIRTUALCHANNELCLOSE callback function

## Description

Closes the client end of a virtual channel.

Remote Desktop Services provides a pointer to a
**VirtualChannelClose** function in the
[CHANNEL_ENTRY_POINTS](https://learn.microsoft.com/windows/desktop/api/cchannel/ns-cchannel-channel_entry_points) structure passed to your
[VirtualChannelEntry](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelentry) entry point.

## Parameters

### `openHandle` [in]

Handle to the virtual channel. This is the handle returned in the *pOpenHandle* parameter of the
[VirtualChannelOpen](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelopen) function.

## Return value

If the function succeeds, the return value is CHANNEL_RC_OK.

If an error occurs, the function returns one of the following values.

## See also

[VirtualChannelOpen](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelopen)