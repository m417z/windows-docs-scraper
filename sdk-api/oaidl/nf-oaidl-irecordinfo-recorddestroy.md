# IRecordInfo::RecordDestroy

## Description

Releases the resources and deallocates the memory of the record.

## Parameters

### `pvRecord` [in]

An instance of the record to be destroyed.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |

## Remarks

[RecordClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-irecordinfo-recordclear) is called to release the resources held by the instance of a record without deallocating memory.

**Note** This method can only be called on records allocated through [RecordCreate](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-irecordinfo-recordcreate) and [RecordCreateCopy](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-irecordinfo-recordcreatecopy). If you allocate the record yourself, you cannot call this method.

## See also

[IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo)