# IKeyStore::SetKey

## Description

The SetKey method is analogous to the SetKey method on [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject). It is the only method which is capable of creating a key and associating metadata with it within the key store.

## Parameters

### `key`

The name of the key to create or set a value for.

### `object`

The value of the key.

### `metadata`

Optional metadata to be associated with this key. There is no present use for second level metadata. This argument should therefore typically be specified as null.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IDataModelManager> spManager; /* get the data model manager */
ComPtr<IKeyStore> spMetadata;        /* get or create a metadata store */

ComPtr<IModelObject> sp16;
VARIANT vt16;
vt16.vt = VT_UI4;
vt16.ulVal = 16;
if (SUCCEEDED(spManager->CreateIntrinsicObject(ObjectIntrinsic, &vt16, &sp16)))
{
    if (SUCCEEDED(spMetadata->SetKey(L"PreferredRadix", sp16.Get(), nullptr)))
    {
        // The 'PreferredRadix' key has been set to 16 (even if it did
        // not exist).  If this metadata store is passed to something like
        // IStringDisplayableConcept::ToDisplayString, the conversion of numbers
        // will happen in hexadecimal instead of the default radix.
    }
}
```

## See also

[IKeyStore interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-ikeystore)