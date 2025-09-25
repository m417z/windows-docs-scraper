# IRecordInfo::PutField

## Description

Puts a variant into a field.

## Parameters

### `wFlags` [in]

The only legal values for the wFlags parameter is INVOKE_PROPERTYPUT or INVOKE_PROPERTYPUTREF.

If INVOKE_PROPERTYPUTREF is passed in then **PutField** just assigns the value of the variant that is passed in to the field using normal coercion rules.

If INVOKE_PROPERTYPUT is passed in then specific rules apply. If the field is declared as a class that derives from [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) and the field's value is NULL then an error will be returned. If the field's value is not NULL then the variant will be passed to the default property supported by the object referenced by the field. If the field is not declared as a class derived from **IDispatch** then an error will be returned. If the field is declared as a variant of type VT_Dispatch then the default value of the object is assigned to the field. Otherwise, the variant's value is assigned to the field.

### `pvData` [in, out]

The pointer to an instance of the record.

### `szFieldName` [in]

The name of the field of the record.

### `pvarField` [in]

The pointer to the variant.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |

## See also

[IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo)