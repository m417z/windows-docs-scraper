# IITResultSet::Get

## Description

Gets the property in the specified row and column and fills the given property object.

## Parameters

### `lRowIndex` [in]

Row where property belongs.

### `lColumnIndex` [in]

### `Prop` [out, ref]

Column where property belongs.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The row was successfully retrieved. |
| **E_NOTEXIST** | The row or column does not exist in the row set. |

## See also

[IITResultSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/infotech/nn-infotech-iitresultset)