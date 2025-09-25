# IStorageProviderPropertyHandler::SaveProperties

## Description

Saves properties associated with a file or folder.

## Parameters

### `propertiesToSave` [in]

The properties to save.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Attempting to save properties that are not managed by the sync engine should result in the error code **E_INVALIDARG**.

## See also

[IStorageProviderPropertyHandler](https://learn.microsoft.com/windows/desktop/api/storageprovider/nn-storageprovider-istorageproviderpropertyhandler)