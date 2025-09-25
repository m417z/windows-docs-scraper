# SafeArrayDestroyData function

## Description

Destroys all the data in the specified safe array.

## Parameters

### `psa` [in]

A safe array descriptor.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The argument *psa* was not valid. |
| **DISP_E_ARRAYISLOCKED** | The array is locked. |

## Remarks

This function is typically used when freeing safe arrays that contain elements with data types other than variants. If objects are stored in the array, Release is called on each object in the array. Safe arrays of variant will have the [VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear) function called on each member and safe arrays of BSTR will have the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function called on each element. [IRecordInfo::RecordClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-irecordinfo-recordclear) will be called to release object references and other values of a record without deallocating the record.