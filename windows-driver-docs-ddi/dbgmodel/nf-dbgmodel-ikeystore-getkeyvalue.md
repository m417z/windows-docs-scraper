# IKeyStore::GetKeyValue

## Description

The GetKeyValue method is the first method a client will go to in order to find the value of a particular key within the metadata store. If the key specified by the key argument exists within the store (or it's parent store), the value of that key and any metadata associated with it will be returned. If the value of the key is a property accessor (an [IModelPropertyAccessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelpropertyaccessor) boxed into an [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)), the GetValue method of the property accessor will automatically be called by GetKeyValue and the underlying value of the property returned.

## Parameters

### `key`

The name of the key to return a value for.

### `object`

The value of the key will be returned here. If the key's value is a property accessor, the GetValue method will be called on the property accessor and that underlying value will be returned here..

### `metadata`

Any metadata which is associated with the key is optionally returned here. There is no present use for second level metadata. This argument should therefore typically be specified as null.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IKeyStore> spMetadata; /* get a metadata store */

ComPtr<IModelObject> spRadix;
if (SUCCEEDED(spMetadata->GetKeyValue(L"PreferredRadix", &spRadix, nullptr)))
{
    // spRadix has the preferred display radix.  Use GetIntrinsicValueAs to unbox.
}
```

## See also

[IKeyStore interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-ikeystore)