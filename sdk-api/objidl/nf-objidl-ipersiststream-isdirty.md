# IPersistStream::IsDirty

## Description

Determines whether an object has changed since it was last saved to its stream.

## Return value

This method returns S_OK to indicate that the object has changed. Otherwise, it returns S_FALSE.

## Remarks

Use this method to determine whether an object should be saved before closing it. The dirty flag for an object is conditionally cleared in the [IPersistStream::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststream-save) method.

### Notes to Callers

You should treat any error return codes as an indication that the object has changed. Unless this method explicitly returns S_FALSE, assume that the object must be saved.

Note that the OLE-provided implementations of the **IPersistStream::IsDirty** method in the OLE-provided moniker interfaces always return S_FALSE because their internal state never changes.

## See also

[IPersistStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststream)