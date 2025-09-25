# IRecordInfo::GetField

## Description

Returns a pointer to the VARIANT containing the value of a given field name.

## Parameters

### `pvData` [in]

The instance of a record.

### `szFieldName` [in]

The field name.

### `pvarField` [out]

The VARIANT that you want to hold the value of the field name, *szFieldName*. On return, places a copy of the field's value in the variant.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |

## Remarks

The VARIANT that you pass in contains a copy of the field's value upon return. If you modify the VARIANT then the underlying record field does not change.

The caller allocates memory of the VARIANT.

The method [VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear) is called for *pvarField* before copying.

## See also

[IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo)

[VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear)