# DVD_ERROR enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DVD_ERROR** enumeration value defines DVD error conditions.

The [EC_DVD_ERROR](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-error) event contains a flag from this enumeration in the *lParam1* event parameter. The value of the flag determines the meaning of the *lParam2* parameter, as described here for each flag. If not listed, *lParam2* is zero.

## Constants

### `DVD_ERROR_Unexpected:1`

Something unexpected happened; perhaps content is authored incorrectly. Playback is stopped.

### `DVD_ERROR_CopyProtectFail:2`

Key exchange for DVD copy protection failed. Playback is stopped.

### `DVD_ERROR_InvalidDVD1_0Disc:3`

DVD-Video disc is authored incorrectly for specification version 1.*x*. Playback is stopped.

### `DVD_ERROR_InvalidDiscRegion:4`

The disc cannot be played because it is not authored to play in the system region. You can try fixing the region mismatch by changing the system region with Dvdrgn.exe.

*lParam2*: The low **WORD** contains the disc region and the high **WORD** contains the system region.

### `DVD_ERROR_LowParentalLevel:5`

Player parental level is lower than the lowest parental level available in the DVD content. Playback is stopped.

*lParam2*: The lowest parental level in the DVD content, or -1 if no parental level is specified in the content.

### `DVD_ERROR_MacrovisionFail:6`

Analog copy protection distribution failed. Playback stopped.

### `DVD_ERROR_IncompatibleSystemAndDecoderRegions:7`

No discs can be played because the system region does not match the decoder region.

*lParam2*: The low **WORD** contains the system region and the high **WORD** contains the decoder region.

### `DVD_ERROR_IncompatibleDiscAndDecoderRegions:8`

The disc cannot be played because the disc is not authored to be played in the decoder's region.

*lParam2*: The low **WORD** contains the disc region and the high **WORD** contains the decoder region.

### `DVD_ERROR_CopyProtectOutputFail:9`

The disc cannot be played because the video display does not meet the copy protection requirements.

### `DVD_ERROR_CopyProtectOutputNotSupported:10`

The disc cannot be played because the driver does not support checking the video display.

## Remarks

For the flags where *lParam2* contains two region codes, the regions are encoded as a set of bits, one bit per region, in reverse order. If a disc is allowed in a region, that bit is turned off. For example, for a Region 2 disc, the value is 11111101, with the second least significant bit turned off. A multi-region disc will have more than one bit turned off.

## See also

[DVD Region Change Support in Windows](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-region-change-support-in-windows)

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[EC_DVD_ERROR](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-error)