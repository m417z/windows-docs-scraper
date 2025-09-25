## Description

The **KS_VBI_FRAME_INFO** structure extends the [**KSSTREAM_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksstream_header) structure for vertical blanking interval (VBI) streams.

## Members

### `ExtendedHeaderSize`

Specifies the size of this structure.

### `dwFrameFlags`

Specifies flags indicating additional information about the frame captured. During capture, the minidriver sets this member to one of the following values that are defined in *ksmedia.h*:

| Flag | Meaning |
|---|---|
| KS_VBI_FLAG_FIELD1 | Indicates the first field of a two-field sequence |
| KS_VBI_FLAG_FIELD2 | Indicates the second field of a two-field sequence |
| KS_VBI_FLAG_MV_PRESENT | Indicates Macrovision protection scheme |
| KS_VBI_FLAG_MV_HARDWARE | Indicates Macrovision hardware support |
| KS_VBI_FLAG_MV_DETECTED | Indicates Macrovision detected |
| KS_VBI_FLAG_TVTUNER_CHANGE | Indicates that the **TvTunerChangeInfo** member structure contains valid data |
| KS_VBI_FLAG_VBIINFOHEADER_CHANGE | Indicates that the **VBIInfoHeader** member structure contains valid data |

### `PictureNumber`

Specifies a count representing the current picture number. Initialize or update this value on transition into KSSTATE_ACQUIRE.

### `DropCount`

Specifies the number of pictures that were not captured. When capturing video, the minidriver sets this member. This counter should be incremented whenever a frame should have been captured but was not; this condition usually arises when no buffers were available during capture. Initialize or update this value on transition into KSSTATE_ACQUIRE.

### `dwSamplingFrequency`

Specifies the sampling frequency in hertz (Hz).

### `TvTunerChangeInfo`

Specifies information about the current VBI data source, including country/region code, analog video standard, and channel. This member is only valid if **dwFrameFlags** specifies the KS_VBI_FLAG_TVTUNER_CHANGE flag.

### `VBIInfoHeader`

Specifies information about the current VBI data source, including start line, end line, sampling frequency, and video standard. This member is only valid if **dwFrameFlags** specifies the KS_VBI_FLAG_VBIINFOHEADER_CHANGE flag.

## Remarks

The KS_VBI_FRAME_INFO structure provides a way to return information about a captured frame, as well as providing tuning information to VBI decoders.

The **PictureNumber** member count represents the count of the current picture based on the format used to open the stream. This count is calculated in one of two ways, depending on the device:

1. Measure the time since the stream was started and divide by the frame duration. This method is appropriate for devices that do not provide their own clock. For example: *PictureNumber = (CurrentStreamTime − StartStreamTime) / FrameDuration*

1. Add together the count of frames captured and the count of frames dropped. This method is appropriate for devices that provide their own clock. For example: *PictureNumber = FramesCaptured + FramesDropped*

When calculating the **PictureNumber** and **DropCount**, it is important to use the frame duration specified when the stream was opened, which may not necessarily match the rate at which the device is actually producing images. For example, a USB camera may only produce images at 7.5 fps, but a client could open the stream at 8 fps. In this case, all calculations should use the 8 fps number. For more information about updating **PictureNumber** and **DropCount** see [Capturing Video](https://learn.microsoft.com/windows-hardware/drivers/stream/capturing-video).

The **dwSamplingFrequency** member is not used by Microsoft VBI codecs, but may be used by other WDM codecs. It must be the same as the **VBIInfoHeader**.*SamplingFrequency* member. A minidriver indicates a change in sampling frequency by setting the KS_VBI_FLAG_VBIINFOHEADER_CHANGE bit in the **dwFrameFlags** member, and filling in all members, including **dwSamplingFrequency**, in the **VBIInfoHeader** structure.

## See also

[**KSSTREAM_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksstream_header)

[**KS_TVTUNER_CHANGE_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_tvtuner_change_info)

[**KS_VBIINFOHEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_vbiinfoheader)