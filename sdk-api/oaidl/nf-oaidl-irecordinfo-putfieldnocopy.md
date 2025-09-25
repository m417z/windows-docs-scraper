# IRecordInfo::PutFieldNoCopy

## Description

 Passes ownership of the data to the assigned field by placing the actual data into the field.**PutFieldNoCopy** is useful for saving resources because it allows you to place your data directly into a record field. **PutFieldNoCopy** differs from [PutField](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-irecordinfo-putfield) because it does not copy the data referenced by the variant.

## Parameters

### `wFlags` [in]

The only legal values for the wFlags parameter is INVOKE_PROPERTYPUT or INVOKE_PROPERTYPUTREF.

### `pvData` [in, out]

An instance of the record described by [IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo).

### `szFieldName` [in]

The name of the field of the record.

### `pvarField` [in]

The variant to be put into the field.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |

## See also

[IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo)