# IColumnProvider::GetColumnInfo

## Description

Requests information about a column.

## Parameters

### `dwIndex`

Type: **DWORD**

The column's zero-based index. It is an arbitrary value that is used to enumerate columns.

### `psci` [out]

Type: **[SHCOLUMNINFO](https://learn.microsoft.com/windows/desktop/api/shlobj/ns-shlobj-shcolumninfo)***

A pointer to an [SHCOLUMNINFO](https://learn.microsoft.com/windows/desktop/api/shlobj/ns-shlobj-shcolumninfo) structure to hold the column information.

## Return value

Type: **HRESULT**

Returns a COM error value to indicate that the request was unsuccessful or one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Request successful. |
| **S_FALSE** | Column index out of range. |

## Remarks

This method is called to assign an index to the column and to ask for details on what kind of information the column will contain.

## See also

[IColumnProvider](https://learn.microsoft.com/windows/desktop/api/shlobj/nn-shlobj-icolumnprovider)