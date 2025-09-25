# IEnumVARIANT::Next

## Description

Retrieves the specified items in the enumeration sequence.

## Parameters

### `celt` [in]

The number of elements to be retrieved

### `rgVar` [out]

An array of at least size *celt* in which the elements are to be returned.

### `pCeltFetched` [out]

The number of elements returned in *rgVar*, or NULL.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The number of elements returned is *celt*. |
| **S_FALSE** | The number of elements returned is less than *celt*. |

## Remarks

If fewer than the requested number of elements remain in the sequence, **Next** returns only the remaining elements. The actual number of elements is returned in *pCeltFetched*, unless it is null.

#### Examples

The following code implements **IEnumVariant::Next**. A complete example implementation of the **IEnumVariant** interface is available in the COM Fundamentals Lines sample (Enumvar.cpp).

```cpp
STDMETHODIMP
CEnumVariant::Next(ULONG cElements, VARIANT * pvar, ULONG * pcElementFetched)
{
   HRESULT hr;
   ULONG l;
   long l1;
   ULONG l2;

   if (pcElementFetched != NULL)
      *pcElementFetched = 0;

   if (pvar == NULL)
      return E_INVALIDARG;

   for (l=0; l<cElements; l++)
      VariantInit(&pvar[l]);

   // Retrieve the next cElements elements.
   // m_lLBound+m_cElements = # of elements in the m_psa collection.

   for (l1=m_lCurrent, l2=0; l1<(long)(m_lLBound+m_cElements) &&
      l2<cElements; l1++, l2++)
   {
      hr = SafeArrayGetElement(m_psa, &l1, &pvar[l2]);
      if (FAILED(hr))
         goto error;
   }
   // Set count of elements retrieved.
   if (pcElementFetched != NULL)
      *pcElementFetched = l2;
   m_lCurrent = l1;

   return  (l2 < cElements) ? S_FALSE : NOERROR;

error:
   for (l=0; l<cElements; l++)
      VariantClear(&pvar[l]);
   return hr;
}
```

## See also

[IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant)