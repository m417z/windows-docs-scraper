# IAMTimecodeReader::GetTimecode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetTimecode` method retrieves the most recent timecode, userbit, and flag values available in the stream.

## Parameters

### `pTimecodeSample` [out]

Pointer to a [TIMECODE_SAMPLE](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-timecode_sample) structure.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

## Remarks

Use this method to monitor the timecode and to parse duplicates and discontinuities.

The timecode contains undefined bits, called *userbits*. Applications can use these bits to store synchronization information or other custom information.

### DV and MPEG Camcorder Implementation

The [MSDV](https://learn.microsoft.com/windows/desktop/DirectShow/msdv-driver) driver supports reading SMPTE timecode or absolute track numbers (ATN). The [MSTape](https://learn.microsoft.com/windows/desktop/DirectShow/mstape-driver) driver supports reading the relative time counter (RTC). To read time information on these devices, do the following:

Set the **dwFlags** member of the [TIMECODE_SAMPLE](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-timecode_sample) structure to one of the following values.

| Constant | Description |
| --- | --- |
| ED_DEVCAP_TIMECODE_READ | Timecode (DV) |
| ED_DEVCAP_ATN_READ | Absolute track number (DV) |
| ED_DEVCAP_RTC_READ | Relative time counter (MPEG tape) |

The **timecode** member of the [TIMECODE_SAMPLE](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-timecode_sample) structure is a [TIMECODE](https://learn.microsoft.com/windows/desktop/DirectShow/getting-timecode-from-the-device) structure. Initialize that structure's **dwFrames** member to zero.

All other structure members are ignored.

When the method returns, the **dwFrames** member contains the time information, in the following format.

| Time Information | Format |
| --- | --- |
| Timecode | Hours, minutes, seconds, and frames, as a binary coded decimal (BCD) value: *0xhhmmssff*. |
| ATN | Track number. |
| RTC | Hours, minutes, seconds, and frames, as a BCD value: *0xhhmmssff*. The most significant bit of the frames byte is a sign bit. If the frame count is not available, the remaining frame bits are set to 0x7F. |

Also, the **dwUser** member receives the *blank flag* bit from the device, which has one of the following values.

| Value | Description |
| --- | --- |
| 0x00 | Not a discontinuity. |
| 0x01 | Discontinuity. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[Getting Timecode from the Device](https://learn.microsoft.com/windows/desktop/DirectShow/getting-timecode-from-the-device)

[IAMTimecodeReader Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtimecodereader)