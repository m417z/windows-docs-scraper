# IWABObject::SetMe

## Description

Designates a particular contact as the ME object.

## Parameters

### `lpIAB`

Type: **[IAddrBook](https://learn.microsoft.com/windows/desktop/api/wabiab/nn-wabiab-iaddrbook)***

Pointer to an [IAddrBook](https://learn.microsoft.com/windows/desktop/api/wabiab/nn-wabiab-iaddrbook) interface
that specifies the address book.

### `ulFlags`

Type: **ULONG**

Value of type **ULONG** that specifies flags
affecting behavior.

#### MAPI_DIALOG

Causes a selection dialog box to be displayed.

### `sbEID`

Type: **[SBinary](https://learn.microsoft.com/previous-versions/office/developer/office-2007/cc815817(v=office.12))**

Value of type [SBinary](https://learn.microsoft.com/previous-versions/office/developer/office-2007/cc815817(v=office.12)) that
specifies the entry identifier of the contact that should be tagged
as ME.

### `hwnd`

Type: **ULONG**

Value of type **ULONG** that specifies the
parent window handle for displaying dialog boxes. Cast the
parent **HWND** to a **ULONG**
before passing.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error code otherwise.

## Remarks

If the calling application provides an entry identifier to set as the ME object,
and *ulFlags* is set to zero, the entry corresponding
to the entry identifier is designated as "ME" and any previous ME entry is cleared
of this setting.

If the calling application specifies
**MAPI_DIALOG** in the *ulFlags* parameter,
the Windows Address Book (WAB) displays a ME selection dialog box which contains
a list of contacts from which the user can choose. If the application passed
in an entry identifier, the entry corresponding to the entry identifier is pre-selected
in the contact list. If the application did not pass in an entry identifier,
and a ME entry currently exists in the WAB, the current ME entry is
pre-selected in the contact list.

Passing a combination of no flags and no entry identifiers is not valid.