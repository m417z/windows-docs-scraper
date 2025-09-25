# IDsAdminNotifyHandler::Notify

## Description

The **IDsAdminNotifyHandler::Notify** method is called for each object after the confirmation dialog box has been displayed and the notification handler is selected in the confirmation dialog box.

## Parameters

### `nItem` [in]

Contains the index of the item in the **aObjects** member of the [DSOBJECTNAMES](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-dsobjectnames) structure supplied in the [IDsAdminNotifyHandler::Begin](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadminnotifyhandler-begin) method.

### `uFlags` [in]

Contains the flags supplied by the notification handler in the [IDsAdminNotifyHandler::Begin](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadminnotifyhandler-begin) method.

## Return value

The return value from this method is ignored.

## See also

[DSOBJECTNAMES](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-dsobjectnames)

[IDsAdminNotifyHandler](https://learn.microsoft.com/windows/desktop/api/dsadmin/nn-dsadmin-idsadminnotifyhandler)

[IDsAdminNotifyHandler::Begin](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadminnotifyhandler-begin)