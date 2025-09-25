# IDsAdminNotifyHandler::Initialize

## Description

The **IDsAdminNotifyHandler::Initialize** method is called to initialize the notification handler.

## Parameters

### `pExtraInfo` [in]

Reserved. This parameter will be **NULL**.

### `puEventFlags` [out]

Pointer to a **ULONG** value that receives a set of flags that indicate which events the notification handler should receive. This can be a combination of one or more of the following values. If this parameter receives zero, the notification handler will not receive any events.

#### DSA_NOTIFY_DEL

Notify the handler when an object is deleted.

#### DSA_NOTIFY_REN

Notify the handler when an object is renamed.

#### DSA_NOTIFY_MOV

Notify the handler when an object is moved.

#### DSA_NOTIFY_PROP

Notify the handler when a property is changed.

#### DSA_NOTIFY_ALL

Notify the handler in response to all events.

## Return value

If the method succeeds, **S_OK** is returned. If the method fails, a standard **HRESULT** value is returned.

## See also

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[IDsAdminNotifyHandler](https://learn.microsoft.com/windows/desktop/api/dsadmin/nn-dsadmin-idsadminnotifyhandler)