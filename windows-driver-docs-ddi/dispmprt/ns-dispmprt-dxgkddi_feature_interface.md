## Description

The **DXGKDDI_FEATURE_INTERFACE** structure contains the display kernel-mode miniport driver's (KMD's) interface that the port driver can call to query for KMD's feature support.

## Members

### `Size`

The size, in bytes, of this structure.

### `Version`

The version number of this interface. Version number constants are defined in *Dispmprt.h* (for example, **DXGK_FEATURE_INTERFACE_VERSION_1**).

### `Context`

A pointer to a private context block.

### `InterfaceReference`

Pointer to a KMD-implemented interface reference function.

### `InterfaceDereference`

Pointer to a KMD-implemented interface dereference function.

### `QueryFeatureSupport`

Pointer to a KMD-implemented [**DxgkDdiQueryFeatureSupport**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryfeaturesupport) function to query feature support.

### `QueryFeatureInterface`

Pointer to a KMD-implemented [**DxgkDdiQueryFeatureInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryfeaturesupport) function to query KMD's interfaces for a feature. The OS only calls these interfaces for enabled features, and always requests the interface for a version of the feature that the driver supports.

## Remarks

If the driver implements the **DXGKDDI_FEATURE_INTERFACE**, it no longer needs to call [**DxgkCbQueryFeatureSupport**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_queryfeaturesupport) to enable a feature in the port driver ahead of time. It can instead query feature support on demand using its **DXGKDDI_FEATURE_INTERFACE** interface.

For more information, see [Querying WDDM feature support and enablement](https://learn.microsoft.com/windows-hardware/drivers/display/querying-wddm-feature-support-and-enablement).

## See also

[**DxgkDdiQueryFeatureSupport**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryfeaturesupport)

[**DxgkDdiQueryInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_interface)