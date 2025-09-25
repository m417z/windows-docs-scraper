# _D3DKMT_GET_MULTIPLANE_OVERLAY_CAPS structure

## Description

Used to get multiplane overlay capabilities.

## Members

### `hAdapter` [in]

A handle to the graphics adapter.

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology that the monitor is connected to.

### `MaxPlanes` [out]

The total number of planes currently supported.

### `MaxRGBPlanes` [out]

The number of RGB planes currently supported.

### `MaxYUVPlanes` [out]

The number of YUV planes currently supported.

### `OverlayCaps` [out]

Overlay capabilities.

### `MaxStretchFactor` [out]

The maximum stretch factor.

### `MaxShrinkFactor` [out]

The maximum shrink factor.

## Remarks

## See also