# IStorage::RenameElement

## Description

The **RenameElement** method renames the specified substorage or stream in this storage object.

## Parameters

### `pwcsOldName` [in]

Pointer to a wide character null-terminated Unicode string that contains the name of the substorage or stream to be changed.

**Note** The *pwcsName*, created in [CreateStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-createstorage) or [CreateStream](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-createstream) must not exceed 31 characters in length, not including the string terminator.

### `pwcsNewName` [in]

Pointer to a wide character null-terminated unicode string that contains the new name for the specified substorage or stream.

**Note** The *pwcsName*, created in [CreateStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-createstorage) or [CreateStream](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-createstream) must not exceed 31 characters in length, not including the string terminator.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The element was successfully renamed.|
|E_PENDING | Asynchronous Storage only: Part or all of the element's data is currently unavailable.|
|STG_E_ACCESSDENIED | The caller does not have enough permissions for renaming the element.|
|STG_E_FILENOTFOUND | The element with the specified old name does not exist.|
|STG_E_FILEALREADYEXISTS | The element specified by the new name already exists.|
|STG_E_INSUFFICIENTMEMORY | The element was not renamed due to a lack of memory.|
|STG_E_INVALIDNAME | Invalid value for one of the names.|
|STG_E_INVALIDPOINTER | The pointer specified for the element was not valid.|
|STG_E_INVALIDPARAMETER | One of the parameters was not valid.|
|STG_E_REVERTED | The storage object has been invalidated by a revert operation above it in the transaction tree.|
|STG_E_TOOMANYOPENFILES | The element was not renamed because there are too many open files.|

## Remarks

**IStorage::RenameElement** renames the specified substorage or stream in this storage object. An element in a storage object cannot be renamed while it is open. The rename operation is subject to committing the changes if the storage is open in transacted mode.

The **IStorage::RenameElement** method is not guaranteed to work in low memory with storage objects open in transacted mode. It may work in direct mode.

## See also

[IStorage - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istorage-compound-file-implementation)