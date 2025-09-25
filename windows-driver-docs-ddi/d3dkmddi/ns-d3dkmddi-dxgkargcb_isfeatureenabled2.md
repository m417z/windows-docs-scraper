## Description

The **DXGKARGCB_ISFEATUREENABLED2** structure is the parameter for the [**DXGKCB_ISFEATUREENABLED2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_isfeatureenabled2) callback function.

## Members

### `FeatureId`

[in] A [**DXGK_FEATURE_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-dxgk_feature_id) value that identifies the feature to query enabled state for.

### `Flags`

[in] A [**DXGKARGCB_ISFEATUREENABLED2_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_isfeatureenabled2_flags) value that specifies optional feature query flags.

### `Result`

[out] A [**DXGK_ISFEATUREENABLED_RESULT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-dxgk_isfeatureenabled_result) value in which the result of the feature query is returned.

## Remarks

For more information, see [Querying WDDM feature support and enablement](https://learn.microsoft.com/windows-hardware/drivers/display/querying-wddm-feature-support-and-enablement).

## See also

[**DXGKCB_ISFEATUREENABLED2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_isfeatureenabled2)