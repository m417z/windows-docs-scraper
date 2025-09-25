## Description

**D3DKMTNotifyWorkSubmission** notifies the kernel-mode display driver (KMD) that the user-mode display driver (UMD) has submitted work to the GPU.

## Parameters

### `unnamedParam1`

Pointer to a [**D3DKMT_NOTIFY_WORK_SUBMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_notify_work_submission) structure that identifies the hardware queue on which the work was submitted.

## Return value

**D3DKMTNotifyWorkSubmission** returns STATUS_SUCCESS if it succeeds in pinging KMD. Otherwise, it returns an appropriate error code such as STATUS_INVALID_PARAMETER if an invalid hardware queue or flag are specified.

## Remarks

In the [user-mode work submission](https://learn.microsoft.com/windows-hardware/drivers/display/user-mode-work-submission) model, KMD isn't involved in work submission and so isn't aware when new work is submitted on a HWQueue. This low latency work submission path is the main motivation of the model. However, there are certain niche scenarios and hardware limitations when KMD needs to be notified whenever work is submitted on a HWQueue. For example, a GPU hardware scheduler requires KMD to switch the hardware runlist from normal to realtime when a realtime context submits work. If KMD isn't involved in work submission then it can't trigger the runlist switch immediately, which results in delaying the realtime work execution.

To accommodate this need, KMD can specify the doorbell connection status as D3DDDI_DOORBELL_STATUS_CONNECTED_NOTIFY at [doorbell creation time](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedoorbell). Whenever UMD sees this doorbell status, it adjusts its work submission workflow such that after writing a new command and ringing the doorbell, it calls into the kernel using **D3DKMTNotifyWorkSubmission**. *Dxgkrnl* forwards this call to KMD using [**DxgkDdiNotifyWorkSubmission**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_notifyworksubmission).

**D3DKMTNotifyWorkSubmission** is a simple ping from UMD to *Dxgkrnl* to KMD, notifying the latter that new work has been submitted on a particular HWQueue so that KMD can initiate specific actions such as switching a runlist to realtime.

KMD can also request notification dynamically after doorbell creation. If KMD detects a condition where it should be notified of work submission on this hardware queue, then it can first disconnect the doorbell by calling *Dxgkrnl*'s [**DxgkCbDisconnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_disconnectdoorbell) with status D3DDDI_DOORBELL_STATUS_DISCONNECTED_RETRY. Later, when UMD tries to reconnect the doorbell, KMD can make the connection with status D3DDDI_DOORBELL_STATUS_CONNECTED_NOTIFY.

Drivers should use this mechanism in very specific and infrequent scenarios because it involves a round trip from UMD to KMD on every work submission, and if it is used for broad scenarios then it defeats the purpose of a low latency user mode submission model.

For more information, see [User-mode work submission](https://learn.microsoft.com/windows-hardware/drivers/display/user-mode-work-submission).

## See also

[**D3DKMT_NOTIFY_WORK_SUBMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_notify_work_submission)

[**D3DKMTCreateDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedoorbell)

[**DxgkCbDisconnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_disconnectdoorbell)

[**DxgkDdiNotifyWorkSubmission**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_notifyworksubmission)