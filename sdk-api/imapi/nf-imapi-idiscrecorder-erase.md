# IDiscRecorder::Erase

## Description

Attempts to erase the CD-RW media if this is a CD-RW disc recorder. Both full and quick erases are supported.

## Parameters

### `bFullErase` [in]

Indicates the erase type. If this parameter is **FALSE**, a quick erase is performed. If this parameter is **TRUE**, a full erase is performed.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## Remarks

Erasing a disc can be a very lengthy operation (sometimes in excess of an hour). To receive an erase completion notification, use [IDiscMasterProgressEvents::NotifyEraseComplete](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscmasterprogressevents-notifyerasecomplete).

The quick option erases only the PMA, first session TOC, and the pre-gap of the first track. This erases a disc quickly (between 1 and 2 minutes depending on recorder speed), but the program area will still contain user data. A full erase, on the other hand, erases the entire disc.

## See also

[IDiscRecorder](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscrecorder)