# _D3DKMT_SET_COLORSPACE_TRANSFORM structure

## Description

Used to set the color space transform.

## Members

### `AdapterLuid`

A LUID that serves as an identifier for the device.

### `VidPnTargetId`

The zero-based identification number of the video present target in a path of a video present network (VidPN) topology.

### `Type`

The type of color space.

### `Size`

The size of the color space transform.

### `pColorSpaceTransform`

Pointer to a [D3DKMDT_3x4_COLORSPACE_TRANSFORM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dkmdt_3x4_colorspace_transform) structure.