# IDiscMaster::ProgressAdvise

## Description

Registers an application for progress notifications.

## Parameters

### `pEvents` [in]

Pointer to an
[IDiscMasterProgressEvents](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscmasterprogressevents) interface that receives the progress notifications.

### `pvCookie` [out]

Uniquely identifies this registration. Save this value because it will be needed by the
[ProgressUnadvise](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscmaster-progressunadvise) method.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## See also

[IDiscMaster](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscmaster)