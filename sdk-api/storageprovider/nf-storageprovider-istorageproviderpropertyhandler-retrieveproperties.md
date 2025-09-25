# IStorageProviderPropertyHandler::RetrieveProperties

## Description

Gets the properties managed by the sync engine.

## Parameters

### `propertiesToRetrieve` [in]

The identifier for the properties to retrieve.

### `propertiesToRetrieveCount` [in]

The number of properties to retrieve.

### `retrievedProperties` [out]

A collection of properties.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the file or folder cannot be found, this method should return **S_OK**, but *retrievedProperties* should be empty.

Any properties that are not managed by the sync engine should return **VT_EMPTY** for those properties.

## See also

[IStorageProviderPropertyHandler](https://learn.microsoft.com/windows/desktop/api/storageprovider/nn-storageprovider-istorageproviderpropertyhandler)