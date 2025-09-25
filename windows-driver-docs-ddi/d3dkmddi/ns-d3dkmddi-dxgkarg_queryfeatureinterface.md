## Description

**DXGKARG_QUERYFEATUREINTERFACE** is the parameter to the [**DxgkDdiQueryFeatureInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryfeatureinterface) function.

## Members

### `FeatureId`

[in] A [**DXGK_FEATURE_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-dxgk_feature_id) enumeration value that specifies the ID of the feature whose interface is being queried.

### `Version`

[in] The version of the feature whose interface is being queried. See Remarks.

### `InterfaceSize`

[in/out] The size of the interface buffer that **Interface** points to, in bytes. On success, this value must be set to the size of the returned interface. If the output value is less than the input size of the requested interface, the caller should return an error, such as STATUS_BUFFER_TOO_SMALL.

### `Interface`

[in/out] A pointer to the interface buffer to fill in. This buffer is guaranteed to be exactly **InterfaceSize** bytes in length.

## Remarks

Feature interfaces aren't required to be backwards compatible with older versions of the same interface. For example, the interface for version 1 and version 2 of a feature may be radically different (that is, the v2 interface doesn't need to be an extension of the v1 interface). This is useful for feature bringup when the design of a feature is iterated on over time, without the need to permanently support a DDI forever.

While a feature's interface for a particular version may be forever defined somewhere in documentation, the OS and driver may set a lower bound (minimum) supported version of a feature to reduce the need to support old, deprecated interfaces.

For more information, see [Querying WDDM feature support and enablement](https://learn.microsoft.com/windows-hardware/drivers/display/querying-wddm-feature-support-and-enablement).

## See also

[**DXGK_FEATURE_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-dxgk_feature_id)

[**DXGKDDI_FEATURE_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkddi_feature_interface)

[**DxgkDdiQueryFeatureInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryfeatureinterface)