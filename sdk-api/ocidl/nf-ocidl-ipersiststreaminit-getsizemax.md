# IPersistStreamInit::GetSizeMax

## Description

Retrieves the size of the stream needed to save the object.

## Parameters

### `pCbSize` [out]

The size in bytes of the stream needed to save this object, in bytes.

## Return value

This method returns S_OK to indicate that the size was retrieved successfully.

## Remarks

This method returns the size needed to save an object. You can call this method to determine the size and set the necessary buffers before calling the [IPersistStreamInit::Save](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipersiststreaminit-save) method.

### Notes to Implementers

The **GetSizeMax** implementation should return a conservative estimate of the necessary size because the caller might call the [IPersistStreamInit::Save](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipersiststreaminit-save) method with a non-growable stream.

## See also

[IPersistStreamInit](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipersiststreaminit)