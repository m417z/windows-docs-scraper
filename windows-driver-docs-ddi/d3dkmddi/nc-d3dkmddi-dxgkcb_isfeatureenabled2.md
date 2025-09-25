## Description

A kernel-mode display miniport driver (KMD) calls **DXGKCB_ISFEATUREENABLED2** to query whether the OS has enabled a feature.

## Parameters

### `hAdapter`

[in] The adapter for which to query the feature. If the feature is a global feature, this value must be NULL.

### `pArgs`

[in/out] Pointer to a [**DXGKARGCB_ISFEATUREENABLED2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_isfeatureenabled2) structure that contains information about the feature being queried.

## Return value

**DXGKCB_ISFEATUREENABLED2** returns STATUS_SUCCESS if the operation succeeds. Otherwise, returns an appropriate NTSTATUS code.

## Remarks

For more information, see [Querying WDDM feature support and enablement](https://learn.microsoft.com/windows-hardware/drivers/display/querying-wddm-feature-support-and-enablement).

## See also

[**DXGK_FEATURE_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_feature_interface)

[**DXGKARGCB_ISFEATUREENABLED2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_isfeatureenabled2)