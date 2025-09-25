# IShellView::AddPropertySheetPages

## Description

Allows the view to add pages to the **Options** property sheet from the **View** menu.

## Parameters

### `dwReserved` [in]

Type: **DWORD**

Reserved.

### `pfn` [in]

Type: **LPFNADDPROPSHEETPAGE**

The address of the callback function used to add the pages.

### `lparam` [in]

Type: **LPARAM**

A value that must be passed as the callback function's *lparam* parameter.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM-defined error value otherwise.

## Remarks

### Notes to Implementers

Windows Explorer calls this method when it is opening the **Options** property sheet from the **View** menu. Views can add pages by creating them and calling the callback function with the page handles.

## See also

[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)