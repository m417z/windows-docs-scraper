# DeviceTypes enumeration

\[The feature associated with this page, [Windows Media Streaming API](https://learn.microsoft.com/windows/win32/mediastreaming/media-streaming-api-portal), is a legacy feature. It has been superseded by [Media Casting](https://learn.microsoft.com/windows/uwp/audio-video-camera/media-casting). **Media Casting** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Media Casting** instead of **Windows Media Streaming API**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Describes the DLNA device types that are supported by the Media Streaming API.

## Constants

**Unknown**

Unknown device type.

**DigitalMediaRenderer**

DLNA Digital Media Renderer (DMR). The value is equivalent to the device type **urn:schemas-upnp-org:device:MediaRenderer:1**.

**DigitalMediaServer**

DLNA Digital Media Server (DMS). The value is equivalent to the device type **urn:schemas-upnp-org:device:MediaServer:1**.

**DigitalMediaPlayer**

DLNA Digital Media Player

## Requirements

| Requirement | Value |
|----------------|------------------------------------------------------------------------------------------------------------------------------------------------|
| IDL<br> | Windows.Media.Streaming.idl (reference Windows.Media.Streaming.idl) |

