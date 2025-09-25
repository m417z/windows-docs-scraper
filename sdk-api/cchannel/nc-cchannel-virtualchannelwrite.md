# VIRTUALCHANNELWRITE callback function

## Description

Sends data from the client end of a virtual channel to a partner application on the server end.

Remote Desktop Services provides a pointer to a
**VirtualChannelWrite** function in the
[CHANNEL_ENTRY_POINTS](https://learn.microsoft.com/windows/desktop/api/cchannel/ns-cchannel-channel_entry_points) structure passed to your
[VirtualChannelEntry](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelentry) entry point.

## Parameters

### `openHandle` [in]

Handle to the virtual channel. This is the handle returned in the *pOpenHandle* parameter of the
[VirtualChannelOpen](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelopen) function.

### `pData` [in]

Pointer to a buffer containing the data to write.

### `dataLength` [in]

Specifies the number of bytes of the data in the *pData* buffer to write.

### `pUserData` [in]

An application-defined value. This value is passed to your
[VirtualChannelOpenEvent](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-channel_open_event_fn) function when the write operation is completed or canceled.

## Return value

If the function succeeds, the return value is CHANNEL_RC_OK.

If an error occurs, the function returns one of the following values.

## Remarks

The
**VirtualChannelWrite** function is asynchronous. When the write operation has been completed, your
[VirtualChannelOpenEvent](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-channel_open_event_fn) function receives a CHANNEL_EVENT_WRITE_COMPLETE notification. Until that notification is received, the caller must not free or reuse the *pData* buffer passed to
**VirtualChannelWrite**.

The value specified for the *pUserData* parameter is passed to your
**VirtualChannelOpenEvent** function when the write operation is completed or canceled. You can use this data to identify the write operation.

The server add-in at the server end of the virtual channel calls the
[WTSVirtualChannelRead](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelread) function to read the data written by a
**VirtualChannelWrite** call.

## See also

[VirtualChannelOpen](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelopen)

[VirtualChannelOpenEvent](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-channel_open_event_fn)

[WTSVirtualChannelRead](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelread)