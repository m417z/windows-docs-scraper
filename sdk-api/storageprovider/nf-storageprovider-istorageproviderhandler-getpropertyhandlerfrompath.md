# IStorageProviderHandler::GetPropertyHandlerFromPath

## Description

Gets an instance of [IStorageProviderPropertyHandler](https://learn.microsoft.com/windows/desktop/api/storageprovider/nn-storageprovider-istorageproviderpropertyhandler) associated with the provided path.

## Parameters

### `path` [in]

The path for the relevant file.

### `propertyHandler` [out]

An [IStorageProviderPropertyHandler](https://learn.microsoft.com/windows/desktop/api/storageprovider/nn-storageprovider-istorageproviderpropertyhandler) instance associated with the file specified by *path*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IStorageProviderHandler](https://learn.microsoft.com/windows/desktop/api/storageprovider/nn-storageprovider-istorageproviderhandler)