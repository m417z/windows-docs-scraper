# IDiscMaster::ClearFormatContent

## Description

Clears the contents of an unburned image (the current stash file).

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## Remarks

The stash file is an internal structure that is used to stage a disc before recording it to media.

[SetActiveDiscRecorder](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscmaster-setactivediscrecorder) determines if there is an IMAPI multi-session disc in the active drive. If so, IMAPI enters multi-session mode automatically. Using
**ClearFormatContent** after multi-session mode had been established causes IMAPI to return to single-session mode. This means that a blank disc is required for a
[RecordDisc](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscmaster-recorddisc) burn.

**Caution** Use care when calling this method. There is no confirmation and no recovery. If an application fills the image file with data, then calls this method, the data is gone.

## See also

[IDiscMaster](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscmaster)