# TransportStatus enumeration

\[The feature associated with this page, [Windows Media Streaming API](https://learn.microsoft.com/windows/win32/mediastreaming/media-streaming-api-portal), is a legacy feature. It has been superseded by [Media Casting](https://learn.microsoft.com/windows/uwp/audio-video-camera/media-casting). **Media Casting** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Media Casting** instead of **Windows Media Streaming API**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Defines the available transport status as defined by the UPnP Guidelines.

## Constants

**Unknown**

Erroneous device status.

**Ok**

The device is in a good status.

**ErrorOccurred**

An error occurred on the device.

**Last**

The device s previous status to the current transport status.

## Requirements

| Requirement | Value |
|----------------|------------------------------------------------------------------------------------------------------------------------------------------------|
| IDL<br> | Windows.Media.Streaming.idl (reference Windows.Media.Streaming.idl) |

