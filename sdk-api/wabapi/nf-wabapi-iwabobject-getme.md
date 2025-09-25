# IWABObject::GetMe

## Description

Retrieves the entry identifier of the object that has been designated
as "ME."

## Parameters

### `lpIAB`

Type: **[IAddrBook](https://learn.microsoft.com/windows/desktop/api/wabiab/nn-wabiab-iaddrbook)***

Pointer to an [IAddrBook](https://learn.microsoft.com/windows/desktop/api/wabiab/nn-wabiab-iaddrbook) interface
that specifies the address book object.

### `ulFlags`

Type: **ULONG**

Value of type **ULONG** that specifies flags
affecting functionality.

#### AB_NO_DIALOG

Suppresses the ME selection dialog box.

#### WABOBJECT_ME_NOCREATE

Suppresses automatic ME creation.

### `lpdwAction`

Type: **DWORD***

Pointer to a variable of type **DWORD** that
receives the flag WABOBJECT_ME_NEW on return, if a new ME entry is created.
The variable is used to signal creation, as opposed to selection, of a new ME entry. The variable
can be **NULL**.

### `lpsbEID`

Type: **[SBinary](https://learn.microsoft.com/previous-versions/office/developer/office-2007/cc815817(v=office.12))***

Pointer to a variable of type [SBinary](https://learn.microsoft.com/previous-versions/office/developer/office-2007/cc815817(v=office.12))
that specifies the entry identifier of the ME object on return.

### `hwnd`

Type: **ULONG**

Value of type **ULONG** that specifies
the handle of the parent window for displayed dialog boxes.
You must cast the parent **HWND** to a
**ULONG**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Users can designate a single entry in the Windows Address Book (WAB)
that represents them. This entry is referred to as "ME." Applications desiring information about the WAB user can access
this entry to obtain such information. The **IWABObject::GetMe**
method returns the entry identifier of the object that has been designated as "ME."
The application can then open this object using the entry identifier to inspect its
properties.

If an application calls **IWABObject::GetMe** when no ME entry
exists in the WAB, the WAB opens a dialog box that requests the user to create a new ME entry or designate
an existing entry in the WAB as being the ME entry.

If an application passes the **AB_NO_DIALOG**
flag in the *ulFlags* parameter, and no ME entry already exists, the
selection dialog box is not displayed and a new entry is automatically created.

If the user of the application calls the **IWABObject::GetMe** method to check for the existence of "ME" but does not want a new ME entry to be created automatically, the application must pass **WABOBJECT_ME_NOCREATE**. This flag prevents the creation of a new entry. If an existing ME entry is not found, the call to **IWABObject::GetMe** fails, returning MAPI_E_NOT_FOUND.

**Note** (Microsoft Internet Explorer 5
and later) If the user or the calling application informs
the WAB that a new ME object should be created,
the WAB creates the new object and tries to pre-populate it
with data that the user may have previously entered using the Registration
Wizard in Windows 98 and Windows 2000. This pre-populated
information will be displayed to the user so that the user has the option
of changing it as necessary.