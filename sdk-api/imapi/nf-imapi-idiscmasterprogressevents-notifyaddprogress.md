# IDiscMasterProgressEvents::NotifyAddProgress

## Description

Notifies an application of its progress in response to calls to
[IRedbookDiscMaster::AddAudioTrackBlocks](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-iredbookdiscmaster-addaudiotrackblocks) or
[IJolietDiscMaster::AddData](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-ijolietdiscmaster-adddata). Notifications are sent for the first and last steps, and at points in between.

## Parameters

### `nCompletedSteps` [in]

Number of arbitrary steps that have been completed in adding audio or data to a staged image.

### `nTotalSteps` [in]

Total number of arbitrary steps that must be taken to add a full set of audio or data to the staged image.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## See also

[IDiscMasterProgressEvents](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscmasterprogressevents)