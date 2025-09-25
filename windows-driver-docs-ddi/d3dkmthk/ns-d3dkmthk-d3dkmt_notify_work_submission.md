## Description

The **D3DKMT_NOTIFY_WORK_SUBMISSION** structure is passed to [**D3DKMTNotifyWorkSubmission**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtnotifyworksubmission) to notify the kernel-mode display driver (KMD) that the user-mode display driver (UMD) has submitted work to the GPU.

## Members

### `hDoorbell`

[in] UM handle of the doorbell. This handle was returned in a prior call to [**D3DKMTCreateDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedoorbell).

### `Flags`

[in] A [**D3DKMT_NOTIFY_WORK_SUBMISSION_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_notify_work_submission_flags) structure with work submission flags.

## Remarks

For more information, see [User-mode work submission](https://learn.microsoft.com/windows-hardware/drivers/display/user-mode-work-submission).

## See also

[**D3DKMT_NOTIFY_WORK_SUBMISSION_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_notify_work_submission_flags)

[**D3DKMTNotifyWorkSubmission**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtnotifyworksubmission)