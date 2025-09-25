# VIRTUALCHANNELENTRY callback function

## Description

An application-defined entry point for the client-side DLL of an application that uses Remote Desktop Services virtual channels. Remote Desktop Services calls this entry point to pass a set of function pointers to the client DLL. The client calls these functions to work with virtual channels. Your
**VirtualChannelEntry** implementation must call the
[VirtualChannelInit](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelinit) function to initialize access to virtual channels.

## Parameters

### `pEntryPoints` [in]

Pointer to a
[CHANNEL_ENTRY_POINTS](https://learn.microsoft.com/windows/desktop/api/cchannel/ns-cchannel-channel_entry_points) structure that contains pointers to the client-side virtual channel functions.

This pointer is no longer valid after the
**VirtualChannelEntry** function returns. You must make a copy of this structure in extension-allocated memory for later use.

## Return value

Return **TRUE** if the function is successful.

Return **FALSE** if an error occurs. In this case, Remote Desktop Services unloads your DLL.

## See also

[CHANNEL_ENTRY_POINTS](https://learn.microsoft.com/windows/desktop/api/cchannel/ns-cchannel-channel_entry_points)

[VirtualChannelInit](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelinit)