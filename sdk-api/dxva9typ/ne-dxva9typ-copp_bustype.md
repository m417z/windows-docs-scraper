# COPP_BusType enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the type of I/O bus used by the graphics adapter.

## Constants

### `COPP_BusType_Unknown:0`

Unknown bus type.

### `COPP_BusType_PCI:1`

PCI bus.

### `COPP_BusType_PCIX:2`

PCI-X bus.

### `COPP_BusType_PCIExpress:3`

PCI Express bus.

### `COPP_BusType_AGP:4`

AGP bus.

### `COPP_BusType_Integrated:0x80000000`

Integrated bus. This flag can be combined with the other flags. This flag indicates that the command and status signals between the graphics adapter and other subsystems on the computer are not available on an expansion bus that has a public specification and standard connector type, unless it is a memory bus.

### `COPP_BusType_ForceDWORD`

Reserved.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[Using Certified Output Protection Protocol (COPP)](https://learn.microsoft.com/windows/desktop/DirectShow/using-certified-output-protection-protocol--copp)