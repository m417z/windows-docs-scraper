# IPersistStorage::IsDirty

## Description

Determines whether an object has changed since it was last saved to its current storage.

## Return value

This method returns S_OK to indicate that the object has changed. Otherwise, it returns S_FALSE.

## Remarks

Use this method to determine whether an object should be saved before closing it. The dirty flag for an object is conditionally cleared in the [IPersistStorage::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-save) method.

For example, you could optimize a **File Save** operation by calling the **IPersistStorage::IsDirty** method for each object and then calling the [IPersistStorage::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-save) method only for those objects that are dirty.

### Notes to Callers

You should treat any error return codes as an indication that the object has changed. Unless this method explicitly returns S_FALSE, assume that the object must be saved.

### Notes to Implementers

An object with no contained objects simply checks its dirty flag to return the appropriate result.

A container with one or more contained objects must maintain an internal dirty flag that is set when any of its contained objects has changed since it was last saved.

## See also

[IPersistStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststorage)