# D3DKMT_PRESENT_MULTIPLANE_OVERLAY3 structure

## Description

Contains present multiplane overlay information.

## Members

### `hAdapter`

A handle to the graphics adapter.

### `ContextCount`

The context count.

### `pContextList`

Pointer to a context list.

### `VidPnSourceId`

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology that the monitor is connected to.

### `PresentCount`

The number of present operations that can be queued for the device that is specified by *hDevice*.

### `Flags`

### `PresentPlaneCount`

The number of resources to pin.

### `ppPresentPlanes`

Pointer to an array of present planes.

### `pPostComposition`

Pointer to post composition.

### `Duration`

Per-present duration.

### `HDRMetaDataType`

The HDR metadata type.

### `HDRMetaDataSize`

The HDR metadata size.

### `pHDRMetaData`

The HDR metadata.

### `BoostRefreshRateMultiplier`

Dynamic refresh rate's boost multiplier.

## Remarks

## See also