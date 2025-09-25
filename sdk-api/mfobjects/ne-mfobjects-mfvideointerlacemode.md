# MFVideoInterlaceMode enumeration

## Description

Specifies how a video stream is interlaced.

In the descriptions that follow, upper field refers to the field that contains the leading half scan line. Lower field refers to the field that contains the first full scan line.

## Constants

### `MFVideoInterlace_Unknown:0`

The type of interlacing is not known.

### `MFVideoInterlace_Progressive:2`

Progressive frames.

### `MFVideoInterlace_FieldInterleavedUpperFirst:3`

Interlaced frames. Each frame contains two fields. The field lines are interleaved, with the upper field appearing on the first line.

### `MFVideoInterlace_FieldInterleavedLowerFirst:4`

Interlaced frames. Each frame contains two fields. The field lines are interleaved, with the lower field appearing on the first line.

### `MFVideoInterlace_FieldSingleUpper:5`

Interlaced frames. Each frame contains one field, with the upper field appearing first.

### `MFVideoInterlace_FieldSingleLower:6`

Interlaced frames. Each frame contains one field, with the lower field appearing first.

### `MFVideoInterlace_MixedInterlaceOrProgressive:7`

The stream contains a mix of interlaced and progressive modes.

### `MFVideoInterlace_Last`

Reserved.

### `MFVideoInterlace_ForceDWORD:0x7fffffff`

Reserved. This member forces the enumeration type to compile as a **DWORD** value.

## Remarks

Scan lines in the lower field are 0.5 scan line lower than those in the upper field. In NTSC television, a frame consists of a lower field followed by an upper field. In PAL television, a frame consists of an upper field followed by a lower field.

The upper field is also called the even field, the top field, or field 2. The lower field is also called the odd field, the bottom field, or field 1.

If the interlace mode is MFVideoInterlace_FieldSingleUpper or MFVideoInterlace_FieldSingleLower, each sample contains a single field, so each buffer contains only half the number of field lines given in the media type.

## See also

[MF_MT_INTERLACE_MODE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-interlace-mode-attribute)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Video Interlacing](https://learn.microsoft.com/windows/desktop/medfound/video-interlacing)

[Video Media Types](https://learn.microsoft.com/windows/desktop/medfound/video-media-types)