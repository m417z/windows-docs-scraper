# ITextFont2::IsEqual2

## Description

Determines whether this text font object has the same properties as the specified text font object.

## Parameters

### `pFont` [in]

Type: **[ITextFont2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont2)***

The text font object to compare against.

### `pB` [out]

Type: **long***

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-rich-edit-controls) value that is **tomTrue** if the font objects have the same properties, or **tomFalse** if they don't. This parameter can be **NULL**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 For two text font objects to be equal, both must belong to the same Text Object Model (TOM) object.

The **ITextFont::IsEqual2** method ignores entries for which either font object has a [tomUndefined](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants) value.

## See also

[ITextFont2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont2)

[ITextFont::IsEqual](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-isequal)