# IPersistFile::IsDirty

## Description

Determines whether an object has changed since it was last saved to its current file.

## Return value

This method returns S_OK to indicate that the object has changed. Otherwise, it returns S_FALSE.

## Remarks

Use this method to determine whether an object should be saved before closing it. The dirty flag for an object is conditionally cleared in the [IPersistFile::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-save) method.

### Notes to Callers

OLE does not call **IsDirty**. Applications would not call it unless they are also saving an object to a file.

You should treat any error return codes as an indication that the object has changed. Unless this method explicitly returns S_FALSE, assume that the object must be saved.

### Notes to Implementers

An object with no contained objects simply checks its dirty flag to return the appropriate result.

A container with one or more contained objects must maintain an internal dirty flag that is set when any of its contained objects has changed since it was last saved. To do this, the container should maintain an advise sink by implementing the [IAdviseSink](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink) interface. Then, the container can register each link or embedding for data change notifications with a call to [IDataObject::DAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dadvise). Then, the container can set its internal dirty flag when it receives an [IAdviseSink::OnDataChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-ondatachange) notification. If the container does not register for data change notifications, the **IPersistFile::IsDirty** implementation would call [IPersistStorage::IsDirty](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-isdirty) for each of its contained objects to determine whether they have changed.

The container can clear its dirty flag whenever it is saved, as long as the file to which the object is saved is the current working file after the save. Therefore, the dirty flag would be cleared after a successful **Save** or **Save As** operation, but not after a **Save A Copy As . . .** operation.

## See also

[IAdviseSink::OnDataChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-ondatachange)

[IDataObject::DAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dadvise)

[IPersistFile](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersistfile)