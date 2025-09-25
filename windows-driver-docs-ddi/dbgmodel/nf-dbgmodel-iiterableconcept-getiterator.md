# IIterableConcept::GetIterator

## Description

The GetIterator method on the iterable concept returns an iterator interface which can be used to iterate the object. The returned iterator must remember the context object that was passed to the GetIterator method. It will not be passed to methods on the iterator itself.

## Parameters

### `contextObject`

The instance (this pointer) for which to acquire an iterator.

### `iterator`

An implementation of [IModelIterator](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodeliterator) which iterates the instance object is returned here.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

**Example Implementation:**

```cpp
IFACEMETHOD(GetIterator)(_In_ IModelObject *pContextObject,
                         _COM_Outptr_ IModelIterator **ppIterator)
{
    HRESULT hr = S_OK:
    *ppIterator = nullptr;

    // The iterator is not going to be passed the context object any more.
    // If it needs this (to access fields for iteration, etc...), it must
    // capture that in its own state.
    ComPtr<MyObjectIterator> spIter;
    hr = Microsoft::WRL::MakeAndInitialize<MyObjectIterator>(&spIter, pContextObject);
    if (SUCCEEDED(hr))
    {
        *ppIterator = spIter.Detach();
    }
    return hr;
}
```

## See also

[IIterableConcept interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-iiterableconcept)