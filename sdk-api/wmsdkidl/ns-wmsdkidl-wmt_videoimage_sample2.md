# WMT_VIDEOIMAGE_SAMPLE2 structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMT_VIDEOIMAGE_SAMPLE2** structure describes a sample for a Video Image stream. This structure must be used, either alone or with an accompanying image, in each sample passed to the writer for a Video Image stream. For more information, see [Writing Video Image Samples](https://learn.microsoft.com/windows/desktop/wmformat/writing-video-image-samples).

## Members

### `dwMagic`

Reserved. You must set this member to WMT_VIDEOIMAGE_MAGIC_NUMBER_2.

### `dwStructSize`

Size of the structure. Set to `sizeof(WMT_VIDEOIMAGE_SAMPLE2)`.

### `dwControlFlags`

Specifies the type of sample. Use one or more of the flags in the following table, combined with the bitwise **OR** operator (|):

| Flag | Description |
| --- | --- |
| WMT_VIDEOIMAGE_SAMPLE_INPUT_FRAME | Indicates that the sample contains an input image. The image data must be included in the sample immediately following the structure. The format of the image must conform to the values set in the input properties for the stream. |
| WMT_VIDEOIMAGE_SAMPLE_OUTPUT_FRAME | Indicates that the sample should result in a unique output frame in the stream. If this flag is not set, the remainder of the members of the structure are ignored and the frame in the stream will be a duplicate of the previous frame. |
| WMT_VIDEOIMAGE_SAMPLE_USES_CURRENT_INPUT_FRAME | Indicates that the sample is based, either solely or in part, on the current image. If this flag is set, the first set of value members will be used (those with names containing the string "Curr"). This flag is not valid unless used in combination with WMT_VIDEOIMAGE_SAMPLE_OUTPUT_FRAME. |
| WMT_VIDEOIMAGE_SAMPLE_USES_PREVIOUS_INPUT_FRAME | Indicates that the sample is based, either solely or in part, on the previous image. If this flag is set, the second set of value members will be used (those with names containing the string "Prev"). This flag is not valid unless used in combination with WMT_VIDEOIMAGE_SAMPLE_OUTPUT_FRAME. |

### `dwViewportWidth`

Width of the output frame.

### `dwViewportHeight`

Height of the output frame.

### `dwCurrImageWidth`

Width of the current image.

### `dwCurrImageHeight`

Height of the current image.

### `fCurrRegionX0`

X component of the origin point of the region of interest in the current image.

### `fCurrRegionY0`

Y component of the origin point of the region of interest in the current image.

### `fCurrRegionWidth`

Width of the region of interest in the current image. The specified region of interest will be sized to match the size of the output frame.

### `fCurrRegionHeight`

Height of the region of interest in the current image. The specified region of interest will be sized to match the size of the output frame.

### `fCurrBlendCoef`

Blending coefficient for the current image. This value specifies the transparency of the current image relative to the previous image. The blending coefficients of the two images must total 1.0.

### `dwPrevImageWidth`

Width of the previous image.

### `dwPrevImageHeight`

Height of the previous image.

### `fPrevRegionX0`

X component of the origin point of the region of interest in the previous image.

### `fPrevRegionY0`

Y component of the origin point of the region of interest in the previous image.

### `fPrevRegionWidth`

Width of the region of interest in the previous image. The specified region of interest will be sized to match the size of the output frame.

### `fPrevRegionHeight`

Height of the region of interest in the previous image. The specified region of interest will be sized to match the size of the output frame.

### `fPrevBlendCoef`

Blending coefficient for the previous image. This value specifies the transparency of the previous image relative to the current image. The blending coefficients of the two images must total 1.0.

### `dwEffectType`

The effect identifier of the transition between the previous image and the current image. For more information, see [Video Image Transitions](https://learn.microsoft.com/windows/desktop/wmformat/video-image-transitions).

### `dwNumEffectParas`

The number of effect parameters relevant to the current effect. The final five members of this structure contain the values of effect parameters. This member specifies how many of those parameters contain valid information.

### `fEffectPara0`

Effect parameter. The uses of this parameter and the other four parameters in this structure are determined by the effect used, as specified by the value of the **dwEffectType** member.

### `fEffectPara1`

Effect parameter. The uses of this parameter and the other four parameters in this structure are determined by the effect used, as specified by the value of the **dwEffectType** member.

### `fEffectPara2`

Effect parameter. The uses of this parameter and the other four parameters in this structure are determined by the effect used, as specified by the value of the **dwEffectType** member.

### `fEffectPara3`

Effect parameter. The uses of this parameter and the other four parameters in this structure are determined by the effect used, as specified by the value of the **dwEffectType** member.

### `fEffectPara4`

Effect parameter. The uses of this parameter and the other four parameters in this structure are determined by the effect used, as specified by the value of the **dwEffectType** member.

### `bKeepPrevImage`

For input samples, **TRUE** indicates that the new image should replace the current image and that the current image should be discarded. The default behavior, indicated by setting this member to **FALSE**, is for the current image to become the previous image and the new image to become the current image.

## Remarks

When creating an input Video Image sample, the values for the current image describe the image attached to the sample. The values for the previous image describe the image that was the current image in the previous sample. Normally, the previous image is discarded when you pass in a new image. (The old current image becomes the new previous image and the image passed in with the sample becomes the new current image.) If, when passing a new image, you want to discard the old current image and keep the old previous image, you can set the **bKeepPrevImage** member to **TRUE**.

## See also

[Structures](https://learn.microsoft.com/windows/desktop/wmformat/structures)