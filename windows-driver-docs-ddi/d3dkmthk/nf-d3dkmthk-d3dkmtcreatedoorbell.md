## Description

The **D3DKMTCreateDoorbell** function creates a GPU doorbell for a D3D hardware queue for user-mode work submission.

## Parameters

### `unnamedParam1`

[in/out] Pointer to a [**D3DKMT_CREATE_DOORBELL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_create_doorbell) structure that describes the doorbell to create.

## Return value

**D3DKMTCreateDoorbell** returns STATUS_SUCCESS when the OS successfully creates a doorbell for this hardware queue that UMD can use for work submission. Any failure return code means that the doorbell was not created and the UMD can't use it for work submission.

## Remarks

**D3DKMTCreateDoorbell** creates a doorbell object that is initialized as disconnected. UMD must call [**D3DKMTConnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtconnectdoorbell) before using this doorbell to submit commands on the hardware queue.

When UMD calls **D3DKMTCreateDoorbell**, the OS makes a corresponding call to KMD's [**DxgkDdiCreateDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdoorbell) callback in which KMD can initialize its doorbell state.

For more information, see [User-mode work submission](https://learn.microsoft.com/windows-hardware/drivers/display/user-mode-work-submission).

## See also

[**D3DKMTConnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtconnectdoorbell)

[**D3DKMT_CREATE_DOORBELL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_create_doorbell)

[**DxgkDdiConnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_connectdoorbell)

[**DxgkDdiCreateDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdoorbell)

[**D3DKMTDestroyDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtdestroydoorbell)