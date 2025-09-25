# IStorage::DestroyElement

## Description

The
**DestroyElement** method
removes the specified storage or stream from this storage object.

## Parameters

### `pwcsName` [in]

A pointer to a wide character null-terminated Unicode string that contains the name of the storage or stream to be removed.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The element was successfully removed.|
|E_PENDING | Asynchronous Storage only: Part or all of the element data is currently unavailable. |
|STG_E_ACCESSDENIED | The caller does not have permissions to remove the element.|
|STG_E_FILENOTFOUND | The element with the specified name does not exist.|
|STG_E_INSUFFICIENTMEMORY | The element was not removed due to a lack of memory.|
|STG_E_INVALIDNAME | Invalid value for *pwcsName*.|
|STG_E_INVALIDPOINTER | The pointer specified for the element was not valid.|
|STG_E_INVALIDPARAMETER | One of the parameters was not valid.|
|STG_E_REVERTED | The storage object has been invalidated by a revert operation above it in the transaction tree.|
|STG_E_TOOMANYOPENFILES | The element was not removed because there are too many open files.|

## Remarks

The
**DestroyElement** method deletes a substorage or stream from the current storage object. After a successful call to
**DestroyElement**, any open instance of the destroyed element from the parent storage becomes invalid.

If a storage object is opened in the transacted mode, destruction of an element requires that the call to
**DestroyElement** be followed by a call to [IStorage::Commit](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-commit).

**Note** The **DestroyElement** method does not shrink the directory stream. It only marks the deleted directory entry as invalid. Invalid entries are reused when creating a new storage or stream.

For content streams, the deleted stream sectors are marked as free. If the free sectors are at the end of the file, the document file should shrink. To compact a document file, call **IStorage::CopyTo** on the root storage object and copy to a new storage object.

## See also

[IStorage - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istorage-compound-file-implementation)