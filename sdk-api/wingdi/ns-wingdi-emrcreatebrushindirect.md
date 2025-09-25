# EMRCREATEBRUSHINDIRECT structure

## Description

The **EMRCREATEBRUSHINDIRECT** structure contains members for the [CreateBrushIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createbrushindirect) enhanced metafile record.

## Members

### `emr`

The base structure for all record types.

### `ihBrush`

Index of brush in handle table.

### `lb`

A [LOGBRUSH32](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logbrush32) structure containing information about the brush. The **lbStyle** member must be either the BS_SOLID, BS_HOLLOW, BS_NULL, or BS_HATCHED value.

Note, that if your code is used on both 32-bit and 64-bit platforms, you must use the [LOGBRUSH32](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logbrush32) structure. This maintains compatibility between the platforms when you record the metafile on one platform and use it on the other platform. If your code remains on one platform, it is sufficient to use [LOGBRUSH](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logbrush).

## See also

[CreateBrushIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createbrushindirect)

[LOGBRUSH](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logbrush)

[LOGBRUSH32](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logbrush32)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)