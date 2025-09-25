# _D3DKMT_FLIPQUEUEINFO structure

## Description

The D3DKMT_FLIPQUEUEINFO structure describes information about the graphics adapter's queue of flip operations that the OpenGL installable client driver (ICD) obtains by calling the [D3DKMTQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryadapterinfo) function.

## Members

### `MaxHardwareFlipQueueLength` [out]

The maximum number of flip operations that can be queued for hardware-flip queuing.

### `MaxSoftwareFlipQueueLength` [out]

The maximum number of flip operations that can be queued for software-flip queuing on hardware that supports memory mapped I/O (MMIO)-based flips.

### `FlipFlags` [out]

A [D3DKMT_FLIPINFOFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_flipinfoflags) structure that indicates, in bit-field flags, flipping capabilities.

## See also

[D3DKMTQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryadapterinfo)

[D3DKMT_FLIPINFOFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_flipinfoflags)

[D3DKMT_QUERYADAPTERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryadapterinfo)