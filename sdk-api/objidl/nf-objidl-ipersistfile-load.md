# IPersistFile::Load

## Description

Opens the specified file and initializes an object from the file contents.

## Parameters

### `pszFileName` [in]

The absolute path of the file to be opened.

### `dwMode` [in]

The access mode to be used when opening the file. Possible values are taken from the [STGM](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants) enumeration. The method can treat this value as a suggestion, adding more restrictive permissions if necessary. If *dwMode* is 0, the implementation should open the file using whatever default permissions are used when a user opens the file.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_OUTOFMEMORY** | The object could not be loaded due to a lack of memory. |
| **E_FAIL** | The object could not be loaded for some reason other than a lack of memory. |

## Remarks

**IPersistFile::Load** loads the object from the specified file. This method is for initialization only and does not show the object to the end user. It is not equivalent to what occurs when a user selects the **File Open** command.

### Notes to Callers

The [BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject) method in file monikers calls this method to load an object during a moniker binding operation (when a linked object is run). Typically, applications do not call this method directly.

### Notes to Implementers

Because the information needed to open a file varies greatly from one application to another, the object on which this method is implemented must also open the file specified by the *pszFileName* parameter. This differs from the [IPersistStorage::Load](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-load) and [IPersistStream::Load](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststream-load), in which the caller opens the storage or stream and then passes an open storage or stream pointer to the loaded object.

For an application that normally uses OLE compound files, your **IPersistFile::Load** implementation can simply call the [StgOpenStorage](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenstorage) function to open the storage object in the specified file. Then, you can proceed with normal initialization. Applications that do not use storage objects can perform normal file-opening procedures.

When the object has been loaded, your implementation should register the object in the running object table (see [IRunningObjectTable::Register](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunningobjecttable-register)).

## See also

[IPersistFile](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersistfile)