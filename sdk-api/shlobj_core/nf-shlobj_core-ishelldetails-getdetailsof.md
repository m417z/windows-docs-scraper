# IShellDetails::GetDetailsOf

## Description

Gets detailed information on an item in a Shell folder.

## Parameters

### `pidl` [in, optional]

Type: **PCUITEMID_CHILD**

The PIDL of the item that you are requesting information for. If this parameter is set to **NULL**, the title of the information field specified by *iColumn* will be returned in the [SHELLDETAILS](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shelldetails) structure pointed to by *pDetails*.

### `iColumn`

Type: **UINT**

The zero-based index of the desired information field. It is identical to column number of the information as it is displayed in a Windows Explorer Details view.

### `pDetails` [out]

Type: **SHELLDETAILS***

A pointer to a [SHELLDETAILS](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shelldetails) structure with the detail information.

## Return value

Type: **HRESULT**

Returns S_OK if successful. Returns E_FAIL if *iColumn* exceeds the number of columns supported by the folder. Otherwise, returns a standard COM error code.

## Remarks

This method has been superseded by the [IShellFolder2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder2) methods for Shell [version 5.0](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)) and later.

The **IShellDetails::GetDetailsOf** method provides access to the information that is displayed in the Windows Explorer Details view of a Shell folder. The column numbers, column titles, and item information that you see in the Details view are identical to those returned by **IShellDetails::GetDetailsOf**.

The available information fields and their column numbers vary depending on the particular folder. To enumerate the available fields call **IShellDetails::GetDetailsOf** with *pidl* set to **NULL** for increasing values of *iColumn*. This approach provides you with the title associated with each column index. When *iColumn* exceeds the number of columns supported by the folder, **IShellDetails::GetDetailsOf** will return E_FAIL. Bear in mind that these titles are localizable, and may not be the same for all locales.

File system folders have a large standard set of information fields. The first four fields are standard for all file system folders.

| Column Index | Column Title |
| --- | --- |
| 0 | Name |
| 1 | Size |
| 2 | Type |
| 3 | Date Modified |

File system folders may support a number of additional fields. However, they are not required to do so and the column indexes assigned to these fields may vary.

Each virtual folder has its own unique set of information fields. Typically, the item's display name is in column zero, but the order and content of the available fields depend on the implementation of the particular folder object.

### Note to Implementers

Folder objects should implement [IShellFolder2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder2) instead of this interface.