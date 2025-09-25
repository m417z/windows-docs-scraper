## Description

The **D3DKMT_CREATE_DOORBELL_FLAGS** structure specifies flags for [creating a doorbell](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedoorbell).

## Members

### `RequireSecondaryCpuVA`

UMD sets this flag on hardware that implements a secondary doorbell location. For such devices, the OS reserves another CPU virtual address for this doorbell. This address remains constant over the lifetime of the doorbell, even if the underlying physical doorbell gets disconnected.

### `ResizeRingBufferOperation`

Indication from UMD to KMD that a doorbell is being recreated for this hardware queue with a new, resized [**hRingBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedoorbell) ring buffer.

### `Reserved`

Reserved for system use.

### `Value`

An alternative way to access the structure members.

## Remarks

For more information, see [User-mode work submission](https://learn.microsoft.com/windows-hardware/drivers/display/user-mode-work-submission).

## See also

[**D3DKMT_CREATE_DOORBELL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedoorbell)

[**D3DKMTCreateDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedoorbell)