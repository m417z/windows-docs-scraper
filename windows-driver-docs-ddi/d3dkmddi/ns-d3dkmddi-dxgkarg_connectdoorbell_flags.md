## Description

The **DXGKARG_CONNECTDOORBELL_FLAGS** structure specifies doorbell connection flags for [**DxgkDdiConnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_connectdoorbell).

## Members

### `RequireSecondaryAddress`

If UMD [created this doorbell](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedoorbell) with the **RequireSecondaryCpuVA** flag, then *Dxgkrnl* sets this corresponding **RequireSecondaryAddress** flag to inform KMD that this doorbell requires two physical addresses.

### `Reserved`

Reserved; set to zero.

### `Value`

An alternative way to access the structure members.

## Remarks

For more information, see [User-mode work submission](https://learn.microsoft.com/windows-hardware/drivers/display/user-mode-work-submission).

## See also

[**D3DKMT_CREATE_DOORBELL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedoorbell)

[**DXGKARG_CONNECTDOORBELL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_connectdoorbell)

[**DxgkDdiConnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_connectdoorbell)