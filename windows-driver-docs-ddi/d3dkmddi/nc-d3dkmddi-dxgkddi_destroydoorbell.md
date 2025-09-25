## Description

The **DxgkDdiDestroyDoorbell** function destroys a previously created doorbell object.

## Parameters

### `pArgs`

[in/out] Pointer to a [**DXGKARG_DESTROYDOORBELL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_destroydoorbell) structure that describes the doorbell to destroy.

## Return value

**DxgkDdiDestroyDoorbell** must succeed and return STATUS_SUCCESS.

## Remarks

The OS calls KMD's **DxgkDdiDestroyDoorbell** when UMD calls [**D3DKMTDestroyDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtdestroydoorbell).

KMD should disconnect the physical doorbell location and destroy its doorbell objects.

UMD must not use the handle after calling **D3DKMTDestroyDoorbell**.

For more information, see [User-mode work submission](https://learn.microsoft.com/windows-hardware/drivers/display/user-mode-work-submission).

## See also

[**DXGKARG_DESTROYDOORBELL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_destroydoorbell)

[**DxgkddiCreateDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdoorbell)