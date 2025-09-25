# IDiscMaster::SetActiveDiscRecorder

## Description

Selects an active disc recorder. The active disc recorder is the recorder where a burn will occur when
[RecordDisc](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscmaster-recorddisc) is called.

## Parameters

### `pRecorder` [in]

Pointer to the
[IDiscRecorder](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscrecorder) interface of a disc recorder object. This pointer should have been returned by a previous call to
[EnumDiscRecorders](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscmaster-enumdiscrecorders).

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## Remarks

**SetActiveDiscRecorder** must be called after the media to be used has been inserted, and before calling
[IJolietDiscMaster::AddData](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-ijolietdiscmaster-adddata).

Selecting a recorder while in an active Joliet format will cause IMAPI to read information from the currently installed recorder disc. If this disc is a previous IMAPI Joliet disc and has space for another session, IMAPI automatically sets itself to multi-session mode. This disc must be in the active recorder when
[RecordDisc](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscmaster-recorddisc) is called.

The **MaxWriteSpeed** property is updated when this method is called. The default setting is the highest write speed.

## See also

[IDiscMaster](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscmaster)