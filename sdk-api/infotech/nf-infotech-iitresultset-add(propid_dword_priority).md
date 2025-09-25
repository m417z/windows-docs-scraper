# IITResultSet::Add(PROPID,DWORD,PRIORITY)

## Description

Adds a column to the result set.

## Parameters

### `PropID` [in]

Property ID associated with column.

### `dwDefaultData` [in]

Default data value.

### `Priority` [in]

Download priority of column (PRIORITY_LOW, PRIORITY_NORMAL, or PRIORITY_HIGH).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The column was successfully added. |
| **E_OUTOFMEMORY** | Memory allocation failed. |

## Remarks

This method is used to add a column for numerical properties.

## See also

[IITResultSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/infotech/nn-infotech-iitresultset)