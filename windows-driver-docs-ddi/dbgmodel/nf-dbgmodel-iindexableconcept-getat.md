# IIndexableConcept::GetAt

## Description

The GetAt method retrieves the value at a particular N-dimensional index from within the indexed object. An indexer of N-dimensions where N is the value returned from GetDimensionality must be supported. Note that an object may be indexable in different domains by different types (e.g.: indexable via both ordinals and strings). If the index is out of range (or could not be accessed), the method will return a failure; however, in such cases, the output object may still be set to an error object.

## Parameters

### `contextObject`

The instance object (this pointer) which is being indexed is passed here.

### `indexerCount`

The number of dimensions that the object is being indexed in.

### `indexers`

An array (sized according to the indexerCount) of indices indicating where inside the instance object to access.

### `object`

The value of the element at the specified indices is returned here. If the method fails, extended error information may be returned here as an error object.

### `metadata`

Optional metadata about the indexed element may be returned here.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

**Example Implementation:**

```cpp
// Consider that we are pairing this with the same MyObjectIterator class
// shown in the example snippet for IModelIterator::GetNext.
IFACEMETHOD(GetAt)(_In_ IModelObject *pContextObject,
                   _In_ ULONG64 indexerCount,
                   _In_reads_(indexerCount) IModelObject **ppIndexers,
                   _COM_Errorptr_ **ppValue,
                   _COM_Outptr_opt_result_maybenull_ IKeyStore **ppMetadata)
{
    HRESULT hr = S_OK;
    *ppValue = nullptr;
    if (ppMetadata != nullptr)
    {
        *ppMetadata = nullptr;
    }

    if (indexerCount != 1)
    {
        return E_INVALIDARG;
    }

    ComPtr<IModelObject> spValue;

    ULONG64 numElements;
    ComPtr<IModelObject> spNumElements;
    hr = pContextObject->GetKeyValue(L"NumElements", &spNumElements, nullptr));
    if (SUCCEEDED(hr))
    {
        VARIANT vtNumElements;
        hr = spNumElements->GetIntrinsicValueAs(VT_UI8, &vtNumElements));
        if (SUCCEEDED(hr))
        {
            VARIANT vtIdx;
            hr = ppIndexers[0]->GetIntrinsicValueAs(VT_UI8, &vtIdx));
            if (SUCCEEDED(hr))
            {
                if (vtIdx.ullVal >= vtNumElements.ullVal)
                {
                    return E_BOUNDS;
                }

                VARIANT vtValue;
                vtValue.vt = VT_UI8;
                vtValue.ullVal = vtIdx.ullVal + 10;
                hr = GetManager()->CreateIntrinsicObject(ObjectIntrinsic,
                                                         &vtValue,
                                                         &spValue);
            }
        }
    }

    if (SUCCEEDED(hr))
    {
        *ppValue = spValue.Detach();
    }

    return hr;
}
```

## See also

[IIndexableConcept interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-iindexableconcept)