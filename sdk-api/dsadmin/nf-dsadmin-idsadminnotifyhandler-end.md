# IDsAdminNotifyHandler::End

## Description

The **IDsAdminNotifyHandler::End** method is called after the notification event has occurred. This method is called even if the notification process is canceled.

## Return value

The return value from this method is ignored.

## Remarks

This method provides the opportunity for the notification handler to free any memory allocated during the [IDsAdminNotifyHandler::Begin](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadminnotifyhandler-begin) or [IDsAdminNotifyHandler::Notify](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadminnotifyhandler-notify) methods.

## See also

[IDsAdminNotifyHandler](https://learn.microsoft.com/windows/desktop/api/dsadmin/nn-dsadmin-idsadminnotifyhandler)

[IDsAdminNotifyHandler::Begin](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadminnotifyhandler-begin)

[IDsAdminNotifyHandler::Notify](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadminnotifyhandler-notify)