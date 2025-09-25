# IFont::get_hFont

## Description

Retrieves a handle to the font described by this font object.

## Parameters

### `phFont` [out]

A pointer to the caller-allocated variable that receives the font handle.
The caller does not own this resource and must not attempt to destroy the font.

## Return value

The method supports the standard return values **E_UNEXPECTED** and
**E_OUTOFMEMORY**, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The font handle was retrieved successfully. |
| **E_POINTER** | The address in the *phFont* parameter is not valid. For example, it may be **NULL**. |

## Remarks

### Notes to Callers

The font object maintains ownership of the **HFONT** and can destroy it
at any time without prior notification. If the caller needs to secure this font for a limited period of time, it
can call [IFont::AddRefHfont](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-addrefhfont) and
[IFont::ReleaseHfont](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-releasehfont).

## See also

[IFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ifont)

[IFont::AddRefHfont](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-addrefhfont)

[IFont::ReleaseHfont](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-releasehfont)