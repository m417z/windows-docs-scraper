# IPrintAsyncNotifyDataObject::ReleaseData

## Description

Releases the memory used by the data encapsulated in [IPrintAsyncNotifyDataObject](https://learn.microsoft.com/windows/desktop/api/prnasnot/nn-prnasnot-iprintasyncnotifydataobject).

## Return value

See [PrintAsyncNotifyError](https://learn.microsoft.com/windows/desktop/api/prnasnot/ne-prnasnot-printasyncnotifyerror) for the possible values.

For more information about COM error codes, see [Error Handling](https://learn.microsoft.com/windows/desktop/SetupApi/error-handling).

## Remarks

Listening applications must call this method when they have finished consuming the notification data.

The [IPrintAsyncNotifyDataObject](https://learn.microsoft.com/windows/desktop/api/prnasnot/nn-prnasnot-iprintasyncnotifydataobject) interface must be implemented in a way that ensures that a call of [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) does not free the object if a listening application has not finished consuming the object's data. Accordingly, if a call to **Release** occurs when an application has called [AcquireData](https://learn.microsoft.com/windows/desktop/api/prnasnot/nf-prnasnot-iprintasyncnotifydataobject-acquiredata) but has not yet called **ReleaseData**, then the object must not be freed. For this reason, we recommend that **AcquireData** use [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) to increment the object's reference count, and that **ReleaseData** decrement the count.

## See also

[Asynchronous Printing Notification Interfaces](https://learn.microsoft.com/windows/desktop/printdocs/asynchronous-notification-interfaces)

[IPrintAsyncNotifyDataObject](https://learn.microsoft.com/windows/desktop/api/prnasnot/nn-prnasnot-iprintasyncnotifydataobject)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)