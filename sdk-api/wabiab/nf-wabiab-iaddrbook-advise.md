## Description

Registers the caller with the Windows Address Book (WAB) to receive notifications.

## Parameters

### `cbEntryID`

Reserved. Must be set to 0.

### `lpEntryID`

Reserved. Must be set to NULL.

### `ulEventMask`

Value of type ULONG that specifies the event masks. Set to **fnevObjectModified**. All other event masks will be rejected.

### `lpAdviseSink`

Pointer to an **IUnknown** interface that specifies the object invoked by the Windows Address Book (WAB) to send notifications.

### `lpulConnection`

Pointer to a variable of type ULONG that receives the connection number returned by the Windows Address Book (WAB). Use this number when calling [IAddrBook::Unadvise](https://learn.microsoft.com/windows/win32/api/wabiab/nf-wabiab-iaddrbook-unadvise).

## Return value

HRESULT

## Remarks

At this time, the Windows Address Book (WAB) only provides notifications to generic changes in the store. Clients cannot register for notifications provided per entry identifier. When the Windows Address Book (WAB) store changes, the Windows Address Book (WAB) invokes the **IMAPIAdviseSink::OnNotify** method on the *lpAdviseSink* pointer passed into this function.

The **NOTIFICATION** structure passed to the **OnNotify method has the following valid members:

```
<![CDATA[Notification.ulEventType = fnevObjectModified
Notification.info.obj.ulObjType = MAPI_ADDRBOOK]]>
```
All other members in the structure will be NULL or zero. Clients must use this notification only for refreshing their UI. Detailed information about modifications to individual objects within the Windows Address Book (WAB) is not currently available.

## See also