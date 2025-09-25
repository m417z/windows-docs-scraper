# WMT_VIDEOIMAGE_SAMPLE structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[This structure is no longer available for use as of the Windows Media Video 9 Image v2 codec. Instead, use [WMT_VIDEOIMAGE_SAMPLE2](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wmt_videoimage_sample2).]

The **WMT_VIDEOIMAGE_SAMPLE** structure describes a sample for a Video Image stream that uses the Windows Media Video 9 Image codec.

## Members

### `dwMagic`

Reserved value. Always set to WMT_VIDEOIMAGE_MAGIC_NUMBER.

### `cbStruct`

Size of the structure. Always set to **sizeof**(**WMT_VIDEOIMAGE_SAMPLE**).

### `dwControlFlags`

One or more of the following values.

| Value | Description |
| --- | --- |
| WMT_VIDEOIMAGE_SAMPLE_INPUT_FRAME | Indicates that the sample contains an input image. The image data must immediately follow the structure in the sample and must conform to the values set in the input properties for the stream. |
| WMT_VIDEOIMAGE_SAMPLE_OUTPUT_FRAME | Indicates that the sample should result in a unique frame in the stream. If this flag is not set, the remainder of the members of the structure are ignored and the frame in the stream will be identical to the last output stream. |
| WMT_VIDEOIMAGE_SAMPLE_USES_CURRENT_INPUT_FRAME | Indicates that the sample is based, either solely or in part, on the current image. If this flag is set, the first set of value members will be used. This flag cannot be set if the sample is input only. |
| WMT_VIDEOIMAGE_SAMPLE_USES_PREVIOUS_INPUT_FRAME | Indicates that the sample is based, either solely or in part, on the previous image. If this flag is set, the second set of value members will be used. This flag cannot be set if the sample is input only. |

### `dwInputFlagsCur`

One or more flags indicating the operation to perform on the current image. The following flags are available.

| Value | Description |
| --- | --- |
| WMT_VIDEOIMAGE_SAMPLE_ADV_BLENDING | Indicates that the sample uses advanced blending. This feature is not supported in the current version. |
| WMT_VIDEOIMAGE_SAMPLE_BLENDING | Indicates that the sample contains blending. If this flag is set, the sum of the values of **lCurBlendCoef1** and **lPrevBlendCoef1** (before multiplying by the denominator) must equal 1. |
| WMT_VIDEOIMAGE_SAMPLE_MOTION | Indicates that the sample uses pan and/or zoom. |
| WMT_VIDEOIMAGE_SAMPLE_ROTATION | Indicates that the sample uses rotation. This feature is not supported in the current version. |

### `lCurMotionXtoX`

**LONG** value containing the horizontal scaling factor of the current image. A scaling factor of 1 means no horizontal scaling will be performed for this sample. This value must be multiplied by WMT_VIDEOIMAGE_INTEGER_DENOMINATOR before being set in the structure.

### `lCurMotionYtoX`

Not used.

### `lCurMotionXoffset`

**LONG** value containing the horizontal offset for the current image, in pixels, in relation to the last output sample. An offset of 0 means that no panning will be performed for this sample. This value must be multiplied by WMT_VIDEOIMAGE_INTEGER_DENOMINATOR before being set in the structure.

### `lCurMotionXtoY`

Not used.

### `lCurMotionYtoY`

**LONG** value containing the vertical scaling factor of the current image. A scaling factor of 1 means no vertical scaling will be performed for this sample. This value must be multiplied by WMT_VIDEOIMAGE_INTEGER_DENOMINATOR before being set in the structure.

### `lCurMotionYoffset`

**LONG** value containing the vertical offset for the current image, in pixels, in relation to the last output sample. An offset of 0 means that no panning will be performed for this sample. This value must be multiplied by WMT_VIDEOIMAGE_INTEGER_DENOMINATOR before being set in the structure.

### `lCurBlendCoef1`

**LONG** value containing the blend coefficient for the current image when combined with the previous image for an output. This coefficient and the coefficient for the previous image must total 1. This value must be multiplied by WMT_VIDEOIMAGE_INTEGER_DENOMINATOR before being set in the structure.

### `lCurBlendCoef2`

Not used.

### `dwInputFlagsPrev`

One or more flags indicating the operation to perform on the previous image. The following flags are available.

| Value | Description |
| --- | --- |
| WMT_VIDEOIMAGE_SAMPLE_ADV_BLENDING | Indicates that the sample uses advanced blending. This feature is not supported in the current version. |
| WMT_VIDEOIMAGE_SAMPLE_BLENDING | Indicates that the sample contains blending. If this flag is set, the sum of the values of **lCurBlendCoef1** and **lPrevBlendCoef1** (before multiplying by the denominator) must equal 1. |
| WMT_VIDEOIMAGE_SAMPLE_MOTION | Indicates that the sample uses pan and/or zoom. |
| WMT_VIDEOIMAGE_SAMPLE_ROTATION | Indicates that the sample uses rotation. This feature is not supported in the current version. |

### `lPrevMotionXtoX`

**LONG** value containing the horizontal scaling factor of the previous image. A scaling factor of 1 means no horizontal scaling will be performed for this sample. This value must be multiplied by WMT_VIDEOIMAGE_INTEGER_DENOMINATOR before being set in the structure.

### `lPrevMotionYtoX`

Not used.

### `lPrevMotionXoffset`

**LONG** value containing the horizontal offset for the previous image, in pixels, in relation to the last output sample. An offset of 0 means that no panning will be performed for this sample. This value must be multiplied by WMT_VIDEOIMAGE_INTEGER_DENOMINATOR before being set in the structure.

### `lPrevMotionXtoY`

Not used.

### `lPrevMotionYtoY`

**LONG** value containing the vertical scaling factor of the previous image. A scaling factor of 1 means no vertical scaling will be performed for this sample. This value must be multiplied by WMT_VIDEOIMAGE_INTEGER_DENOMINATOR before being set in the structure.

### `lPrevMotionYoffset`

**LONG** value containing the vertical offset for the previous image, in pixels, in relation to the last output sample. An offset of 0 means that no panning will be performed for this sample. This value must be multiplied by WMT_VIDEOIMAGE_INTEGER_DENOMINATOR before being set in the structure.

### `lPrevBlendCoef1`

**LONG** value containing the blend coefficient for the previous image when combined with the current image for an output. This coefficient and the coefficient for the current image must total 1. This value must be multiplied by WMT_VIDEOIMAGE_INTEGER_DENOMINATOR before being set in the structure.

### `lPrevBlendCoef2`

Not used.

## See also

[Structures](https://learn.microsoft.com/windows/desktop/wmformat/structures)