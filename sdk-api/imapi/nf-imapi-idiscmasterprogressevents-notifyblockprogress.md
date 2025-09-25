# IDiscMasterProgressEvents::NotifyBlockProgress

## Description

Notifies an application of its progress in burning a disc on the active recorder. Notifications are sent for the first and last blocks, and at points in between.

## Parameters

### `nCompleted` [in]

Number of blocks that have been burned onto a disc or track so far.

### `nTotal` [in]

Total number of blocks to be burned to finish a disc or track.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## See also

[IDiscMasterProgressEvents](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscmasterprogressevents)