## Description

Currently reserved for system use. The **D3DKMT_CROSSADAPTERRESOURCE_SUPPORT** structure indicates the cross adapter resource support provided by a display driver.

## Members

### `SupportTier`

A [**D3DKMT_CROSSADAPTERRESOURCE_SUPPORT_TIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-d3dkmt_crossadapterresource_support_tier) value that describes the tier(s) of support provided by the driver for cross-adapter resources.

## Remarks

The tiers of support for cross-adapter resources are:

* Copying to and from cross-adapter resources (tier 1)
* Texturing from (tier 2)
* Scan-out (tier 3)

Each higher tier of support must imply and guarantee the support tiers below it. For example, to claim support for scan-out of cross-adapter resources, the driver must also support texturing and copy, too (D3DKMT_CROSSADAPTERRESOURCE_SUPPORT_TIER_COPY && D3DKMT_CROSSADAPTERRESOURCE_SUPPORT_TIER_TEXTURE && D3DKMT_CROSSADAPTERRESOURCE_SUPPORT_TIER_SCANOUT).

## See also