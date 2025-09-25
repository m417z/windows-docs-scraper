# IPersistFile::GetCurFile

## Description

Retrieves the current name of the file associated with the object. If there is no current working file, this method retrieves the default save prompt for the object.

## Parameters

### `ppszFileName` [out]

The path for the current file or the default file name prompt (such as *.txt). If an error occurs, *ppszFileName* is set to **NULL**.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | A valid absolute path was returned successfully. |
| **S_FALSE** | The default save prompt was returned. |
| **E_OUTOFMEMORY** | The operation failed due to insufficient memory. |
| **E_FAIL** | The operation failed due to some reason other than insufficient memory. |

## Remarks

This method allocates memory for the string returned in the *ppszFileName* parameter using the [IMalloc::Alloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-alloc) method. The caller is responsible for calling the [IMalloc::Free](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-free) method to free the string. Both the caller and this method use the OLE task allocator provided by a call to [CoGetMalloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetmalloc).

The file name returned in *ppszFileName* is the name specified in a call to [IPersistFile::Load](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-load) when the document was loaded; or in [IPersistFile::SaveCompleted](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-savecompleted) if the document was saved to a different file.

If the object does not have a current working file, it should provide the default prompt that it would display in a **Save As** dialog box. For example, the default save prompt for a word processor object could be

"*.txt".

### Notes to Callers

OLE does not call the **GetCurFile** method. Applications would not call this method unless they are also calling the save methods of this interface.

In saving the object, you can call this method before calling [IPersistFile::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-save) to determine whether the object has an associated file. If this method returns S_OK, you can then call **IPersistFile::Save** with a **NULL** filename and a **TRUE** value for the *fRemember* parameter to tell the object to save itself to its current file. If this method returns S_FALSE, you can use the save prompt returned in the *ppszFileName* parameter to ask the end user to provide a file name. Then, you can call **IPersistFile::Save** with the file name that the user entered to perform a **Save As** operation.

## See also

[IPersistFile](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersistfile)