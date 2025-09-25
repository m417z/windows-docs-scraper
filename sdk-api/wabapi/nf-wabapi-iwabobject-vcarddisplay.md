# IWABObject::VCardDisplay

## Description

Displays properties on a vCard file.

## Parameters

### `lpIAB`

Type: **[IAddrBook](https://learn.microsoft.com/windows/desktop/api/wabiab/nn-wabiab-iaddrbook)***

Pointer to an [IAddrBook](https://learn.microsoft.com/windows/desktop/api/wabiab/nn-wabiab-iaddrbook) interface
that specifies the address book object.

### `hWnd`

Type: **HWND**

Value of type **HWND** that specifies
the parent window handle for displayed dialog boxes.

### `lpszFileName`

Type: **LPSTR**

Value of type **LPSTR** that specifies
the full path of the vCard file to display.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.