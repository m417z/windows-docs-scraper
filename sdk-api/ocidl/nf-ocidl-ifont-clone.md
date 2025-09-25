# IFont::Clone

## Description

Creates a duplicate font object with a state identical to the current font.

## Parameters

### `ppFont` [out]

Address of [IFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ifont) pointer variable that receives the interface
pointer to the new font object. The caller must call
[IFont::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) when this new font object is no longer
needed.

## Return value

The method supports the standard return values **E_UNEXPECTED** and
**E_OUTOFMEMORY**, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The new font object was successfully created. |
| **E_NOTIMPL** | This font object does not support cloning. |
| **E_POINTER** | The address in *ppfont* is not valid. For example, it may be **NULL**. |

## Remarks

### Notes to Callers

The new font object is entirely independent of the first. The caller is responsible for releasing this new
object when it is no longer needed. This method does not affect the reference count of the font being cloned.

## See also

[IFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ifont)