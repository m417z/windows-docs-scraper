# IFont::ReleaseHfont

## Description

Notifies the font object that the caller that previously locked this font in the cache with
[IFont::AddRefHfont](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-addrefhfont) no longer requires the lock.

## Parameters

### `hFont` [in]

A font handle previously realized through
[IFont::get_hFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-get_hfont). This value was passed to a previous
call to [IFont::AddRefHfont](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-addrefhfont) to lock the font, and the
caller would now like to unlock the font in the cache.

## Return value

The method supports the standard return values **E_UNEXPECTED** and
**E_INVALIDARG**, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The font was unlocked successfully. |
| **S_FALSE** | The font was not locked in the cache. This return value is a benign notification to the caller that it may have a font reference counting problem. |

## See also

[IFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ifont)

[IFont::AddRefHfont](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-addrefhfont)