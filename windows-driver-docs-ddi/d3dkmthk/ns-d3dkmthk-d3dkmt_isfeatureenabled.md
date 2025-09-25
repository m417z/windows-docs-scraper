## Description

**D3DKMT_ISFEATUREENABLED** is a parameter for the [**D3DKMTIsFeatureEnabled**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtisfeatureenabled) function that queries whether a feature is enabled.

## Members

### `hAdapter`

[in] The adapter for which to query the feature. If the feature is a global feature, this value must be NULL.

### `FeatureId`

[in] A [**DXGK_FEATURE_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-dxgk_feature_id) value that specifies the feature ID to query enabled state for.

### `Result`

[out] A [**DXGK_ISFEATUREENABLED_RESULT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-dxgk_isfeatureenabled_result) structure that contains the result of the query.

## Remarks

For more information, see [Querying WDDM feature support and enablement](https://learn.microsoft.com/windows-hardware/drivers/display/querying-wddm-feature-support-and-enablement).

## See also

[**D3DKMTIsFeatureEnabled**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtisfeatureenabled)