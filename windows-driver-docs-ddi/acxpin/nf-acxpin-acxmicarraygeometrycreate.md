## Description

The **AcxMicArrayGeometryCreate** function creates and initializes a new [ACX_MIC_ARRAY_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_mic_array_geometry) object.

## Parameters

### `AcxCircuit` [in]

The ACXCIRCUIT object to which the mic array geometry will be added. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Attributes` [in]

Pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure to use when initializing the new **ACX_MIC_ARRAY_GEOMETRY** structure.

### `Config` [in]

Pointer to an [ACX_MICARRAYGEOMETRY_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_micarraygeometry_config) structure to use when initializing the new **ACX_MIC_ARRAY_GEOMETRY** structure.

### `MicArrayGeometry` [out]

Pointer to the newly created **ACX_MIC_ARRAY_GEOMETRY** structure.

## Return value

The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

Call the [ACX_MICARRAYGEOMETRY_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/nf-acxpin-acx_micarraygeometry_config_init) function to initialize the **ACX_MICARRAYGEOMETRY_CONFIG** structure before using it to call **AcxMicArrayGeometryCreate**.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_MIC_ARRAY_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_mic_array_geometry)
- [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)
- [ACX_MICARRAYGEOMETRY_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_micarraygeometry_config)
- [ACX_MICARRAYGEOMETRY_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/nf-acxpin-acx_micarraygeometry_config_init)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)