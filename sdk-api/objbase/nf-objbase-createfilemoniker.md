# CreateFileMoniker function

## Description

Creates a file moniker based on the specified path.

## Parameters

### `lpszPathName` [in]

The path on which this moniker is to be based.

This parameter can specify a relative path, a UNC path, or a drive-letter-based path. If based on a relative path, the resulting moniker must be composed onto another file moniker before it can be bound.

### `ppmk` [out]

The address of an [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)* pointer variable that receives the interface pointer to the new file moniker. When successful, the function has called [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the file moniker and the caller is responsible for calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). When an error occurs, the value of the interface pointer is **NULL**.

## Return value

This function can return the standard return value E_OUTOFMEMORY, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The moniker was created successfully. |
| **MK_E_SYNTAX** | There was an error in the syntax of the path. |

## Remarks

**CreateFileMoniker** creates a moniker for an object that is stored in a file. A moniker provider (an object that provides monikers to other objects) can call this function to create a moniker to identify a file-based object that it controls, and can then make the pointer to this moniker available to other objects. An object identified by a file moniker must also implement the [IPersistFile](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersistfile) interface so it can be loaded when a file moniker is bound.

When each object resides in its own file, as in an OLE server application that supports linking only to file-based documents in their entirety, file monikers are the only type of moniker necessary. To identify objects smaller than a file, the moniker provider must use another type of moniker (such as an item moniker) in addition to file monikers, creating a composite moniker. Composite monikers would be needed in an OLE server application that supports linking to objects smaller than a document (such as sections of a document or embedded objects).

A file moniker can be composed to the right only of another file moniker when the first moniker is based on an absolute path and the other is a relative path, resulting in a single file moniker based on the combination of the two paths. A moniker composed to the right of another moniker must be a refinement of that moniker, and the file moniker represents the largest unit of storage. To identify objects stored within a file, you would compose other types of monikers (usually item monikers) to the right of a file moniker.

## See also

[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)