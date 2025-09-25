## Description

The **DXGK_ISFEATUREENABLED_RESULT** structure defines the results of a feature query.

## Members

### `Version`

When enabled (**Enabled**=TRUE), **Version** is the negotiated version of the feature that is used. This value is the highest version that is supported by both the OS and driver. For example, if the OS supports versions 1 through 3, and the driver supports versions 2 through 5, the resulting negotiated feature version is 3.

### `Enabled`

When set, the feature is enabled.

### `KnownFeature`

When set, the feature is known to the OS.

### `SupportedByDriver`

When set, the feature is supported by the driver. **SupportedByDriver** is set only if the feature depends on the driver support.

### `SupportedOnCurrentConfig`

When set, the feature is supported on the current configuration.

### `Reserved`

Reserved for system use.

### `Value`

An alternative way to access the bit fields of this structure.

## Remarks

For more information, see [Querying WDDM feature support and enablement](https://learn.microsoft.com/windows-hardware/drivers/display/querying-wddm-feature-support-and-enablement).

## See also

[**D3DKMT_ISFEATUREENABLED**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_isfeatureenabled)

[**DXGK_FEATURE_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_feature_interface)

[**DXGK_FEATURE_INTERFACE:IsFeatureEnabled**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nf-d3dkmddi-dxgkisfeatureenabled2)