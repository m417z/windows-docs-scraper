# D3DKMT_PRESENT_MULTIPLANE_OVERLAY structure

## Description

Contains present multiplane overlay information.

## Members

### `hDevice`

A handle to the device.

### `hContext`

A handle to the device context.

### `BroadcastContextCount`

Specifies the number of contexts.

### `BroadcastContext`

A D3DKMT_HANDLE data type that represents the broadcast context.

### `VidPnSourceId`

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology that the monitor is connected to.

### `PresentCount`

The number of present operations that can be queued for the device that is specified by *hDevice*.

### `FlipInterval`

A UINT value that specifies whether the display miniport driver natively supports the scheduling of a flip command to take effect after two, three or four vertical syncs occur.

### `Flags`

Flag options.

### `PresentPlaneCount`

The number of resources to pin.

### `pPresentPlanes`

Pointer to present planes.

### `Duration`

Per-present duration.

## Remarks

## See also