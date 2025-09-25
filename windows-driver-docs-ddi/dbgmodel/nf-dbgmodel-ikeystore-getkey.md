# IKeyStore::GetKey

## Description

The GetKey method is analogous to the GetKey method on [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject). It will return the value of the specified key if it exists in the key store or the key store's parent store. Note that if the value of the key is a property accessor, the GetValue method will not be called on the property accessor. The actual [IModelPropertyAccessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelpropertyaccessor) boxed into an [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) will be returned. It is typical that a client will call GetKeyValue for this reason.

## Parameters

### `key`

The name of the key to get a value for

### `object`

The value of the key will be returned in this argument.

### `metadata`

The metadata store associated with this key will be optionally returned in this argument. There is no present use for second level metadata. This argument should therefore typically be specified as null.

## Return value

This method returns HRESULT that indicates success or failure. The return values E_BOUNDS (or E_NOT_SET in some cases) indicates the key could not be found.

## Remarks

**Code Sample**

```cpp
ComPtr<IModelObject> spObject; /* get an object */
ComPtr<IKeyStore> spMetadata;  /* get a key store from spObject (say
                                  returned from GetKeyValue) */

ComPtr<IModelObject> spRadixKey;
if (SUCCEEDED(spMetadata->GetKey(L"PreferredRadix", &spRadixKey, nullptr)))
{
    // Since this is GetKey and not GetKeyValue, spRadixKey *MAY* be a
    // property accessor.  Check and fetch.
    ModelObjectKind kind;
    if (SUCCEEDED(spRadixKey->GetKind(&kind)))
    {
        if (kind == ObjectPropertyAccessor)
        {
            VARIANT vtProp;
            if (SUCCEEDED(spRadixKey->GetIntrinsicValue(&vtProp)))
            {
                // There is a guarantee in-process that the IUnknown here
                // is IModelPropertyAccessor because of the ObjectPropertyAccessor.
                IModelPropertyAccessor *pProperty =
                    static_cast<IModelPropertyAccessor *>(vtProp.punkVal);

                ComPtr<IModelObject> spRadix;

                // It is important that the context object be the object where
                // the metadata store CAME FROM.  Hence the second argument
                // of spObject.Get().  Note that if you use GetKeyValue on the store,
                // this is automatically handled for you.
                if (SUCCEEDEDED(pProperty->GetValue(L"PreferredRadix",
                                                    spObject.Get(),
                                                    &spRadix)))
                {
                    // spRadix has the radix.  Use GetIntrinsicValueAs to unbox.
                }
                VariantClear(&vtProp);
            }
        }
        else
        {
            // spRadixKey has the radix.  Use GetIntrinsicValueAs to unbox.
        }
    }
}
```

## See also

[IKeyStore interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-ikeystore)