# IDataModelManager::CreateMetadataStore

## Description

The CreateMetadataStore method creates a key store -- a simplified container of key/value/metadata tuples -- which is used to hold metadata that can be associated with properties and a variety of other values.

A metadata store may have a single parent (which in turn can have a single parent). If a given metadata key is not located in a given store, its parents are checked. Most metadata stores do not have parents. It does, however, provide a way of sharing common metadata easily.

## Parameters

### `parentStore`

The parent store for the newly created metadata store. This may be null if there is no parent.

### `metadataStore`

The newly created metadata store will be returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDataModelManager> spManager; /* get the data model manager */

// Create an empty key store (the usual case) which will be later filled with metadata.
ComPtr<IKeyStore> spMetadata;
if (SUCCEEDED(spManager->CreateMetadataStore(nullptr, &spMetadata)))
{
    // spMetadata now is an empty store.  You can set key values
    // like 'PreferredRadix', 'PreferredFormat', 'PreferredLength', etc...
    ComPtr<IKeyStore> spChildMetadata;
    if (SUCCEEDED(spManager->CreateMetadataStore(spMetadata.Get(), &spChildMetadata)))
    {
        // spChildMetadata now is an empty store.  If a key queried from
        // it does not exist there, it will be queried from spMetadata.
        // This can be useful to override properties on some store without
        // modifying or copying it.
    }
}
```

## See also

[IDataModelManager interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelmanager)