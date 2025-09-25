# XLATEOBJ structure

## Description

The XLATEOBJ structure is used to translate color indexes from one palette to another.

## Members

### `iUniq`

A cache identifier that enables the driver to recognize an XLATEOBJ structure that it has previously cached. If this member is zero, the driver should not cache the XLATEOBJ structure.

### `flXlate`

Flags specifying hints about the translation. This member can be any combination of the following values:

| Value | Meaning |
| --- | --- |
| XO_DEVICE_ICM | ICM is enabled on the device. The driver should translate color according to the color transform created by [DrvIcmCreateColorTransform](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvicmcreatecolortransform). The driver should call [XLATEOBJ_hGetColorTransform](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-xlateobj_hgetcolortransform) to get the color transform handle. This bit is mutually exclusive from XO_HOST_ICM. |
| XO_FROM_CMYK | As a result of ICM translation, source indices are translated to the 32-bit [CMYK](https://learn.microsoft.com/windows-hardware/drivers/) color format. When this bit is set, **iSrcType**, **iDstType**, **cEntries**, and **pulXlate** should be ignored. |
| XO_HOST_ICM | ICM is performed by the graphics engine, so the colors in this color table are corrected to the target surface. This bit is set by the GDI as information for the driver: no action is required by the driver. This bit is mutually exclusive from XO_DEVICE_ICM. |
| XO_TABLE | A table is provided to translate source indices to target indices. |
| XO_TO_MONO | Source indices are translated to a monochrome format with the special property that all indices map to zero, except for one. A driver can use this to accelerate a block transfer. |
| XO_TRIVIAL | Source indices are usable as target indices. |

### `iSrcType`

Is obsolete. Use [XLATEOBJ_cGetPalette](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-xlateobj_cgetpalette) to query the source format.

### `iDstType`

Is obsolete. Use [XLATEOBJ_cGetPalette](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-xlateobj_cgetpalette) to query the destination format.

### `cEntries`

Specifies the number of entries in the array pointed to by the **pulXlate** member. Indexing into **pulXlate** with a value greater than **cEntries** results in a memory access violation.

### `pulXlate`

Pointer to an array of translation entries.

## Remarks

The destination palette always belongs to the destination surface of some drawing operation. The source palette is an application-selected palette or a palette from another surface.

The XLATEOBJ structure is used to translate color indices that refer to the source palette to indices for the destination palette. The resulting index identifies a color that matches the source color as closely as possible.

## See also

[DrvIcmCreateColorTransform](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvicmcreatecolortransform)

[XLATEOBJ_cGetPalette](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-xlateobj_cgetpalette)

[XLATEOBJ_hGetColorTransform](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-xlateobj_hgetcolortransform)

[XLATEOBJ_piVector](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-xlateobj_pivector)