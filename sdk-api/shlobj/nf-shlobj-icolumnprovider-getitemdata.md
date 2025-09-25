# IColumnProvider::GetItemData

## Description

Requests column data for a specified file.

## Parameters

### `pscid` [in]

Type: **LPCSHCOLUMNID**

An [SHCOLUMNID](https://learn.microsoft.com/windows/desktop/shell/objects) structure that identifies the column.

### `pscd` [in]

Type: **LPCSHCOLUMNDATA**

An [SHCOLUMNDATA](https://learn.microsoft.com/windows/desktop/api/shlobj/ns-shlobj-shcolumndata) structure that specifies the file.

### `pvarData` [out]

Type: **VARIANT***

A pointer to a **VARIANT** with the data for the file specified by *pscd* that belongs in the column specified by *pscid*. Set this value if the file is a member of the class supported by the column provider.

## Return value

Type: **HRESULT**

Returns S_OK if file data is returned, S_FALSE if the file is not supported by the column provider and no data is returned, or a COM error value otherwise.

## Remarks

This method is called to retrieve the data for a file to be displayed in the specified column. It should be thread-safe.

This method is called for every file that Windows Explorer displays, even though many of them will not be supported by a particular column provider. To improve performance, first check the **pwszExt** member of the structure pointed to by *pscd* to see if it has a file name extension that is supported by the column provider. If not, avoid unnecessary processing by immediately returning S_FALSE.