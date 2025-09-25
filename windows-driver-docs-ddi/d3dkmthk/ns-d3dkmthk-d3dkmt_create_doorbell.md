## Description

The **D3DKMT_CREATE_DOORBELL** structure contains parameters for [**D3DKMTCreateDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedoorbell).

## Members

### `hHwQueue`

[in] UMD handle of the hardware queue object created in a prior call to [**D3DKMTCreateHwQueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatehwqueue). This handle identifies the hardware queue for which a doorbell needs to be assigned.

### `hRingBuffer`

[in] UMD handle to a ring buffer allocation that UMD [previously created](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation). The allocation must be GPU visible and already resident. *Dxgkrnl* passes along the GPU virtual address (VA) and size of this allocation to KMD in a corresponding [**DxgkDdiCreateDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdoorbell) call. The [**ResizeRingBufferOperation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_create_doorbell_flags) flag is a hint from UMD to KMD that a doorbell is being recreated for this hardware queue with a new, resized ring buffer.

### `hRingBufferControl`

[in/optional] UMD handle to a ring buffer control allocation [previously created](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation) by UMD. UMD and KMD can use this allocation as a control area to store ring buffer read/write pointer locations if required. The allocation must be GPU visible and already resident when UMD calls **D3DKMTCreateDoorbell**. *Dxgkrnl* passes along the GPU VA and size of this allocation to KMD in a corresponding [**DxgkDdiCreateDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdoorbell) call.

### `Flags`

[in/optional] A bit field of [**D3DKMT_CREATE_DOORBELL_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_create_doorbell_flags) values specifying the doorbell creation flags.

### `PrivateDriverDataSize`

[in] Size of the private driver data that **pPrivateDriverData** points to, in bytes.

### `PrivateDriverData`

[in/out] Pointer to a buffer that is private to the driver. The size of this buffer is specified by **PrivateDriverDataSize**. The maximum buffer size allowed is D3DDDI_DOORBELL_PRIVATEDATA_MAX_BYTES_WDDM3_1 bytes.

### `DoorbellCPUVirtualAddress`

[out] Pointer to the CPU VA (both read/write) reserved by the OS for this doorbell. UMD will write a specific value to this address, effectively "ringing the doorbell" to notify the GPU scheduler of a new work submission on the hardware queue. This address remains constant over the lifetime of the doorbell, even if the underlying physical doorbell gets disconnected. The UMD should always use this address to write/read to this doorbell.

### `DoorbellSecondaryCPUVirtualAddress`

[out/optional] Pointer to a secondary CPU VA (both read/write) reserved by the OS for this doorbell.

On hardware that implements a secondary doorbell location the UMD sets the [**RequireSecondaryCpuVA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_create_doorbell_flags) flag. For such devices, the OS will reserve another CPU VA for this doorbell. Over the lifetime of the doorbell, this address will remain constant even if the underlying physical doorbell gets disconnected.

### `DoorbellStatusCPUVirtualAddress`

[out] Pointer to the CPU VA of the doorbell status. The value at this address indicates to the UMD whether the doorbell assigned to this hardware queue is currently connected. Each time the UMD submits new work to the queue and rings the doorbell, it must check this value to determine whether the doorbell ring succeeded. If the ring failed, UMD must call [**D3DKMTConnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtconnectdoorbell) to reconnect the doorbell and then try submitting the work again.

The OS allocates and writes this 64-bit doorbell status memory, maps it into the process’s address space, and gives its user-mode CPU VA to the UMD to read from. Hence, UMD should read the 64-bit value stored in this address to obtain the doorbell status. The value of this address can be one of the [**D3DDDI_DOORBELL_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_doorbellstatus) enum values.

This address remains constant over the lifetime of the doorbell, even if the underlying physical doorbell gets disconnected. The UMD should always use this address to read the doorbell's status.

Only the OS writes to and updates this status memory:

* On successful return from [**DxgkDdiConnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_connectdoorbell), the OS writes the status as D3DDDI_DOORBELL_STATUS_CONNECTED.
* If the OS disconnects the doorbell as part of suspending the hardware queue or powering down the GPU, it calls KMD's **DxgkDdiDisconnectDoorbell** and then writes the status as D3DDDI_DOORBELL_STATUS_DISCONNECTED_RETRY.
* If the KMD wants to disconnect the doorbell for any reason, it calls the [**DxgkDisconnectDoorbellCB**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_disconnectdoorbell) callback to inform the OS. KMD provides D3DDDI_DOORBELL_STATUS as the status, which the OS writes to this status page.
* In GPU lost or stopped scenarios, the OS writes D3DDDI_DOORBELL_STATUS_DISCONNECTED_ABORT as the status.

### `HwQueueProgressFenceLastQueuedValueCPUVirtualAddress`

[out] CPU VA of the location where the UMD will write the newly queued progress fence value every time a new command buffer is appended to the ring buffer.

### `hDoorbell`

[out] Runtime handle to the newly created doorbell object.

## Remarks

For more information, see [User-mode work submission](https://learn.microsoft.com/windows-hardware/drivers/display/user-mode-work-submission).

## See also

[**D3DKMT_CREATE_DOORBELL_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_create_doorbell_flags)

[**D3DKMTConnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtconnectdoorbell)

[**D3DKMTCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation)

[**D3DKMTCreateDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedoorbell)

[**DxgkDdiConnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_connectdoorbell)

[**DxgkDdiCreateDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdoorbell)