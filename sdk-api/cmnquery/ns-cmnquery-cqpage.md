# CQPAGE structure

## Description

The **CQPAGE** structure is used to define a query page added to a form in the query dialog box with the [CQAddPagesProc](https://learn.microsoft.com/windows/desktop/api/cmnquery/nc-cmnquery-lpcqaddpagesproc) callback function.

## Members

### `cbStruct`

Contains the size, in bytes, of the structure.

### `dwFlags`

Reserved. This member must be zero.

### `pPageProc`

Pointer to a query page callback function defined by the query form extension. This callback function is used to notify the extension of events in the page and takes the form of the [CQPageProc](https://learn.microsoft.com/windows/desktop/api/cmnquery/nc-cmnquery-lpcqpageproc) callback function.

### `hInstance`

Contains the instance handle of the module that contains the resources identified by the **idPageName** and **idPageTemplate** members.

### `idPageName`

Contains the identifier of the string resource in **hInstance** used for the page title.

### `idPageTemplate`

Contains the identifier of the dialog resource in **hInstance** used for the page dialog.

### `pDlgProc`

Pointer to the dialog box procedure. For more information, see [DialogProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-dlgproc).

### `lParam`

An extension-defined 32-bit value passed in the **lParam** member of the **CQPAGE** structure passed as the *pPage* parameter in the [CQPageProc](https://learn.microsoft.com/windows/desktop/api/cmnquery/nc-cmnquery-lpcqpageproc) callback function.

## See also

[CQAddPagesProc](https://learn.microsoft.com/windows/desktop/api/cmnquery/nc-cmnquery-lpcqaddpagesproc)

[CQPageProc](https://learn.microsoft.com/windows/desktop/api/cmnquery/nc-cmnquery-lpcqpageproc)

[DialogProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-dlgproc)

[Display Structures in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-structures-in-active-directory-domain-services)

[IQueryForm::AddPages](https://learn.microsoft.com/windows/desktop/api/cmnquery/nf-cmnquery-iqueryform-addpages)