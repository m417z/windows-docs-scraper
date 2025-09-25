## Description

The OS calls KMD's **DxgkDdiCreateDoorbell** callback function to create a doorbell for a hardware queue.

## Parameters

### `pArgs`

[in/out] Pointer to a [**DXGKARG_CREATEDOORBELL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_createdoorbell) structure that describes the doorbell.

## Return value

**DxgkDdiCreateDoorbell** returns STATUS_SUCCESS if KMD was able to successfully create its doorbell object for the specified hardware queue, and UMD can use this doorbell for work submission. Otherwise, it returns an appropriate NTSTATUS error code. UMD can't use the doorbell for work submission if KMD returns any failure code.

## Remarks

When UMD calls [**D3DKMTCreateDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedoorbell) to create a doorbell for a hardware queue, the OS makes a corresponding **DxgkDdiCreateDoorbell** call to KMD so that KMD can initialize its doorbell structures.

KMD's **DxgkDdiCreateDoorbell** function should only create and initialize its doorbell data structures. It should not assign a physical doorbell location to this doorbell object yet as that is done during a subsequent call to [**DxgkDdiConnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_connectdoorbell). This lazy assignment ensures that a physical doorbell is not used up during hardware queue and doorbell creation, only to go wasted in the event that UMD never submits commands to it or starts submitting commands at a later time. In this way, physical doorbells are used only when actually required.

For more information, see [User-mode work submission](https://learn.microsoft.com/windows-hardware/drivers/display/user-mode-work-submission).

## See also

[**DXGKARG_CREATEDOORBELL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_createdoorbell)

[**D3DKMTCreateDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedoorbell)

[**DxgkDdiConnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_connectdoorbell)

[**DxgkDdiDestroyDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_destroydoorbell)