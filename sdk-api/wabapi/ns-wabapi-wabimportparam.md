# WABIMPORTPARAM structure

## Description

Do not use. Structure passed to [Import](https://learn.microsoft.com/windows/desktop/api/wabapi/nf-wabapi-iwabobject-import) that gives information about importing .wab files.

## Members

### `cbSize`

Type: **ULONG**

Value of type **ULONG** that specifies the size of the structure in bytes.

### `lpAdrBook`

Type: **[IAddrBook](https://learn.microsoft.com/windows/desktop/api/wabiab/nn-wabiab-iaddrbook)***

Pointer to an [IAddrBook](https://learn.microsoft.com/windows/desktop/api/wabiab/nn-wabiab-iaddrbook) interface that specifies the address book object to import to.

### `hWnd`

### `ulFlags`

Type: **ULONG**

Value of type **ULONG** that specifies flags affecting behavior.

#### MAPI_DIALOG

Causes [Import](https://learn.microsoft.com/windows/desktop/api/wabapi/nf-wabapi-iwabobject-import) to show a dialog box with a progress bar indicating the progress of the import process.

### `lpszFileName`

Type: **LPSTR**

Value of type **LPSTR** that specifies the filename to import, or **NULL** to cause a FileOpen dialog box to open.

### `hwnd`

Type: **HWND**

Value of type **HWND** that specifies the parent window handle for any dialog boxes.