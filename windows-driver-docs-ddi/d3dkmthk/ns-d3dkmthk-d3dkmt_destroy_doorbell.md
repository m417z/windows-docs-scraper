## Description

The **D3DKMT_DESTROY_DOORBELL** structure identifies the doorbell that [**D3DKMTDestroyDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtdestroydoorbell) should destroy.

## Members

### `hDoorbell`

[in] UM handle of the doorbell to be destroyed. This handle was returned in a prior call to [**D3DKMTCreateDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedoorbell).

## Remarks

For more information, see [User-mode work submission](https://learn.microsoft.com/windows-hardware/drivers/display/user-mode-work-submission).

## See also

[**D3DKMTCreateDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedoorbell)

 [**D3DKMTCreateHwQueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatehwqueue)

[**D3DKMTDestroyDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtdestroydoorbell)