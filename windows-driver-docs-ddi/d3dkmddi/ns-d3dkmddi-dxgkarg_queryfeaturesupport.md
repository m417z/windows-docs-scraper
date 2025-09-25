## Description

**DXGKARG_QUERYFEATURESUPPORT** is the parameter to the [**DxgkDdiQueryFeatureSupport**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryfeaturesupport) function.

## Members

### `FeatureId`

[in] A [**DXGK_FEATURE_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-dxgk_feature_id) value that specifies the ID of the feature being queried.

### `MinSupportedVersion`

[out] Driver-defined value that identifies the minimum version supported by the driver. If **SupportedByDriver** is TRUE, this value must be non-zero.

### `MaxSupportedVersion`

[out] Driver-defined value that identifies the maximum version supported by the driver. If **SupportedByDriver** is TRUE, this value must be non-zero, and must be greater than or equal to **MinSupportedVersion**.

### `AllowExperimental`

[in] If TRUE, the driver may report experimental features as supported. If FALSE, the driver must report an experimental feature as unsupported. The OS determines whether a particular feature is allowed to be enabled in an experimental state or not. See Remarks.

### `SupportedByDriver`

[out] The driver sets this to TRUE if it implements and supports this feature; otherwise, it sets it to FALSE. See Remarks.

### `SupportedOnCurrentConfig`

[out] The driver sets this to TRUE if the current configuration supports this feature; otherwise, it sets it to FALSE.

## Remarks

The distinction between **SupportedByDriver** and **SupportedOnCurrentConfig** is used to determine if the system is capable of actually using a particular feature. For example, in a test environment, it's often important to understand that the driver supports a feature, but is running on older hardware that doesn't support it. Such a test should be skipped instead of reporting a failure. For a feature to be considered enabled, both values must be reported as TRUE by the driver.

For more information, see [Querying WDDM feature support and enablement](https://learn.microsoft.com/windows-hardware/drivers/display/querying-wddm-feature-support-and-enablement).

## See also

[**DXGK_FEATURE_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-dxgk_feature_id)

[**DXGKDDI_FEATURE_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkddi_feature_interface)

[**DxgkDdiQueryFeatureSupport**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryfeaturesupport)