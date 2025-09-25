# IRootStorage::SwitchToFile

## Description

The
**SwitchToFile** method copies the current file associated with the storage object to a new file. The new file is then used for the storage object and any uncommitted changes.

## Parameters

### `pszFile`

A pointer to a null terminated string that specifies the file name for the new file. It cannot be the name of an existing file. If **NULL**, this method creates a temporary file with a unique name, and you can call
[IStorage::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-stat) to retrieve the name of the temporary file.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The file was successfully copied.|
|STG_E_MEDIUMFULL | The file was not copied because of insufficient space on the storage device.|
|STG_E_ACCESSDENIED | The file was not copied because the caller does not have permission to access storage device.|
|STG_E_INVALIDPOINTER | The file was not copied because the *pszFile* pointer is not valid.|
|STG_E_FILEALREADYEXISTS | The file was not copied because the new filename (*pszFile*) points to an existing file.|

## Remarks

The **IRootStorage::SwitchToFile** method copies the file associated with the storage object. A COM container calls
**SwitchToFile** to perform a full save on a file in a low-memory situation. Typically, this is done only after a normal, full save operation (that is, save to temporary file, delete original file, rename temporary file) has failed with an E_OUTOFMEMORY error.

It is erroneous to call the
**SwitchToFile** method if the storage object or anything contained within it has been marshaled to another process. Before calling
**SwitchToFile**, the container must call the
[IPersistStorage::HandsOffStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-handsoffstorage) method for any element within the storage object that is loaded or running. The **HandsOffStorage** method forces the element to release its storage pointers and enter the hands-off storage mode. The container must also release all pointers to streams or storages that are contained in this root storage. After the full save operation is completed, the container returns the contained elements to normal storage mode.

### Notes to Implementers

If you are implementing your own storage objects, the
[IRootStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irootstorage) methods (including [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)), [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref), and [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release)) must not consume additional memory or file handles.

## See also

[IPersistStorage::HandsOffStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-handsoffstorage)

[IPersistStorage::SaveCompleted](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-savecompleted)

[IStorage::Commit](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-commit)

[IStorage::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-stat)