# IDsAdminNotifyHandler::Begin

## Description

The **IDsAdminNotifyHandler::Begin** method is called when an event that the notification handler has requested is occurring. The notification handler specifies the events to receive notifications for when [IDsAdminNotifyHandler::Initialize](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadminnotifyhandler-initialize) is called.

## Parameters

### `uEvent` [in]

Contains a value the specifies the type of event that is occurring. This can be one of the following values.

#### DSA_NOTIFY_DEL

An object is deleted.

#### DSA_NOTIFY_REN

An object is renamed.

#### DSA_NOTIFY_MOV

An object is moved to another container.

#### DSA_NOTIFY_PROP

One or more properties of an object is modified.

### `pArg1` [in]

Pointer to an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface that supports the [CFSTR_DSOBJECTNAMES](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/cfstr-dsobjectnames-clipboard-format) clipboard format. The contents of the data object will vary depending on the value of *uEvent*. For more information, see the Remarks section.

### `pArg2` [in]

Pointer to an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface that supports the [CFSTR_DSOBJECTNAMES](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/cfstr-dsobjectnames-clipboard-format) clipboard format. The value of this parameter and the contents of the data object will vary depending on the value of *uEvent*. For more information, see the Remarks section.

### `puFlags` [out]

Pointer to a **ULONG** value that receives a set of flags that modify the behavior of the notification handler in the notification confirmation dialog box. This can be zero or a combination of one or more of the following values.

#### DSA_NOTIFY_FLAG_ADDITIONAL_DATA

If this flag is set, the entry for this notification handler in the confirmation dialog box is selected. If this flag is not set, the entry for this notification handler in the confirmation dialog box is not selected.

#### DSA_NOTIFY_FLAG_FORCE_ADDITIONAL_DATA

If this flag is set, the entry for this notification handler in the confirmation dialog box is disabled and the user cannot change the selection state.

### `pBstr` [out]

Pointer to a **BSTR** that receives a string that contains the name and/or description of the notification handler. This string is displayed in the confirmation dialog box. This string must be allocated by calling the [SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) function. The caller must free this string when it is no longer required. If this parameter receives **NULL** or an empty string, the notification handler is not added to the confirmation dialog box and [IDsAdminNotifyHandler::Notify](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadminnotifyhandler-notify) is not called.

## Return value

If the method succeeds,
**S_OK** is returned. If the method fails, a standard **HRESULT** value is returned.

## Remarks

The value and contents of *pArg1* and *pArg2* vary depending upon the event processed as indicated by *uEvent*. The following list explains what *pArg1* and *pArg2* will contain for each different event type.

| *uEvent* | *pArg1* | *pArg2* |
| --- | --- | --- |
| **DSA_NOTIFY_DEL** | Contains the object deleted. | Not used. This will be **NULL**. |
| **DSA_NOTIFY_REN** | Contains the previous name of the object. | Contains the new name of the object. |
| **DSA_NOTIFY_MOV** | Contains the container that the object is moved from. | Contains the container that the object is moved to. |
| **DSA_NOTIFY_PROP** | Contains the object for which the properties have changed. | Not used. This will be **NULL**. |

## See also

[CFSTR_DSOBJECTNAMES](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/cfstr-dsobjectnames-clipboard-format)

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[IDsAdminNotifyHandler](https://learn.microsoft.com/windows/desktop/api/dsadmin/nn-dsadmin-idsadminnotifyhandler)

[IDsAdminNotifyHandler::Initialize](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadminnotifyhandler-initialize)

[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring)