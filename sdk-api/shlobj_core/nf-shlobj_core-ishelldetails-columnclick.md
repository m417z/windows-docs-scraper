# IShellDetails::ColumnClick

## Description

Rearranges a column.

## Parameters

### `iColumn`

Type: **UINT**

The index of the column to be rearranged.

## Return value

Type: **HRESULT**

Returns S_FALSE to tell the calling application to sort the selected column. Otherwise, returns S_OK if successful, a COM error code otherwise.

## Remarks

This method is called when a client of a folder object wants to sort the object's items based on the contents of one of the Details columns. Folder objects typically return S_FALSE.

### Note to Implementers

For Windows 2000 and later systems, folder objects should implement [IShellFolder2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder2) instead of this interface. However, if your application needs to function on earlier systems, it should also expose [IShellDetails](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-ishelldetails).

## See also

[IShellDetails](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-ishelldetails)

[IShellDetails::GetDetailsOf](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-ishelldetails-getdetailsof)