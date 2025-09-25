# SFVM_PROPPAGE_DATA structure

## Description

Contains the details of a page to be added to an object's **Properties** sheet.

## Members

### `dwReserved`

Type: **DWORD**

### `pfn`

Type: **LPFNADDPROPSHEETPAGE**

A pointer to a [AddPropSheetPageProc](https://learn.microsoft.com/windows/desktop/api/prsht/nc-prsht-lpfnaddpropsheetpage) callback function used to add property pages. When this function is used by Windows Explorer, it provides **pfn** through the system folder view object's [IShellView::AddPropertySheetPages](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellview-addpropertysheetpages) method. The callback function can then pass the information to [IShellPropSheetExt::AddPages](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellpropsheetext-addpages).

### `lParam`

Type: **LPARAM**

The details of the property sheet to be added. When this function is used by Windows Explorer, it provides **lParam** through the system folder view object's [IShellView::AddPropertySheetPages](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellview-addpropertysheetpages) method. The callback function can then pass the information to [IShellPropSheetExt::AddPages](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellpropsheetext-addpages).