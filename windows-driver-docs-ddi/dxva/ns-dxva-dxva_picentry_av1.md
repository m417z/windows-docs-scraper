## Description

The **DXVA_PicEntry_AV1** structure specifies a reference to an uncompressed surface, with the additional metadata necessary for referencing that surface.

## Members

### `width`

Specifies the coded width of the referred frame. This field corresponds to the frame_width_minus_1 syntax element. See Remarks.

### `height`

Specifies the coded height of the referred frame. This field corresponds to the frame_height_minus_1 syntax element. See Remarks.

### `wmmat`

The affine transformation matrix that applies globally to motion vectors referring to this frame.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.wminvalid`

Specifies whether the given global motion parameters are valid. If 0 then the parameters should be assumed to be invalid and not read.

### `DUMMYUNIONNAME.wmtype`

Specifies the global motion type of this referred frame. This value matches the reference software’s TransformationType enum:

``` cpp
typedef enum {
  IDENTITY = 0,
  TRANSLATION = 1,
  ROTZOOM = 2,
  AFFINE = 3,
  TRANS_TYPES,
} TransformationType;
```

This attribute is informational, to help validate the contents of **wmmat**.

### `DUMMYUNIONNAME.Reserved`

Reserved; do not use.

### `DUMMYUNIONNAME.GlobalMotionFlags`

Global motion parameters.

### `Index`

Identifies the index into **ref_frame_map_texture_index[]** to identify the frame used as a reference for this picture. When **Index** does not contain an index to a valid reference, the value shall be set to 255, to indicate that the index is invalid.

### `Reserved16Bits`

Reserved; do not use.

## Remarks

If **width** and **height** are derived for the frame (for example via the frame_size_override_flag), the host decoder will derive the appropriate values and store the result in these fields. Each AV1 frame may be coded at a different resolution than the previous frame(s).

See the [Direct X Video Acceleration Specification for AV1 Video Coding](https://www.microsoft.com/download/details.aspx?id=101577) for detailed information, including how to use this structure.