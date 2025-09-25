## Description

Currently reserved for system use. **D3DKMT_CROSSADAPTERRESOURCE_SUPPORT_TIER** enumerates the tier(s) of support provided by the driver for cross-adapter resources.

## Constants

### `D3DKMT_CROSSADAPTERRESOURCE_SUPPORT_TIER_NONE`

The driver does not provide cross-adapter resource support.

### `D3DKMT_CROSSADAPTERRESOURCE_SUPPORT_TIER_COPY`

The driver supports copying to and from cross-adapter shared resources.

### `D3DKMT_CROSSADAPTERRESOURCE_SUPPORT_TIER_TEXTURE`

The driver supports shader resource views, unordered access views, and render target views of cross-adapter row-major textures.

### `D3DKMT_CROSSADAPTERRESOURCE_SUPPORT_TIER_SCANOUT`

The driver supports scan-out of cross-adapter resources.

## Remarks

## See also