# DXGKARGCB_ISFEATUREENABLED structure

## Description

The **DXGKARGCB_ISFEATUREENABLED** structure contains the arguments used in the [**DXGKCB_ISFEATUREENABLED**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_isfeatureenabled) callback function, to query a driver feature's enabled state.

## Members

### `DeviceHandle`

[in] Device handle that was passed to the driver's [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function.

### `FeatureId`

[in] A [**DXGK_FEATURE_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-dxgk_feature_id) value that identifies the feature to query enabled state for.

### `Enabled`

[out] FALSE if the OS instructs the driver not to enable the feature. TRUE if the OS allows the driver to enable the feature.

## See also

[**DXGKCB_ISFEATUREENABLED**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_isfeatureenabled)