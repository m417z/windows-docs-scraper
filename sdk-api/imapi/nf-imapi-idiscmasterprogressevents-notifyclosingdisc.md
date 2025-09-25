# IDiscMasterProgressEvents::NotifyClosingDisc

## Description

Notifies the application that it is has started closing the disc. No further notifications are sent until the burn is finished.

## Parameters

### `nEstimatedSeconds` [in]

Number of seconds from notification that IMAPI estimates it will take to close the disc.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## See also

[IDiscMasterProgressEvents](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscmasterprogressevents)