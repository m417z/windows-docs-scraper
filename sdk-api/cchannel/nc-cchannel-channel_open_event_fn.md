# CHANNEL_OPEN_EVENT_FN callback function

## Description

An application-defined callback function that Remote Desktop Services calls to notify the client DLL of
events for a specific virtual channel.

The **PCHANNEL_OPEN_EVENT_FN** type defines a pointer to this callback function.
**VirtualChannelOpenEvent** is a
placeholder for the application-defined or library-defined function name.

## Parameters

### `openHandle` [in]

Handle to the virtual channel. This is the handle returned in the *pOpenHandle*
parameter of the [VirtualChannelOpen](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelopen)
function.

### `event` [in]

Indicates the event that caused the notification. This parameter can be one of the following values.

#### CHANNEL_EVENT_DATA_RECEIVED

The virtual channel received data from the server end. *pData* is a pointer to a
chunk of the data. *dataLength* indicates the size of this chunk.
*totalLength* indicates the total size of the data written by the server.

#### CHANNEL_EVENT_WRITE_CANCELLED

A write operation started by a
[VirtualChannelWrite](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelwrite) call has been
canceled. *pData* is the value specified in the *pUserData*
parameter of **VirtualChannelWrite**.

A write operation is canceled when the client session is disconnected. This notification enables you to
free any memory associated with the write operation.

#### CHANNEL_EVENT_WRITE_COMPLETE

A write operation started by a
[VirtualChannelWrite](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelwrite) call has
been completed. *pData* is the value specified in the
*pUserData* parameter of
**VirtualChannelWrite**.

### `pData` [in]

Pointer to additional data for the event. The type of data depends on the event, as described previously in
the event descriptions.

If *event* is **CHANNEL_EVENT_DATA_RECEIVED**, the data written
by the server is broken into chunks of not more than **CHANNEL_CHUNK_LENGTH** bytes. The
*dataFlags* parameter indicates whether the current chunk is at the beginning, middle,
or end of the block of data written by the server.

Note that the size of this parameter can be greater
than the value specified by the *dataLength* parameter. The application should read
only the number of bytes specified by *dataLength*.

### `dataLength` [in]

Specifies the size, in bytes, of the data in the *pData* buffer.

### `totalLength` [in]

Specifies the total size, in bytes, of the data written by a single write operation to the server end of
the virtual channel.

### `dataFlags` [in]

Provides information about the chunk of data being received in a
**CHANNEL_EVENT_DATA_RECEIVED** event. The following bit flags will be set.

Note that you should not make direct comparisons using the '==' operator when comparing the values in the
following list; instead, use the comparison methods described.

#### CHANNEL_FLAG_FIRST

The chunk is the beginning of the data written by a single write operation.

Use bitwise comparisons when comparing this flag.

#### CHANNEL_FLAG_LAST

The chunk is the end of the data written by a single write operation.

Use bitwise comparisons when comparing this flag.

#### CHANNEL_FLAG_MIDDLE

This is the default. The chunk is in the middle of a block of data written by a single write operation.

Do not use bitwise comparisons to compare this flag value directly. Instead, use bitwise comparisons to
determine that the flag value is not **CHANNEL_FLAG_FIRST** or
**CHANNEL_FLAG_LAST**. This is done by using the following comparison:
`Result = !(flags & CHANNEL_FLAG_FIRST) && !(flags & CHANNEL_FLAG_LAST)`.

#### CHANNEL_FLAG_ONLY

Combines the **CHANNEL_FLAG_FIRST** and **CHANNEL_FLAG_LAST**
values. The chunk contains all the data from a single write operation.

Use bitwise comparisons when comparing this flag.

## Return value

This function has no return values.

## Remarks

The client DLL uses the
[VirtualChannelOpen](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelopen) function to
register a **VirtualChannelOpenEvent**
function for a specific virtual channel.

You can use the same
**VirtualChannelOpenEvent** function for
multiple calls to [VirtualChannelOpen](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelopen).

This function can be called with a different event type while it is executing. For example, it might be called
with **CHANNEL_EVENT_WRITE_COMPLETE** or
**CHANNEL_EVENT_WRITE_CANCELLED** while it is processing the
**CHANNEL_EVENT_DATA_RECEIVED** event. Note that this function will not be called with the
same event type that it is currently processing.

## See also

[VirtualChannelOpen](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelopen)