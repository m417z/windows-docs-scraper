# IRecordInfo::RecordClear

## Description

Releases object references and other values of a record without deallocating the record.

## Parameters

### `pvExisting` [in]

The record to be cleared.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |

## Remarks

**RecordClear** releases memory blocks held by VT_PTR or VT_SAFEARRAY instance fields. The caller needs to free the instance fields memory, **RecordClear** will do nothing if there are no resources held.

## See also

[IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo)