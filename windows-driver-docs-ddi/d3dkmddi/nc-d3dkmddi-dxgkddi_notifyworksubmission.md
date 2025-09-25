## Description

The **DxgkDdiNotifyWorkSubmission** function notifies KMD that UMD has submitted new work.

## Parameters

### `pArgs`

[in] Pointer to a [**DXGKARG_NOTIFYWORKSUBMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_notifyworksubmission) structure that identifies the hardware queue on which the work was submitted.

## Return value

**DxgkDdiNotifyWorkSubmission** must succeed and return STATUS_SUCCESS.

## Remarks

In the user-mode work submission model, KMD isn't involved in work submission and so isn't typically aware when new work is submitted on a hardware queue. This factor is the main motivation of a low latency work submission path. However, there are certain niche scenarios and hardware limitations in which KMD needs to be notified whenever work is submitted on a hardware queue. For example, a GPU hardware scheduler requires KMD to switch the hardware runlist from normal to real time when a real time context submits work. If KMD isn't involved in work submission then it can't trigger the runlist switch immediately, which results in delaying the real time work execution.

To solve this problem, KMD can specify the doorbell connection status as D3DDDI_DOORBELL_STATUS_CONNECTED_NOTIFY at [doorbell creation time](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdoorbell). Whenever UMD sees this doorbell status, it adjusts its work submission workflow such that after writing a new command and ringing the doorbell, it calls into the kernel using [**D3DKMTNotifyWorkSubmission**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtnotifyworksubmission). *Dxgkrnl* forwards this call to KMD via **DxgkDdiNotifyWorkSubmission**.

**DxgkDdiNotifyWorkSubmission** is a simple ping from UMD to *Dxgkrnl* to KMD, notifying the latter that new work has been submitted on a particular hardware queue, thus allowing KMD to initiate specific actions such as switching the runlist to real time.

KMD can also request notification dynamically after doorbell creation. If KMD detects a condition where it should be notified of work submission on this hardware queue, then it can first disconnect the doorbell by calling [**DxgkCbDisconnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_disconnectdoorbell) with status D3DDDI_DOORBELL_STATUS_DISCONNECTED_RETRY. Later, when UMD tries to reconnect the doorbell, KMD can make the connection with status D3DDDI_DOORBELL_STATUS_CONNECTED_NOTIFY.

Drivers should use this mechanism in very specific and infrequent scenarios because it involves a round trip from UMD to KMD on every work submission, and if it is used for broad scenarios then it defeats the purpose of a low latency user mode submission model.

For more information, see [User-mode work submission](https://learn.microsoft.com/windows-hardware/drivers/display/user-mode-work-submission).

## See also

[**DXGKARG_NOTIFYWORKSUBMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_notifyworksubmission)

[**DxgkDdiCreateDoorbell](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdoorbell)

[**DxgkCbDisconnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_disconnectdoorbell)