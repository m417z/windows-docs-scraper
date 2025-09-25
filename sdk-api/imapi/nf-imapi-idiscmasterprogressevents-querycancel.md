# IDiscMasterProgressEvents::QueryCancel

## Description

Checks whether an
[AddData](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-ijolietdiscmaster-adddata),
[AddAudioTrackBlocks](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-iredbookdiscmaster-addaudiotrackblocks), or
[RecordDisc](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscmaster-recorddisc) operation should be canceled.

## Parameters

### `pbCancel` [out]

If this parameter is **TRUE**, cancel the burn. If this parameter is **FALSE**, continue the burn.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## See also

[IDiscMasterProgressEvents](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscmasterprogressevents)