# EMRMODIFYWORLDTRANSFORM structure

## Description

The **EMRMODIFYWORLDTRANSFORM** structure contains members for the [ModifyWorldTransform](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-modifyworldtransform) enhanced metafile record.

## Members

### `emr`

The base structure for all record types.

### `xform`

The world-space to page-space transform data.

### `iMode`

Indicates how the transformation data modifies the current world transformation. This member can be one of the following values: MWT_IDENTITY, MWT_LEFTMULTIPLY, or MWT_RIGHTMULTIPLY.

## See also

[EMR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-emr)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[ModifyWorldTransform](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-modifyworldtransform)

[XFORM](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-xform)