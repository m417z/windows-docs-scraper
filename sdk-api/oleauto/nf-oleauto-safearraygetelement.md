# SafeArrayGetElement function

## Description

Retrieves a single element of the array.

## Parameters

### `psa` [in]

An array descriptor created by [SafeArrayCreate](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearraycreate).

### `rgIndices` [in]

A vector of indexes for each dimension of the array. The right-most (least significant) dimension is rgIndices[0]. The left-most dimension is stored at `rgIndices[psa->cDims – 1]`.

### `pv` [out]

The element of the array.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **DISP_E_BADINDEX** | The specified index is not valid. |
| **E_INVALIDARG** | One of the arguments is not valid. |
| **E_OUTOFMEMORY** | Memory could not be allocated for the element. |

## Remarks

This function calls [SafeArrayLock](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearraylock) and [SafeArrayUnlock](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearrayunlock) automatically, before and after retrieving the element. The caller must provide a storage area of the correct size to receive the data. If the data element is a string, object, or variant, the function copies the element in the correct way.

#### Examples

The following example is taken from the COM Fundamentals SPoly sample (Cenumpt.cpp).

```cpp
STDMETHODIMP CEnumPoint::Next(
   ULONG celt,
   VARIANT  rgvar[],
   ULONG * pceltFetched)
{
   unsigned int i;
   long ix;
   HRESULT hresult;

   for(i = 0; i < celt; ++i)
      VariantInit(&rgvar[i]);

   for(i = 0; i < celt; ++i){
      // Are we at the last element?
      if(m_iCurrent == m_celts){
      hresult = S_FALSE;
         goto LDone;
   }

      ix = m_iCurrent++;
      // m_psa is a global variable that holds the safe array.
      hresult = SafeArrayGetElement(m_psa, &ix, &rgvar[i]);
      if(FAILED(hresult))
         goto LError0;
   }
   hresult = NOERROR;

LDone:;
   if (pceltFetched != NULL)
      *pceltFetched = i;

   return hresult;

LError0:;
   for(i = 0; i < celt; ++i)
      VariantClear(&rgvar[i]);
   return hresult;
}
```