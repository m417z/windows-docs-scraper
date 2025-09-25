# SafeArraySetRecordInfo function

## Description

Sets the record info in the specified safe array.

## Parameters

### `psa` [in]

The array descriptor.

### `prinfo` [in]

The record info.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The argument *psa* is null or the array descriptor does not have the FADF_RECORD flag set. |

## See also

[IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo)