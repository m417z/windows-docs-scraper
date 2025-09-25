# IStorageProviderHandler::GetPropertyHandlerFromUri

## Description

Gets an instance of [IStorageProviderPropertyHandler](https://learn.microsoft.com/windows/desktop/api/storageprovider/nn-storageprovider-istorageproviderpropertyhandler) associated with the provided URI.

## Parameters

### `uri` [in]

The URI for the relevant file.

### `propertyHandler` [out]

An [IStorageProviderPropertyHandler](https://learn.microsoft.com/windows/desktop/api/storageprovider/nn-storageprovider-istorageproviderpropertyhandler) instance associated with the file specified by *uri*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is used to convert a remote URI to a local file system path. That path is then used to provide the *propertyHandler* to the local file.

## See also

[IStorageProviderHandler](https://learn.microsoft.com/windows/desktop/api/storageprovider/nn-storageprovider-istorageproviderhandler)