# DXGK_NODEMETADATA structure

## Description

The **DXGK_NODEMETADATA** structure describes an engine on a GPU node.

## Members

### `EngineType`

A [**DXGK_ENGINE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-dxgk_engine_type) enumeration value that indicates the engine type.

### `FriendlyName`

A NULL-terminated string that represents a descriptive friendly name for a particular engine.

The display miniport driver (KMD) must provide a value for this member if **EngineType** is **DXGK_ENGINE_TYPE_OTHER**. Otherwise, KMD should set this value to be an empty, NULL-terminated string.

This member doesn't need to be localized and can be represented with an EN-US string value.

### `Flags`

A bit field of [**DXGK_NODEMETADATA_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_nodemetadata_flags) values that describe the engine's metadata. This member is available starting in WDDM 2.2.

### `Reserved`

Reserved for system use.

### `GpuMmuSupported`

A Boolean value that indicates whether the graphics engines of the node support the [GpuMmu model](https://learn.microsoft.com/windows-hardware/drivers/display/gpummu-model). Available starting in WDDM 2.0.

### `IoMmuSupported`

A Boolean value that indicates whether the graphics engines of the node support the [IoMmu model](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-model). Available starting in WDDM 2.0.

## Remarks

This structure is used to define the structure **DXGKARG_GETNODEMETADATA**, in the call to KMD's [**DXGKDDI_GETNODEMETADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getnodemetadata).

For more information on how to use this structure, see [Enumerating GPU engine capabilities](https://learn.microsoft.com/windows-hardware/drivers/display/enumerating-gpu-nodes).

## See also

[**DXGK_ENGINE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-dxgk_engine_type)

[**DXGK_NODEMETADATA_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_nodemetadata_flags)

[**DXGKDDI_GETNODEMETADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getnodemetadata)