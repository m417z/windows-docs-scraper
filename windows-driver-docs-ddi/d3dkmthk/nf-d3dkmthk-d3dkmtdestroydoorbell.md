## Description

**D3DKMTDestroyDoorbell** destroys a doorbell.

## Parameters

### `unnamedParam1`

[in] Pointer to a [**D3DKMT_DESTROY_DOORBELL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_destroy_doorbell) structure that identifies the hardware queue whose doorbell is to be destroyed.

## Return value

**D3DKMTDestroyDoorbell** returns STATUS_SUCCESS when the OS successfully destroys the doorbell object. If **hDoorbell** points to a valid doorbell, then this call always succeeds; otherwise it returns STATUS_INVALID_PARAMETER.

## Remarks

When UMD calls **D3DKMTDestroyDoorbell**, the OS does the following:

* Removes its reference to **hRingBuffer** and to **hRingBufferControl** allocations belonging to this doorbell.
* Frees the mapping that **DoorbellStatusCPUVirtualAddress** points to.
* Frees both the user-mode and kernel-mode mappings that **DoorbellCPUVirtuslAddress** points to.
* Calls KMD's [**DxgkDdiDestroyDoorbell**] so that KMD can disconnect the physical doorbell location and destroy its doorbell objects.

The UMD must not use the handle after calling **D3DKMTDestroyDoorbell**.

For more information, see [User-mode work submission](https://learn.microsoft.com/windows-hardware/drivers/display/user-mode-work-submission).

## See also

[**D3DKMT_DESTROY_DOORBELL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_destroy_doorbell)

[**D3DKMTCreateDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedoorbell)