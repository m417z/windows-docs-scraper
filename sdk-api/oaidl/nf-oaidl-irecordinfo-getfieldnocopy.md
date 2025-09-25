# IRecordInfo::GetFieldNoCopy

## Description

Returns a pointer to the value of a given field name without copying the value and allocating resources.

## Parameters

### `pvData` [in]

The instance of a record.

### `szFieldName` [in]

The name of the field.

### `pvarField` [out]

The VARIANT that will contain the UDT upon return.

### `ppvDataCArray` [out]

 Receives the value of the field upon return.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |

## Remarks

Upon return, the VARIANT you pass contains a direct pointer to the record's field, *ppvDataCArray*. If you modify the VARIANT, then the underlying record field will change.

The caller allocates memory of the VARIANT, but does not own the memory so cannot free *pvarField*. This method calls [VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear) for *pvarField* before filling in the requested field.

## See also

[IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo)

[VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear)