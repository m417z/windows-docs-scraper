# MFVideoFlags enumeration

## Description

Contains flags that describe a video stream.

These flags are used in the [MFVideoInfo](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoinfo) structure, which is part of the [MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat) structure.

## Constants

### `MFVideoFlag_PAD_TO_Mask`

Use this value to mask out the next three flags, which describe the effective aspect ratio of the image. This value by itself is not a valid flag.

### `MFVideoFlag_PAD_TO_None`

Do not modify the picture aspect ratio.

### `MFVideoFlag_PAD_TO_4x3`

Display the image in a 4 x 3 area. If this flag is set, the geometrical aperture of the picture should be expanded to a 4 x 3 area by letterboxing or pillarboxing. The geometrical aperture is the portion of the image that is intended to be viewed, without any overscan region.

### `MFVideoFlag_PAD_TO_16x9`

Display the image in a 16 x 9 area. If this flag is set, the geometrical aperture of the picture should be expanded to a 16 x 9 area by letterboxing or pillarboxing.

### `MFVideoFlag_SrcContentHintMask`

Use this value to mask out the next three flags, which describe the source content. This value by itself is not a valid flag.

### `MFVideoFlag_SrcContentHintNone`

There is no additional information about the source content .

### `MFVideoFlag_SrcContentHint16x9`

The source is a 16 x 9 image encoded within a 4 x 3 area.

### `MFVideoFlag_SrcContentHint235_1`

The source is a 2.35:1 image encoded within a 16 x 9 or 4 x 3 area.

### `MFVideoFlag_AnalogProtected:0x20`

Analog copy protection should be applied.

### `MFVideoFlag_DigitallyProtected:0x40`

Digital copy protection should be applied.

### `MFVideoFlag_ProgressiveContent:0x80`

The video source is progressive content encoded as interlaced video, possibly using 3:2 pulldown. This flag is obsolete. See Remarks.

### `MFVideoFlag_FieldRepeatCountMask`

Used to extract the field repeat count. This flag is obsolete. See Remarks.

### `MFVideoFlag_FieldRepeatCountShift:8`

Used to extract the field repeat count. This flag is obsolete. See Remarks.

### `MFVideoFlag_ProgressiveSeqReset:0x800`

The progressive sequence was disrupted and the sequence is interlaced at the break. This flag is obsolete. See Remarks.

### `MFVideoFlag_PanScanEnabled:0x20000`

Apply the pan and scan rectangle on the output.

### `MFVideoFlag_LowerFieldFirst:0x40000`

The sample contains the lower field. This flag applies only if the interlace mode is single fields (MFVideoInterlace_FieldSingleUpperFirst or MFVideoInterlace_FieldSingleLowerFirst). This flag is obsolete. See Remarks.

### `MFVideoFlag_BottomUpLinearRep:0x80000`

The image is represented bottom-up in memory. This flag should be used only with RGB formats.

### `MFVideoFlags_DXVASurface:0x100000`

Reserved. Do not use.

### `MFVideoFlags_RenderTargetSurface:0x400000`

Reserved. Do not use.

### `MFVideoFlags_ForceQWORD:0x7fffffff`

Reserved. This member forces the enumeration type to compile as a **QWORD** value.

## Remarks

Developers are encouraged to use media type attributes instead of using the [MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat) structure. The following table lists the attributes that correspond to the flags defined in this enumeration.

| Flags | Media Type Attribute |
| --- | --- |
| MFVideoFlag_PAD_TO_None<br><br>MFVideoFlag_PAD_TO_4x3<br><br>MFVideoFlag_PAD_TO_16x9 | [MF_MT_PAD_CONTROL_FLAGS](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-pad-control-flags-attribute) |
| MFVideoFlag_SrcContentHint16x9<br><br>MFVideoFlag_SrcContentHint16x9<br><br>MFVideoFlag_SrcContentHint235_1 | [MF_MT_SOURCE_CONTENT_HINT](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-source-content-hint-attribute) |
| MFVideoFlag_AnalogProtected<br><br>MFVideoFlag_DigitallyProtected | [MF_MT_DRM_FLAGS](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-drm-flags-attribute) |
| MFVideoFlag_PanScanEnabled | [MF_MT_PAN_SCAN_ENABLED](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-pan-scan-enabled-attribute) |
| MFVideoFlag_BottomUpLinearRep | Use the [MF_MT_DEFAULT_STRIDE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-default-stride-attribute) attribute to specify a negative stride. |

The following flags were defined to describe per-sample interlacing information, but are obsolete:

* MFVideoFlag_ProgressiveContent
* MFVideoFlag_FieldRepeatCountMask
* MFVideoFlag_FieldRepeatCountShift
* MFVideoFlag_ProgressiveSeqReset
* MFVideoFlag_LowerFieldFirst

Instead, components should use sample attributes to describe per-sample interlacing information, as described in the topic [Video Interlacing](https://learn.microsoft.com/windows/desktop/medfound/video-interlacing).

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Media Type Attributes](https://learn.microsoft.com/windows/desktop/medfound/media-type-attributes)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)