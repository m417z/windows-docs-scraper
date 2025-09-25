# IPrintAsyncNotifyDataObject::AcquireData

## Description

Directs listening applications to the notification data, including the data's size and type.

## Parameters

### `ppNotificationData` [out]

A buffer containing the notification data.

### `pSize` [out]

The size of the data buffer.

### `ppSchema` [out]

A GUID pointer to the data schema.

## Return value

See [PrintAsyncNotifyError](https://learn.microsoft.com/windows/desktop/api/prnasnot/ne-prnasnot-printasyncnotifyerror) for the possible values.

For more information about COM error codes, see [Error Handling](https://learn.microsoft.com/windows/desktop/SetupApi/error-handling).

## Remarks

Applications that call this method must call [ReleaseData](https://learn.microsoft.com/windows/desktop/api/prnasnot/nf-prnasnot-iprintasyncnotifydataobject-releasedata) when they have finished consuming the notification data.

The [IPrintAsyncNotifyDataObject](https://learn.microsoft.com/windows/desktop/api/prnasnot/nn-prnasnot-iprintasyncnotifydataobject) interface must be implemented to ensure that a call of [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) does not free the object if a listening application has not finished consuming the object's data. Accordingly, if a call to **Release** occurs when an application has called **AcquireData** but has not yet called [ReleaseData](https://learn.microsoft.com/windows/desktop/api/prnasnot/nf-prnasnot-iprintasyncnotifydataobject-releasedata) , then the object must not be freed. For this reason, we recommend that **AcquireData** use [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) to increment the object's reference count and that **ReleaseData** decrement the count.

When the Print Spooler fails, it creates an [IPrintAsyncNotifyDataObject](https://learn.microsoft.com/windows/desktop/api/prnasnot/nn-prnasnot-iprintasyncnotifydataobject) object. When a listener calls **AcquireData** for this notification, *ppNotificationData* is **NULL**, the size is 0, and *ppSchema* is NOTIFICATION_RELEASE.

## See also

[Asynchronous Printing Notification Interfaces](https://learn.microsoft.com/windows/desktop/printdocs/asynchronous-notification-interfaces)

[IPrintAsyncNotifyDataObject](https://learn.microsoft.com/windows/desktop/api/prnasnot/nn-prnasnot-iprintasyncnotifydataobject)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)