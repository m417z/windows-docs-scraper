# IRecordInfo::RecordCopy

## Description

Copies an existing record into the passed in buffer.

## Parameters

### `pvExisting` [in]

The current record instance.

### `pvNew` [out]

The destination where the record will be copied.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |

## Remarks

**RecordCopy** will release the resources in the destination first. The caller is responsible for allocating sufficient memory in the destination by calling [GetSize](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-irecordinfo-getsize) or [RecordCreate](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-irecordinfo-recordcreate). If **RecordCopy** fails to copy any of the fields then all fields will be cleared, as though [RecordClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-irecordinfo-recordclear) had been called.

## See also

[IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo)