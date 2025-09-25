# VIRTUALCHANNELINIT callback function

## Description

Initializes a client DLL's access to Remote Desktop Services virtual channels. The client calls **VirtualChannelInit** to register the
names of its virtual channels.

Remote Desktop Services provides a pointer to a **VirtualChannelInit** function in the
[CHANNEL_ENTRY_POINTS](https://learn.microsoft.com/windows/desktop/api/cchannel/ns-cchannel-channel_entry_points) structure passed to
your [VirtualChannelEntry](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelentry) entry point.

## Parameters

### `ppInitHandle` [in]

Pointer to a variable that receives a handle that identifies the client connection. Use this handle to
identify the client in subsequent calls to the
[VirtualChannelOpen](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelopen) function.

### `pChannel` [in, out]

Pointer to an array of [CHANNEL_DEF](https://learn.microsoft.com/previous-versions/windows/embedded/aa513856(v=msdn.10))
structures. Each structure contains the name and initialization options of a virtual channel that the client
DLL will open. Note that the **VirtualChannelInit** call does not open these
virtual channels; it only reserves the names for use by this application.

### `channelCount` [in]

Specifies the number of entries in the *pChannel* array.

### `versionRequested` [in]

Specifies the level of virtual channel support. Set this parameter to **VIRTUAL_CHANNEL_VERSION_WIN2000**.

### `pChannelInitEventProc` [in]

Pointer to an application-defined
[VirtualChannelInitEvent](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-channel_init_event_fn) function that
Remote Desktop Services calls to notify the client DLL of virtual channel events.

## Return value

If the function succeeds, the return value is **CHANNEL_RC_OK**.

If an error occurs, the function returns one of the following values.

## Remarks

You can call the **VirtualChannelInit** function only from your
[VirtualChannelEntry](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelentry) function.
Calls to **VirtualChannelInit** at any other time fail.

When **VirtualChannelInit** returns successfully, Remote Desktop Services has
registered the requested channels. However, Remote Desktop Services may not have completed other initialization. When
all initialization is complete, Remote Desktop Services calls your
[VirtualChannelInitEvent](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-channel_init_event_fn)
callback function with the **CHANNEL_EVENT_INITIALIZED** event.

You should not make assumptions about the number of available virtual channels before calling this function,
because the system and other plug-ins may have reserved virtual channels. Therefore, you should always check for a
**CHANNEL_RC_TOO_MANY_CHANNELS** return code after calling this function.

When **VirtualChannelInit** returns, the **options** member of each
[CHANNEL_DEF](https://learn.microsoft.com/previous-versions/windows/embedded/aa513856(v=msdn.10)) structure includes
**CHANNEL_OPTION_INITIALIZED** if the channel was successfully initialized.

The maximum number of channels per client session is **CHANNEL_MAX_COUNT**.

## See also

[CHANNEL_DEF](https://learn.microsoft.com/previous-versions/windows/embedded/aa513856(v=msdn.10))

[VirtualChannelEntry](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelentry)

[VirtualChannelInitEvent](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-channel_init_event_fn)