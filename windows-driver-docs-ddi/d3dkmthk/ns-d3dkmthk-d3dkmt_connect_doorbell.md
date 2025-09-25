## Description

The **D3DKMT_CONNECT_DOORBELL** structure describes the doorbell that [**D3DKMTConnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtconnectdoorbell) should connect to a hardware queue.

## Members

### `hDoorbell`

[in] UMD handle of the doorbell to be connected. This handle was returned in a prior call to [**D3DKMTCreateDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedoorbell).

### `Flags`

[in] A [**D3DKMT_CONNECT_DOORBELL_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_connect_doorbell_flags) value that specifies how to connect the doorbell to the hardware queue. No flags are currently defined.

## Remarks

For more information, see [User-mode work submission](https://learn.microsoft.com/windows-hardware/drivers/display/user-mode-work-submission).

## See also

[**D3DKMTConnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtconnectdoorbell)

[**D3DKMTCreateHwQueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatehwqueue)