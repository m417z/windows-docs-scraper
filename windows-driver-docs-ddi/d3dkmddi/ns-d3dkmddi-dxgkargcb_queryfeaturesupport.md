## Description

The **DXGKARGCB_QUERYFEATURESUPPORT** structure is the parameter passed to the [**DXGKCB_QUERYFEATURESUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_queryfeaturesupport) callback function to query for feature support.

## Members

### `DeviceHandle`

[in] Device handle that was passed to the driver [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function.

### `FeatureId`

[in] A [**DXGK_FEATURE_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-dxgk_feature_id) value that identifies the feature to query enabled state for.

### `DriverSupportState`

[in] A UINT value that indicates the driver's support state for the feature identified by **FeatureId**. This field can be one of the following values.

| Value | Meaning |
| ----- | ------- |
| DXGK_FEATURE_SUPPORT_ALWAYS_OFF (0) | When the driver doesn’t support a feature, it shouldn’t call [**DXGKCB_QUERYFEATURESUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_queryfeaturesupport) with that feature ID. This value is provided for implementation convenience of enumerating possible driver support states for a particular feature. |
| DXGK_FEATURE_SUPPORT_EXPERIMENTAL (1) | Driver support for a feature is in the experimental state. |
| DXGK_FEATURE_SUPPORT_STABLE (2) | Driver support for a feature is in the stable state. |
| DXGK_FEATURE_SUPPORT_ALWAYS_ON (3) | Driver support for a feature is in the always-on state and the driver cannot operate without this feature enabled. |

### `Enabled`

[out] The OS sets this field to FALSE to instruct the driver not to enable the feature, and sets it to TRUE if the OS allows the driver to enable the feature.

## See also

[**DXGK_FEATURE_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-dxgk_feature_id)

[**DXGKCB_QUERYFEATURESUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_queryfeaturesupport)