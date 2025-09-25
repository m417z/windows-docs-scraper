# IRecordInfo::RecordCreateCopy

## Description

Creates a copy of an instance of a record to the specified location.

## Parameters

### `pvSource` [in]

An instance of the record to be copied.

### `ppvDest` [out]

The new record with data copied from *pvSource*.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUT_OFMEMORY** | Out of memory. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |

## Remarks

The records created must be freed by calling [RecordDestroy](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-irecordinfo-recorddestroy).

## See also

[IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo)