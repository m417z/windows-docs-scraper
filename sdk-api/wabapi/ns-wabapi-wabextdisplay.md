# WABEXTDISPLAY structure

## Description

Do not use. Used by the Windows Address Book (WAB) to initialize user's [IContextMenu Interface](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu) and [IShellPropSheetExt Interface](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellpropsheetext) implementations.

## Members

### `cbSize`

Type: **ULONG**

Not used.

### `lpWABObject`

Type: **LPWABOBJECT**

Pointer to an [IWABObject](https://learn.microsoft.com/windows/desktop/api/wabapi/nn-wabapi-iwabobject) interface that specifies the object to use for calling the **IWABObject** memory allocation methods. These methods allocate any memory that you pass back to the WAB and that you expect the WAB to free or use. You can also use this pointer to call any of the other **IWABObject** methods.

### `lpAdrBook`

Type: **LPADRBOOK**

Pointer to an [IAddrBook](https://learn.microsoft.com/windows/desktop/api/wabiab/nn-wabiab-iaddrbook) interface that specifies the object to use for calling any of the standard WAB **IAddrBook** methods.

### `lpPropObj`

Type: **LPMAPIPROP**

Pointer to an [IMailUser : IMAPIProp](https://learn.microsoft.com/previous-versions/office/developer/office-2007/cc839725(v=office.12)) object. This interface is relevant for both [IShellPropSheetExt Interface](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellpropsheetext) and [IContextMenu Interface](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu) implementations. For IShellPropSheetExt Interface implementations, **lpPropObj** contains the actual object being displayed. It can be either an IMailUser : IMAPIProp or [IDistList : IMAPIContainer](https://learn.microsoft.com/previous-versions/office/developer/office-2007/cc842393(v=office.12)) object. To determine which object **lpPropObj** is, query for its PR_OBJECT_TYPE property. You can retrieve properties from this object to populate your extension property sheets.

For [IContextMenu Interface](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu) implementations, **lpPropObj** contains a valid object; however, this object does not have any properties associated with it.
You can call the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on this object to ensure that the object and any other data of interest in this **WABEXTDISPLAY** structure survives as long as you need it.
If you call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref), you must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on **lpPropObj** when you no longer need it.

If your application uses named properties, and you want to get the named properties relevant to you from the WAB, you can call the [GetIDsfromNames](https://learn.microsoft.com/previous-versions/windows/desktop/wab/-wab-iabcontainer-getidsfromnames) method on this **lpPropObj** object to retrieve any such named properties. If you want to access properties that are associated with messaging users, cast this object to an [LPMAILUSER](https://learn.microsoft.com/windows/desktop/api/wabdefs/nn-wabdefs-imailuser) before calling GetIDsfromNames on it.

### `fReadOnly`

Type: **BOOL**

Variable of type **BOOL** that specifies the read-only property on certain kinds of objects, such as the [VCARD_NAME](https://developer.mozilla.org/en-US/docs/Web/HTML/Reference) attribute, [LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap) search results, and one-off MailUser. This member is relevant only for [IShellPropSheetExt Interface](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellpropsheetext). If this flag is set to true, one's property sheet must set all its controls to a read-only or disabled mode, typically in response to the [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message. Setting controls to a read-only state makes the user experience more consistent.

### `fDataChanged`

Type: **BOOL**

Variable of type **BOOL** that specifies the flag indicating that a change has been made to your property sheet. This member is relevant for [IShellPropSheetExt Interface](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellpropsheetext) only. Any time the user makes a change such as adding, editing or deleting data on your property sheet, you must set this flag to true to signal to the WAB that the data on your property sheet has changed. If this flag is not set, the WAB may not persist the changes the user made to your property sheet.

### `ulFlags`

Type: **ULONG**

Variable of type **ULONG** that specifies flags that control behavior. The following flags are valid.

#### WAB_CONTEXT_ADRLIST

Set when the WAB calls [Initialize](https://learn.microsoft.com/previous-versions/ms629473(v=vs.85)) prior to invoking your [IContextMenu Interface](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu) methods. This flag indicates that **lpv** contains a pointer to an [ADRLIST](https://learn.microsoft.com/windows/desktop/api/wabdefs/ns-wabdefs-adrlist) structure. The **ADRLIST** structure contains one or more entries, each corresponding to a selected item in the WAB user interface. To retrieve and use this **ADRLIST**, cast **lpv** to an **LPADRLIST**. You can also use **ulFlags** to determine that **WABEXTDISPLAY** is being used to initialize an IContextMenu Interface operation. If **ulFlags** does not contain this flag, you can safely assume that the structure is being used for a [IShellPropSheetExt Interface](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellpropsheetext) action.

#### WAB_DISPLAY_LDAPURL

Indicates that **lpsz** contains the [LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap) URL that is currently being displayed.
Sometimes the WAB will display a property sheet on a contact represented by a LDAP URL. While the contact to which the LDAP URL points will be wrapped into a WAB object and placed in **lpPropObj**, the property sheet may access the URL directly.

### `lpv`

Type: **LPVOID**

Pointer that specifies miscellaneous information that is passed to your application. The current flags identify the information being represented. If **ulFlags** is set to **WAB_CONTEXT_ADRLIST**, **lpv** contains a pointer to an [ADRLIST](https://learn.microsoft.com/windows/desktop/api/wabdefs/ns-wabdefs-adrlist). Cast **lpv** to an **ADRLIST** to access the contents of the **ADRLIST**. The **lpAdrList->cEntries** member contains the number of selected items. The [ADRENTRY](https://learn.microsoft.com/windows/desktop/api/wabdefs/ns-wabdefs-adrentry) structures in **lpAdrList->aEntries** contain [SPropValue](https://learn.microsoft.com/windows/desktop/api/wabdefs/ns-wabdefs-spropvalue) arrays with all of the properties pertaining to each selected item.

### `lpsz`

Type: **LPTSTR**

Variable of type **LPTSTR** that specifies a string used for passing in miscellaneous information to your application. The current flags identify the information being represented. If **ulFlags** is set to **WAB_DISPLAY_LDAPURL**, the **lpsz** member contains a pointer to a **NULL** terminated string containing the LDAP URL whose properties are being displayed.