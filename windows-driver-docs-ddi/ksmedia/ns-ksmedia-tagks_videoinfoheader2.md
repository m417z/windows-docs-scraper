# tagKS_VIDEOINFOHEADER2 structure

## Description

The KS_VIDEOINFOHEADER2 structure describes the details of a video stream, including bob or weave settings, copy protection, and pixel aspect ratio.

## Members

### `rcSource`

Specifies a clipping rectangle that selects the portion of the active video signal to use.

### `rcTarget`

Specifies a rectangle that indicates what part of the target buffer to use.

### `dwBitRate`

Specifies a value that indicates the video stream's appropriate data rate, in bits per second.

### `dwBitErrorRate`

Specifies a value that indicates the video stream's data error rate, in bit errors per second.

### `AvgTimePerFrame`

Specifies the average time per frame, in 100-nanosecond units.

### `dwInterlaceFlags`

Specifies interlace information. Undefined flags must be set to zero, or the connection may be rejected. This member can be set to one or more (logical OR) values that are defined in *ksmedia.h*:

| Flag | Description |
|--|--|
| KS_INTERLACE_IsInterlaced | Indicates an interlace stream. If 0, then the other KS_INTERLACE_Xxx bits are irrelevant. |
| KS_INTERLACE_1FieldPerSample | Indicates one field per media sample. If zero, indicates two fields per media sample. |
| KS_INTERLACE_Field1First | Indicates that Field 1 is first. If zero, indicates that Field 2 is first. Top field in PAL is Field 1, top field in NTSC is Field 2. |
| KS_INTERLACE_UNUSED | Unused |
| KS_INTERLACE_FieldPatternMask | Indicates the bits used to specify field pattern. |
| KS_INTERLACE_FieldPatField1Only | Indicates that a stream never contains a Field 2. |
| KS_INTERLACE_FieldPatField2Only | Indicates that a stream never contains a Field 1. |
| KS_INTERLACE_FieldPatBothRegular | Indicates that there will be a Field 2 for every Field 1. |
| KS_INTERLACE_FieldPatBothIrregular | Indicates a random pattern of Field 1s and Field 2s. |
| KS_INTERLACE_DisplayModeMask | Invalid for video capture. |
| KS_INTERLACE_DisplayModeBobOnly | Invalid for video capture. |
| KS_INTERLACE_DisplayModeWeaveOnly | Invalid for video capture. |
| KS_INTERLACE_DisplayModeBobOrWeave | Invalid for video capture. |

### `dwCopyProtectFlags`

Specifies a KSCOPYPROTECTRestrictDuplication value (0x00000001) to indicate if duplication of a stream should be restricted. If undefined, specify zero or the connection will be rejected.

### `dwPictAspectRatioX`

Specifies the *x* dimension of the picture-aspect ratio (for example, 16 for a 16 × 9 display). The value is expressed in inches-by-inches, not pixels-by-pixels.

### `dwPictAspectRatioY`

Specifies the *y* dimension of the picture aspect ratio (for example, 9 for 16 × 9 display). The value is expressed in inches-by-inches, not pixels-by-pixels.

### `dwControlFlags`

In operating systems prior to Windows Vista, this member was named **dwReserved1** and was required to be zero. In Windows Vista, **dwReserved1** was combined in a union with a new member named **dwControlFlags**. If used, **dwControlFlags** contains a bitwise OR of the flags in the following table.

| Value | Description |
|--|--|
| AMCONTROL_USED | Indicates the **dwControlFlags** flags are used. |
| AMCONTROL_PAD_TO_4x3 | The image should be padded and displayed in a 4 x 3 area. |
| AMCONTROL_PAD_TO_16x9 | The image should be padded and displayed in a 16 x 9 area. |
| AMCONTROL_COLORINFO_PRESENT | Additional color information is contained in the upper 24 bits of the **dwControlFlags** field. |

The AMCONTROL_USED flag provides backward compatibility with older filters. If the AMCONTROL_USED flag is not set, the remaining bits in this field should be ignored. If a filter uses any other flags, it should set the AMCONTROL_USED flag.

The two AMCONTROL_PAD_xxx flags are used by decoders to determine the aspect ratio of the output rectangle.

If the AMCONTROL_COLORINFO_PRESENT flag is set, it means the upper 24 bits of the dwControlFlags field are treated as a [DXVA_ExtendedFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_extendedformat) structure.

See the Remarks section later in this topic for more information about **dwControlFlags**.

### `dwReserved1`

This member is for backward compatibility. See **dwControlFlags** for more information.

### `dwReserved2`

Reserved for system use. Must be set to zero or the connection will be rejected.

### `bmiHeader`

Indicates a [KS_BITMAPINFOHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_bitmapinfoheader) structure that contains color and dimension information for the video image bitmap.

## Remarks

To describe a video stream without bob or weave settings, use [KS_VIDEOINFOHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_videoinfoheader).

The KS_VIDEOINFOHEADER2 structure is identical to the DirectShow [VIDEOINFOHEADER2](https://learn.microsoft.com/previous-versions//ms787914(v=vs.85)) structure.

Capture minidrivers that produce video fields (instead of frames) must use the [KS_DATARANGE_VIDEO2](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_datarange_video2) structure, which contains the KS_VIDEOINFOHEADER2 structure.

A source filter can request that the sink filter take only a section of the video by providing values that effectively define a clipping rectangle in the **rcSource** member. However, if the sink filter does not check for the clipping rectangle on connection, the sink filter simply renders all of the video, effectively ignoring any clipping information passed from the source filter to the sink filter.

Ideally, a sink filter checks **rcSource** and if the sink filter does not support image extraction, and the rectangle is *not* empty, then it rejects the connection. A filter should use the Win32 function **SetRectEmpty** to reset a rectangle to all zeros (and set **IsRectEmpty** to later check the rectangle).

The **rcTarget** member specifies the destination rectangle for the video. Most source filters set this member to all zeros. A downstream filter can request that the video be placed in a particular area of the buffers that it supplies. In this case, it calls the Win32 function **QueryAccept** with a nonempty target.

If the AMCONTROL_COLORINFO_PRESENT flag is set in the **dwControlFlags** member, you can cast the **dwControlFlags** value to a [DXVA_ExtendedFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_extendedformat) structure to access the extended color information. For more information, see [VIDEOINFOHEADER2](https://learn.microsoft.com/previous-versions//ms787914(v=vs.85)).

## See also

[KS_BITMAPINFOHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_bitmapinfoheader)

[KS_DATARANGE_VIDEO2](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_datarange_video2)

[KS_VIDEOINFOHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_videoinfoheader)