# IEnumVARIANT::Clone

## Description

Creates a copy of the current state of enumeration.

## Parameters

### `ppEnum` [out]

The clone enumerator.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

Using this function, a particular point in the enumeration sequence can be recorded, and then returned to at a later time. The returned enumerator is of the same actual interface as the one that is being cloned.

There is no guarantee that exactly the same set of variants will be enumerated the second time as was enumerated the first. Although an exact duplicate is desirable, the outcome depends on the collection being enumerated. You may find that it is impractical for some collections to maintain this condition (for example, an enumeration of the files in a directory).

#### Examples

The following code implements **IEnumVariant::Clone**. A complete example implementation of the **IEnumVariant** interface is available in the COM Fundamentals Lines sample (Enumvar.cpp).

```cpp
STDMETHODIMP
CEnumVariant::Clone(IEnumVARIANT ** ppenum)
{
   CEnumVariant * penum = NULL;
   HRESULT hr;

   if (ppenum == NULL)
      return E_INVALIDARG;

   *ppenum = NULL;

   hr = CEnumVariant::Create(m_psa, m_cElements, &penum);
   if (FAILED(hr))
      goto error;
   penum->AddRef();
   penum->m_lCurrent = m_lCurrent;

   *ppenum = penum;
   return NOERROR;

error:
   if (penum)
      penum->Release();
   return hr;
}
```

## See also

[IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant)