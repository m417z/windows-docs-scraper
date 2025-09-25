# IRecordInfo::RecordInit

## Description

Initializes a new instance of a record.

## Parameters

### `pvNew` [out]

An instance of a record.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |

## Remarks

The caller must allocate the memory of the record by its appropriate size using the [GetSize](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-irecordinfo-getsize) method.

**RecordInit** sets all contents of the record to 0 and the record should hold no resources.

## See also

[IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo)