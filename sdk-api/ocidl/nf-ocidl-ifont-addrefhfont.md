# IFont::AddRefHfont

## Description

Notifies the font object that the previously realized font identified with *hFont* should remain valid until [ReleaseHfont](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-releasehfont) is called or the font object itself is released completely.

## Parameters

### `hFont` [in]

Font handle previously realized through [get_hFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-get_hfont) to be locked in the font object's cache.

## Return value

The method supports the standard return values **E_UNEXPECTED** and **E_INVALIDARG**, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The font was successfully locked in the cache. |

## See also

[IFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ifont)

[ReleaseHfont](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-releasehfont)

[get_hFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-get_hfont)