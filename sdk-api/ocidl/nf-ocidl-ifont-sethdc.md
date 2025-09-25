# IFont::SetHdc

## Description

Provides a device context to the font that describes the logical mapping mode.

## Parameters

### `hDC` [in]

A handle to the device context in which to select the font.

## Return value

The method supports the standard return value **E_INVALIDARG**, as well as the
following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The font was selected successfully. |
| **E_NOTIMPL** | The font selection is not supported through this font object. |

## Remarks

The logical mapping mode affects the font's internal computation of its point size so that when the caller
asks for a font handle by calling [IFont::get_hFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-get_hfont), the
font is already properly scaled to the device context.

### Notes to Callers

The caller retains ownership of this device context which must remain valid for the lifetime of
the font object. Thus, the device context passed should be a memory device context (from the function
[CreateCompatibleDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createcompatibledc)) and not a screen device context
(from [CreateDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdca),
[GetDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdc), or
[BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint)) because screen device contexts are a limited system
resource.

## See also

[IFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ifont)