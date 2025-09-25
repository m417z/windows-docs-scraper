# IMFCollection::GetElement

## Description

Retrieves an object in the collection.

## Parameters

### `dwElementIndex` [in]

Zero-based index of the object to retrieve. Objects are indexed in the order in which they were added to the collection.

### `ppUnkElement` [out]

Receives a pointer to the object's **IUnknown** interface. The caller must release the interface. The retrieved pointer value might be **NULL**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method does not remove the object from the collection. To remove an object, call [IMFCollection::RemoveElement](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfcollection-removeelement).

#### Examples

```cpp
//  Gets an interface pointer from a collection (IMFCollection).
//
//  Q: Interface type

template <class Q>
HRESULT GetCollectionObject(IMFCollection *pCollection,
    DWORD dwIndex, Q **ppObject)
{
    *ppObject = NULL;   // zero output

    IUnknown *pUnk = NULL;
    HRESULT hr = pCollection->GetElement(dwIndex, &pUnk);
    if (SUCCEEDED(hr))
    {
        hr = pUnk->QueryInterface(IID_PPV_ARGS(ppObject));
        pUnk->Release();
    }
    return hr;
}

```

## See also

[IMFCollection](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfcollection)