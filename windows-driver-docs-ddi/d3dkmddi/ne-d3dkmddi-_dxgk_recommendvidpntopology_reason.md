# _DXGK_RECOMMENDVIDPNTOPOLOGY_REASON enumeration

## Description

The **DXGK_RECOMMENDVIDPNTOPOLOGY_REASON** enumeration indicates the reason for calling the display miniport driver's [DxgkDdiRecommendVidPnTopology](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendvidpntopology) function.

## Constants

### `DXGK_RVT_UNINITIALIZED`

Indicates that a variable of type [DXGK_RECOMMENDVIDPNTOPOLOGY_REASON](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_recommendvidpntopology_reason) has not yet been assigned a meaningful value.

### `DXGK_RVT_INITIALIZATION_NOLKG`

Indicates that the call is being made during the initialization of the display adapter after an attempt to use the last known good VidPN topology failed.

### `DXGK_RVT_AUGMENTATION_NOLKG`

 Indicates that the call is being made during the VidPN topology augmentation by the display mode manager (DMM) after an attempt to use the last known good VidPN topology failed.

### `DXGK_RVT_AUGMENTATION_LKGOVERRIDE`

Indicates that the call is being made during the VidPN topology augmentation by the display mode manager (DMM), giving the display miniport driver a chance to override the last known good VidPN topology.

### `DXGK_RVT_INITIALIZATION_LKGOVERRIDE`

Indicates that the call is being made during the initialization of the display adapter, giving the display miniport driver a chance to override the last known good VidPN topology.