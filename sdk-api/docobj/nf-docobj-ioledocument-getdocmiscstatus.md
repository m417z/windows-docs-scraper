# IOleDocument::GetDocMiscStatus

## Description

Retrieves status information about the document object.

## Parameters

### `pdwStatus` [out]

A pointer to the information on supported behaviors. Possible values are taken from the [DOCMISC](https://learn.microsoft.com/windows/win32/api/docobj/ne-docobj-docmisc) enumeration.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The address in *pdwStatus* is **NULL**. |

## Remarks

This method provides a way for containers to ascertain whether a document object supports multiple views, complex rectangles, opening in a pop-up window, or file read/write.

Values from this enumerator are also stored in the registry as the value of the DocObject key.

### Notes to Callers

By calling this method prior to activating a document object, containers can take whatever steps are necessary to support or otherwise accommodate the specified behaviors.

### Notes to Implementers

This method must be completely implemented in any document object, even if the dereferenced value of *pdwStatus* is zero. E_NOTIMPL is not an acceptable return value. Normally, the returned [DOCMISC](https://learn.microsoft.com/windows/win32/api/docobj/ne-docobj-docmisc) value should be hard-coded for performance.

## See also

[DOCMISC](https://learn.microsoft.com/windows/win32/api/docobj/ne-docobj-docmisc)

[IOleDocument](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocument)