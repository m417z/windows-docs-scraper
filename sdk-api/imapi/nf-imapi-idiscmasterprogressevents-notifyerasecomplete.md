# IDiscMasterProgressEvents::NotifyEraseComplete

## Description

Notifies an application that a call to
[IDiscRecorder::Erase](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscrecorder-erase) has finished.

## Parameters

### `status` [in]

Status code to be returned from
[IDiscRecorder::Erase](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscrecorder-erase).

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## See also

[IDiscMasterProgressEvents](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscmasterprogressevents)