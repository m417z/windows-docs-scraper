# SafeArrayDestroy function

## Description

Destroys an existing array descriptor and all of the data in the array. If objects are stored in the array, **Release** is called on each object in the array.

## Parameters

### `psa` [in]

An array descriptor created by [SafeArrayCreate](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearraycreate).

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The argument *psa* is not valid. |
| **DISP_E_ARRAYISLOCKED** | The array is locked. |

## Remarks

Safe arrays of variant will have the [VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear) function called on each member and safe arrays of BSTR will have the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function called on each element. [IRecordInfo::RecordClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-irecordinfo-recordclear) will be called to release object references and other values of a record without deallocating the record.

#### Examples

```cpp
STDMETHODIMP_(ULONG) CEnumPoint::Release()
{
   if(--m_refs == 0){
      if(m_psa != NULL)
      SafeArrayDestroy(m_psa);
      delete this;
      return 0;
   }
   return m_refs;
}
```