# IStorage::MoveElementTo

## Description

The **MoveElementTo** method copies or moves a substorage or stream from this storage object to another storage object.

## Parameters

### `pwcsName` [in]

Pointer to a wide character null-terminated Unicode string that contains the name of the element in this storage object to be moved or copied.

### `pstgDest` [in]

[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) pointer to the destination storage object.

### `pwcsNewName` [in]

Pointer to a wide character null-terminated unicode string that contains the new name for the element in its new storage object.

### `grfFlags` [in]

Specifies whether the operation should be a move (STGMOVE_MOVE) or a copy (STGMOVE_COPY). See the
[STGMOVE](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-stgmove) enumeration.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The storage object was successfully copied or moved.|
|E_PENDING | Asynchronous Storage only: Part or all of the element's data is currently unavailable. |
|STG_E_ACCESSDENIED | The destination storage object is a child of the source storage object. Or, the destination object and element name are the same as the source object and element name. In other words, you cannot move an element to itself.|
|STG_E_FILENOTFOUND | The element with the specified name does not exist.|
|STG_E_FILEALREADYEXISTS | The specified file already exists.|
|STG_E_INSUFFICIENTMEMORY | The copy or move was not completed due to a lack of memory.|
|STG_E_INVALIDFLAG | The value for the *grfFlags* parameter is not valid.|
|STG_E_INVALIDNAME | Not a valid value for *pwcsName*.|
|STG_E_INVALIDPOINTER | The pointer specified for the storage object was not valid.|
|STG_E_INVALIDPARAMETER | One of the parameters was not valid.|
|STG_E_REVERTED | The storage object has been invalidated by a revert operation above it in the transaction tree.|
|STG_E_TOOMANYOPENFILES | The copy or move was not completed because there are too many open files.|

## Remarks

The **IStorage::MoveElementTo** method is typically the same as invoking the
[IStorage::CopyTo](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-copyto) method on the indicated element and then removing the source element. In this case, the
**MoveElementTo** method uses only the publicly available functions of the destination storage object to carry out the move.

If the source and destination storage objects have special knowledge about each other's implementation (they could, for example, be different instances of the same implementation), this method can be implemented more efficiently.

Before calling this method, the element to be moved must be closed, and the destination storage must be open. Also, the destination object and element cannot be the same storage object/element name as the source of the move. That is, you cannot move an element to itself.

## See also

[IStorage - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istorage-compound-file-implementation)

[IStorage::CopyTo](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-copyto)

[STGMOVE](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-stgmove)