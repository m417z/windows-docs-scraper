# IDiscMaster::RecordDisc

## Description

Burns the staged image to media in the active disc recorder.

## Parameters

### `bSimulate` [in]

Indicates whether the media is burned. If this parameter is **TRUE**, media in the active disc recorder is not actually burned. Instead, a simulated burn is performed. The simulation is a good test of a disc recorder, because most of the operations are performed as in a real burn. If this parameter is **FALSE**, then the media in the recorder is actually burned.

### `bEjectAfterBurn` [in]

Indicates whether to eject the media after the burn. If this parameter is **TRUE**, the media is ejected. If this parameter is **FALSE**, the media is not ejected.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## Remarks

This method returns when the burn is complete, although progress callbacks are made if registered with the
[ProgressAdvise](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscmaster-progressadvise) method. Any errors cause this method to return, with little or no corrective action on the part of this method.

The staged image data is not valid after a call to
**RecordDisc**. This allows the application to perform either a simulated or actual burn of the media. For security, the contents of the stash file are cleared automatically after successful completion of the first call to this method. A disc must be restaged to burn it again.

The
**RecordDisc** method expects to work with blank media for audio. Otherwise, the media may need to be erased (for example, CD-RW media in a CD-RW drive). See
[IDiscRecorder::Erase](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscrecorder-erase).

The
[SetActiveDiscRecorder](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscmaster-setactivediscrecorder) method determines if there is an IMAPI multi-session disc in the active drive upon setting. If so, IMAPI goes into multi-session mode automatically. If in multi-session mode and a call is made to
**RecordDisc**, the same disc that established multi-session mode must be in the active recorder or an error code of IMAPI_E_WRONGDISC will be returned.

## See also

[IDiscMaster](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscmaster)