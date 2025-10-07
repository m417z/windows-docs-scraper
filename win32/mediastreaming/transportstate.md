# TransportState enumeration

\[The feature associated with this page, [Windows Media Streaming API](https://learn.microsoft.com/windows/win32/mediastreaming/media-streaming-api-portal), is a legacy feature. It has been superseded by [Media Casting](https://learn.microsoft.com/windows/uwp/audio-video-camera/media-casting). **Media Casting** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Media Casting** instead of **Windows Media Streaming API**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Defines the available transport states as defined by the UPnP Guidelines.

## Constants

**Unknown**

Erroneous device state.

**Stopped**

The device s transport is in a stopped state.

**Playing**

The device s transport is in a playing state.

**Transitioning**

The device s transport is in a transitioning state which will result in another state value.

**Paused**

The device s transport is in a paused state.

**Recording**

The device s transport is in a recording state.

**NoMediaPresent**

The device s transport does not have an URI set for playback.

**Last**

The device s previous state to the current transport state.

## Requirements

| Requirement | Value |
|----------------|------------------------------------------------------------------------------------------------------------------------------------------------|
| IDL<br> | Windows.Media.Streaming.idl (reference Windows.Media.Streaming.idl) |

