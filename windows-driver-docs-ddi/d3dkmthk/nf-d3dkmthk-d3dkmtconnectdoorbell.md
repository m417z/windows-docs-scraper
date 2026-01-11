## Description

**D3DKMTConnectDoorbell** connects (or reconnects) a [previously created doorbell](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedoorbell) to a hardware queue.

## Parameters

### `unnamedParam1`

[in] Pointer to a [**D3DKMT_CONNECT_DOORBELL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_connect_doorbell) structure that describes the doorbell to connect.

## Return value

**D3DKMTConnectDoorbell** returns STATUS_SUCCESS when the OS successfully connects the doorbell to the hardware queue and UMD can use this doorbell for work submission. Typically this call should not fail; however, a failure code would be from GPU lost or stop kinds of irrecoverable scenarios.

## Remarks

Each time the UMD submits new work to the hardware queue and rings the doorbell, it must read the [**DoorbellStatusCPUVirtualAddress**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_create_doorbell) to check whether the doorbell ring succeeded. On failure, UMD must call **D3DKMTConnectDoorbell** to reconnect the doorbell and then try the submission again.

A doorbell can be disconnected for several reasons:

* When a [doorbell is created](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedoorbell), the OS initializes it in a "disconnected" state, and only connects it when UMD calls **D3DKMTConnectDoorbell** for the first time.
* The doorbell was "victimized" on hardware that supports the dedicated doorbell model. That is, this hardware queue's physical doorbell was assigned to another hardware queue. This reassignment is likely because there are more hardware queues created on the GPU than physical doorbells.
* The doorbell was disconnected as a part of suspending the hardware queue or powering down the GPU.

When UMD calls **D3DKMTConnectDoorbell** to connect the doorbell assigned to a hardware queue, the OS makes a corresponding [**DxgkDdiConnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdoorbell) call to KMD, so that the KMD can find a physical doorbell, assign it to this hardware queue, and make the required connections between the hardware queue, doorbell, GPU scheduler and so forth.

For more information, see [User-mode work submission](https://learn.microsoft.com/windows-hardware/drivers/display/user-mode-work-submission).

## See also

[**D3DKMT_CONNECT_DOORBELL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_connect_doorbell)

[**D3DKMTCreateDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_create_doorbell)

[**DxgkDdiConnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdoorbell)