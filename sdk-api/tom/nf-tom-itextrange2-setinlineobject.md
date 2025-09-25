# ITextRange2::SetInlineObject

## Description

Sets or inserts the properties of an inline object for a degenerate range.

## Parameters

### `Type` [in]

Type: **long**

The object type as defined in [ITextRange2::GetInlineObject](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange2-getinlineobject).

### `Align` [in]

Type: **long**

The object alignment as defined in [ITextRange2::GetInlineObject](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange2-getinlineobject).

### `Char` [in]

Type: **long**

The object character as defined in [ITextRange2::GetInlineObject](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange2-getinlineobject).

### `Char1` [in]

Type: **long**

The closing bracket ([tomBrackets](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype)) character. See [Unicode Technical Note 28](https://www.unicode.org/notes/tn28/) for a list of characters.

### `Char2` [in]

Type: **long**

The separator character for [tomBracketsWithSeps](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype), which can be one of the following values.

### `Count` [in]

Type: **long**

The number of arguments in the inline object.

### `TeXStyle` [in]

Type: **long**

The TeX style, as defined in [ITextRange2::GetInlineObject](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange2-getinlineobject).

### `cCol` [in]

Type: **long**

The number of columns in the inline object. For [tomMatrix](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-objecttype) only.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)

[ITextRange2::GetInlineObject](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange2-getinlineobject)