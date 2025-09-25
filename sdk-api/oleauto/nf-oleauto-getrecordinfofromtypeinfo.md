# GetRecordInfoFromTypeInfo function

## Description

Returns a pointer to the [IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo) interface of the UDT by passing its type information. The given [ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo) interface is used to create a RecordInfo object.

## Parameters

### `pTypeInfo` [in]

The type information of a record.

### `ppRecInfo` [out]

The [IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo) interface.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Out of memory. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **TYPE_E_UNSUPFORMAT** | The type is not an interface. |

## See also

[IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo)

[ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo)