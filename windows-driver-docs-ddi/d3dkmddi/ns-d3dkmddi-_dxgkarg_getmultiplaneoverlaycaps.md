# _DXGKARG_GETMULTIPLANEOVERLAYCAPS structure

## Description

Arguments to the [DxgkDdiGetMultiPlaneOverlayCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getmultiplaneoverlaycaps) function.

## Members

### `VidPnSourceId` [in]

Indicates the VidPn source for which we are querying multiplane overlay capabilities.

### `MaxPlanes` [out]

Indicates the total number of planes, including the DWM's primary, that can be supported simultaneously.

### `MaxRGBPlanes` [out]

Indicates the total number of RGB planes, including the DWM’s primary, that can be supported simultaneously.

### `MaxYUVPlanes` [out]

Indicates the total number of YUV planes that can be supported simultaneously.

### `OverlayCaps` [out]

A [DXGK_MULTIPLANEOVERLAYCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplaneoverlaycaps) structure indicating the plane capabilities.

### `MaxStretchFactor` [out]

Indicates the maximum stretch factor that can be applied to a plane.

### `MaxShrinkFactor` [out]

Indicates the maximum shrink factor that can be applied to a plane.