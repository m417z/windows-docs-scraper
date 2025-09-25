# AMCOPPStatusInput structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The AMCOPPStatusInput structure contains a Certified Output Protection Protocol (COPP) status request.

## Members

### `rApp`

128-bit random number.

### `guidStatusRequestID`

GUID that defines the status request.

### `dwSequence`

Sequence number. The application must keep a running count of the COPP status requests issued. For each request, increment the sequence number by one.

### `cbSizeData`

Number of bytes of valid data in the **StatusData** member.

### `StatusData`

Data for the status request. The meaning of the data depends on the request.

## Remarks

The following COPP status requests are defined.

| **GUID** | Description |
| --- | --- |
| **DXVA_COPPQueryConnectorType** | Returns the type of physical connector to the output device. |
| **DXVA_COPPQueryProtectionType** | Returns the available protection mechanisms for the physical connector. |
| **DXVA_COPPQueryLocalProtectionLevel** | Returns the protection level that is currently set through the COPP mechanism in the context of this session. |
| **DXVA_COPPQueryGlobalProtectionLevel** | Returns the actual protection level that is currently set for the physical connector. |
| **DXVA_COPPQueryDisplayData** | Returns information describing the signal that is being transmitted over the connector associated with the COPP device. |
| **DXVA_COPPQueryHDCPKeyData** | Returns the High-bandwidth Digital Content Protection (HDCP) characteristics of the output device. |
| **DXVA_COPPQueryBusData** | Returns information about the type of bus used by the graphics hardware associated with this COPP device. |

For more information, see the Windows DDK documentation.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[Using Certified Output Protection Protocol (COPP)](https://learn.microsoft.com/windows/desktop/DirectShow/using-certified-output-protection-protocol--copp)