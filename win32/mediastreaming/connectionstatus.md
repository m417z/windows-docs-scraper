# ConnectionStatus enumeration

\[The feature associated with this page, [Windows Media Streaming API](https://learn.microsoft.com/windows/win32/mediastreaming/media-streaming-api-portal), is a legacy feature. It has been superseded by [Media Casting](https://learn.microsoft.com/windows/uwp/audio-video-camera/media-casting). **Media Casting** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Media Casting** instead of **Windows Media Streaming API**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Represents the state of the device in the network as last seen.

## Constants

**Online**

Device is online and active on the network.

**Offline**

Device is offline.

**Sleeping**

Device is currently offline but might automatically wake up when an attempt is made to communicate with it.

## Requirements

| Requirement | Value |
|----------------|------------------------------------------------------------------------------------------------------------------------------------------------|
| IDL<br> | Windows.Media.Streaming.idl (reference Windows.Media.Streaming.idl) |

