# IFont::SetRatio

## Description

Converts the scaling factor for this font between logical units and **HIMETRIC** units.
**HIMETRIC** units are used to express the point size in the
[IFont::get_Size](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-get_size) and
[IFont::put_Size](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-put_size) methods. The values passed to
**IFont::SetRatio** are used to compute the display size of
the font in logical units from the value in the **Size** property:

`Display Size = ( cyLogical / cyHimetric ) * Size`

## Parameters

### `cyLogical` [in]

The font size, in logical units.

### `cyHimetric` [in]

The font size, in **HIMETRIC** units.

## Return value

The method supports the standard return values E_UNEXPECTED, E_INVALIDARG, and S_OK.

## See also

[IFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ifont)

[IFont::get_Size](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-get_size)

[IFont::put_Size](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-put_size)