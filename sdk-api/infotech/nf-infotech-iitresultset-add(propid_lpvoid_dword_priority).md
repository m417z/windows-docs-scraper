# IITResultSet::Add(PROPID,LPVOID,DWORD,PRIORITY)

## Description

Adds a column to the result set.

## Parameters

### `PropID` [in]

Property ID associated with column.

### `lpvDefaultData` [in]

Buffer containing default value of data.

### `cbData` [in]

Buffer size.

### `Priority` [in]

Download priority of column (PRIORITY_LOW, PRIORITY_NORMAL, or PRIORITY_HIGH).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The column was successfully added. |
| **E_OUTOFMEMORY** | Memory allocation failed. |

## Remarks

This method is used to add a column for pointer properties.

## See also

[IITResultSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/infotech/nn-infotech-iitresultset)