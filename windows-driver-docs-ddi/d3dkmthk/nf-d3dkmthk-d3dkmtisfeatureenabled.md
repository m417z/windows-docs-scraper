## Description

A user-mode client calls **D3DKMTIsFeatureEnabled** to query whether a particular WDDM feature is enabled.

## Parameters

### `unnamedParam1`

[in/out] Pointer to a [**D3DKMT_ISFEATUREENABLED**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_isfeatureenabled) structure that describes the feature to query.

## Return value

**D3DKMTIsFeatureEnabled** returns STATUS_SUCCESS upon successful completion. Otherwise, it returns an appropriate NTSTATUS code.

## Remarks

For more information, see [Querying WDDM feature support and enablement](https://learn.microsoft.com/windows-hardware/drivers/display/querying-wddm-feature-support-and-enablement).

## See also

[**D3DKMT_ISFEATUREENABLED**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_isfeatureenabled)