# IPersistStorage::Save

## Description

Saves an object, and any nested objects that it contains, into the specified storage object. The object enters NoScribble mode.

## Parameters

### `pStgSave` [in]

An [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) pointer to the storage into which the object is to be saved.

### `fSameAsLoad` [in]

Indicates whether the specified storage is the current one, which was passed to the object by one of the following calls: [IPersistStorage::InitNew](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-initnew), [IPersistStorage::Load](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-load), or [IPersistStorage::SaveCompleted](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-savecompleted).

This parameter is set to **FALSE** when performing a **Save As** or **Save A Copy To** operation or when performing a full save. In the latter case, this method saves to a temporary file, deletes the original file, and renames the temporary file.

This parameter is set to **TRUE** to perform a full save in a low-memory situation or to perform a fast incremental save in which only the dirty components are saved.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **STG_E_MEDIUMFULL** | The object was not saved because of a lack of space on the disk. |
| **E_FAIL** | The object could not be saved due to errors other than a lack of disk space. |

## Remarks

This method saves an object, and any nested objects it contains, into the specified storage. It also places the object into NoScribble mode. Thus, the object cannot write to its storage until a subsequent call to the [IPersistStorage::SaveCompleted](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-savecompleted) method returns the object to Normal mode.

If the storage object is the same as the one it was loaded or created from, the save operation may be able to write incremental changes to the storage object. Otherwise, a full save must be done.

This method recursively calls the **IPersistStorage::Save** method, the [OleSave](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesave) function, or the [IStorage::CopyTo](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-copyto) method to save its nested objects.

This method does not call the [IStorage::Commit](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-commit) method. Nor does it write the CLSID to the storage object. Both of these tasks are the responsibilities of the caller.

### Notes to Callers

Rather than calling **IPersistStorage::Save** directly, you typically call the [OleSave](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesave) helper function which performs the following steps:

1. Call the [WriteClassStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-writeclassstg) function to write the class identifier for the object to the storage.
2. Call the **IPersistStorage::Save** method.
3. If needed, call the [IStorage::Commit](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-commit) method on the storage object.

Then, a container application performs any other operations necessary to complete the save and calls the [SaveCompleted](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-savecompleted) method for each object.

If an embedded object passes the **IPersistStorage::Save** method to its nested objects, it must receive a call to its [IPersistStorage::SaveCompleted](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-savecompleted) method before calling this method for its nested objects.

## See also

[IPersistStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststorage)

[OleSave](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesave)