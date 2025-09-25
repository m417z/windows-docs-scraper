# IShellFolder2::GetDetailsOf

## Description

Gets detailed information, identified by a column index, on an item in a Shell folder.

## Parameters

### `pidl` [in]

Type: **PCUITEMID_CHILD**

PIDL of the item for which you are requesting information. This method accepts only single-level PIDLs. The structure must contain exactly one [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid) structure followed by a terminating zero. If this parameter is set to **NULL**, the title of the information field specified by *iColumn* is returned.

### `iColumn` [in]

Type: **UINT**

The zero-based index of the desired information field. It is identical to the column number of the information as it is displayed in a Windows Explorer Details view.

### `psd` [out]

Type: **[SHELLDETAILS](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shelldetails)***

A pointer to a [SHELLDETAILS](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shelldetails) structure that contains the information.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **IShellFolder2::GetDetailsOf** method is identical to [GetDetailsOf](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-ishelldetails-getdetailsof). For a more robust way to retrieve item information that does not require you to know the column index, use [IShellFolder2::GetDetailsEx](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder2-getdetailsex).

The **IShellFolder2::GetDetailsOf** method provides access to the information that is displayed in the Windows Explorer Details view of a Shell folder. The column numbers, headings, and information that you see in the Details view are identical to those of **IShellFolder2::GetDetailsOf**. Note that the available information fields and their column numbers vary depending on the particular folder. You can enumerate the available fields by calling this method with *pidl* set to **NULL**, and examining the title associated with each column index. Bear in mind that these titles can be localized and might not be the same for all locales.

File system folders have a large, standard set of information fields. The first four fields are standard for all file system folders.

| Column index | Column title |
| --- | --- |
| 0 | Name |
| 1 | Size |
| 2 | Type |
| 3 | Date Modified |

File system folders can support a number of additional fields. However, they are not required to do so, and the column indexes assigned to these fields might vary.

Each virtual folder has its own unique set of information fields. Normally, the item's display name is in column zero, but the order and content of the remaining fields depend on the implementation of the particular folder object.