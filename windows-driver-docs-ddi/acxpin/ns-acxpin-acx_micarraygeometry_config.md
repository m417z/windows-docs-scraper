## Description

The **ACX_MICARRAYGEOMETRY_CONFIG** structure is used to configure a microphone array.

## Members

### `Size`

The size of all of the data in the **ACX_MICARRAYGEOMETRY_CONFIG** structure in bytes.

### `Flags`

A combination of values from the [ACX_MICARRAYGEOMETRY_CONFIG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ne-acxpin-acx_micarraygeometry_config_flags) enum that describe the mic array.

### `Geometry`

An [ACX_MIC_ARRAY_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_mic_array_geometry) structure that specifies the type and the geometry of the microphone array.

## Remarks

The ACX_MICARRAYGEOMETRY_CONFIG structure is used as input to the AcxMicArrayGeometryCreate method.

To initialize an ACX_MICARRAYGEOMETRY_CONFIG structure, your driver should call [ACX_MICARRAYGEOMETRY_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/nf-acxpin-acx_micarraygeometry_config_init).

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_MIC_ARRAY_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_mic_array_geometry)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)