# IPersistStream::GetSizeMax

## Description

Retrieves the size of the stream needed to save the object.

## Parameters

### `pcbSize` [out]

The size in bytes of the stream needed to save this object, in bytes.

## Return value

This method returns S_OK to indicate that the size was retrieved successfully.

## Remarks

This method returns the size needed to save an object. You can call this method to determine the size and set the necessary buffers before calling the [IPersistStream::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststream-save) method.

### Notes to Implementers

The **GetSizeMax** implementation should return a conservative estimate of the necessary size because the caller might call the [IPersistStream::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststream-save) method with a non-growable stream.

### URL Moniker Notes

This method retrieves the maximum number of bytes in the stream that will be required by a subsequent call to [IPersistStream::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststream-save). This value is sizeof(ULONG)==4 plus sizeof(WCHAR)*n where n is the length of the full or partial URL string, including the NULL terminator.

## See also

[IPersistStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststream)