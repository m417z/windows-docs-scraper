# _D3DKMT_CHECK_MULTIPLANE_OVERLAY_PLANE2 structure

> [!NOTE] This structure has been replaced by [D3DKMT_CHECK_MULTIPLANE_OVERLAY_PLANE3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_check_multiplane_overlay_plane3).

## Description

Check multiplane overlay plane.

## Members

### `LayerIndex`

The layer index.

### `hResource`

Handle for this resource in this process.

### `CompSurfaceLuid`

The component surface LUID (locally unique identifier).

### `VidPnSourceId`

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology that the monitor is connected to.

### `PlaneAttributes`

Pointer to a D3DKMT_MULTIPLANE_OVERLAY_ATTRIBUTES2 structure that contains the plane attributes.

## Remarks

## See also