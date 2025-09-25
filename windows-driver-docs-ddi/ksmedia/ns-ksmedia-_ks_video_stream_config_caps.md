## Description

The **KS_VIDEO_STREAM_CONFIG_CAPS** structure describes the configuration and capabilities of a video stream, including analog video standard (for example, NTSC, PAL or SECAM), scaling, and cropping capabilities; minimum and maximum frame rates; and minimum and maximum data rates.

## Members

### `guid`

GUID that specifies the video format type. Possible values include:

- KSDATAFORMAT_SPECIFIER_VIDEOINFO

- KSDATAFORMAT_SPECIFIER_VIDEOINFO2

- KSDATAFORMAT_SPECIFIER_ANALOGVIDEO

- KSDATAFORMAT_SPECIFIER_VBI

- KSDATAFORMAT_SPECIFIER_MPEG1_VIDEO

- KSDATAFORMAT_SPECIFIER_MPEG2_VIDEO

This GUID is identical to the DirectShow AM_MEDIA_TYPE enumeration. For more information about AM_MEDIA_TYPE, see the DirectX SDK documentation.

### `VideoStandard`

Specifies the analog video standards that are supported by the stream. This member can be set to one or more (logically ORed) values from the [KS_AnalogVideoStandard](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_analogvideostandard) enumeration.

### `InputSize`

Specifies the size of the incoming signal. **InputSize** indicates the image rectangle's width and height, in pixels. This is the largest signal that the filter can digitize with each pixel remaining unique.

### `MinCroppingSize`

Specifies the smallest cropping rectangle allowed, as specified in the **rcSource** member of the [**KS_VIDEOINFOHEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_videoinfoheader) structure, which is associated with the **DataRange** member.

### `MaxCroppingSize`

Specifies the largest cropping rectangle allowed, as specified in the **rcSource** member of the KS_VIDEOINFOHEADER structure, which is associated with the **DataRange** member.

### `CropGranularityX`

Specifies the horizontal granularity of the cropping size. For example, valid widths could be specified as even multiples of four.

### `CropGranularityY`

Specifies the vertical granularity of the cropping size. For example, valid heights could be specified as even multiples of four.

### `CropAlignX`

Specifies the horizontal alignment of the cropping rectangle inside **InputSize**. For example, the minidriver could specify that valid rectangles must start on a boundary that is a multiple of four.

### `CropAlignY`

Specifies the vertical alignment of the cropping rectangle inside **InputSize**. For example, the minidriver could specify that valid rectangles must start on a boundary that is a multiple of four.

### `MinOutputSize`

Specifies the smallest bitmap that this pin can produce.

### `MaxOutputSize`

Specifies the largest bitmap that this pin can produce.

### `OutputGranularityX`

Specifies the granularity of the output bitmap width.

### `OutputGranularityY`

Specifies the granularity of the output bitmap height.

### `StretchTapsX`

Specifies one of the following values to indicate how well the filter can stretch the image's width.

| Value | Meaning |
|---|---|
| 0 | The filter cannot stretch. |
| 1 | The filter uses pixel doubling to achieve stretching. |
| 2 | The filter uses interpolation (2 taps). |
| 3 | The filter uses a higher-order (smoother) form of interpolation. |

### `StretchTapsY`

Specifies one of the following values to indicate how well the filter can stretch the image's height.

| Value | Meaning |
|---|---|
| 0 | The filter cannot stretch. |
| 1 | The filter uses pixel doubling to achieve stretching. |
| 2 | The filter uses interpolation (2 taps). |
| 3 | The filter uses a higher-order (smoother) form of interpolation. |

### `ShrinkTapsX`

Specifies one of the following values to indicate how well the filter can shrink the image's width.

| Value | Meaning |
|---|---|
| 0 | The filter cannot shrink. |
| 1 | The filter eliminates some rows of pixels to achieve shrinking. |
| 2 | The filter uses interpolation (2 taps). |
| 3 | The filter uses a higher-order (smoother) form of interpolation. |

### `ShrinkTapsY`

Specifies one of the following values to indicate how well the filter can shrink the image's height.

| Value | Meaning |
|---|---|
| 0 | The filter cannot shrink. |
| 1 | The filter eliminates some columns of pixels to achieve shrinking. |
| 2 | The filter uses interpolation (2 taps). |
| 3 | The filter uses a higher-order (smoother) form of interpolation. |

### `MinFrameInterval`

Specifies the minimum frame rate allowed. This value applies to capture filters only.

### `MaxFrameInterval`

Specifies the maximum frame rate allowed. This value applies to capture filters only.

### `MinBitsPerSecond`

Specifies the minimum data rate, in bits per second, that this pin can produce.

### `MaxBitsPerSecond`

Specifies the maximum data rate, in bits per second, that this pin can produce.

## Remarks

The KS_VIDEO_STREAM_CONFIG_CAPS structure is identical to the DirectShow VIDEO_STREAM_CONFIG_CAPS structure.

It is important to understand the relationships between the members of this structure. For example, assume the following values for some of the structure members:

**MinCroppingSize** = (160, 120)

**MaxCroppingSize** = (320, 240)

**CropGranularityX** = 4

**CropGranularityY** = 8

These values indicate that valid cropping sizes begin at **MinCroppingSize** and increase in steps in the *x*-direction by **CropGranularityX** and in the *y*-direction by **CropGranularityY**. In this case, the *x*-value can be anywhere from 160 to 320 pixels, in steps of four, and the *y*-value can be anywhere from 120 to 240 pixels in steps of eight.

In the example scenario, a few of the valid sizes are:

- 160 × 120, 164 × 120, 168 × 120, 172 × 120, and so on.

- 160 × 128, 164 × 128, 168 × 128, 172 × 128, and so on.

- 160 × 136, 164 × 136, 168 × 136, 172 × 136, and so on.

**CropAlignX** and **CropAlignY** indicate where the cropping rectangle can be located inside the input size rectangle. Given a 160 × 120 cropping rectangle and a value of 2 for **CropAlignX** and a value of 4 for **CropAlignY**, some of the valid values for the **rcSource** member of the [**KS_VIDEOINFOHEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_videoinfoheader) structure would be:

- (0, 0, 160, 120)

- (2, 0, 162, 120)

- (2, 4, 162, 124)

- (2, 8, 162, 128)

For a 320 × 240 cropping rectangle and the same cropping alignment values, (2, 4, 322, 244) is one example of the many valid rectangles.

The **MinCroppingSize**, **MaxCroppingSize**, **CropGranularityX**, **CropGranularityY**, **CropAlignX**, and **CropAlignY** members discussed above work together to specify which values of **rcSource** are valid for the **KS_VIDEOINFOHEADER** structure that describes the output pin's media type. The remaining structure members (**MinOutputSize**, **MaxOutputSize**, **OutputGranularityX**, and **OutputGranularityY**) describe the **biWidth** and **biHeight** members of the [**KS_BITMAPINFOHEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_bitmapinfoheader) structure, which is contained in the pin's media type KS_VIDEOINFOHEADER structure.

## See also

[KS_AnalogVideoStandard](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_analogvideostandard)

[**KS_BITMAPINFOHEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_bitmapinfoheader)

[**KS_VIDEOINFOHEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_videoinfoheader)