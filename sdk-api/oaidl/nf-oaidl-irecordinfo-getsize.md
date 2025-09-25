# IRecordInfo::GetSize

## Description

Gets the number of bytes of memory necessary to hold the record instance. This allows you to allocate memory for a record instance rather than calling [RecordCreate](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-irecordinfo-recordcreate).

## Parameters

### `pcbSize` [out]

The size of a record instance, in bytes.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |

## See also

[IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo)