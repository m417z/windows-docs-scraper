# IWABObject::Find

## Description

Launches the Windows Address Book (WAB) Find dialog box.

## Parameters

### `lpIAB`

Type: **[IAddrBook](https://learn.microsoft.com/windows/desktop/api/wabiab/nn-wabiab-iaddrbook)***

Pointer to an [IAddrBook](https://learn.microsoft.com/windows/desktop/api/wabiab/nn-wabiab-iaddrbook) interface
that specifies the address book to search.

### `hWnd`

Type: **HWND**

Value of type **HWND** that specifies
the handle to the parent window for the Find dialog box.
The value can be **NULL**.

## Return value

Type: **HRESULT**

Returns S_OK if successful.