# ITextStrings::EncodeFunction

## Description

Encodes an object, given a set of argument strings.

## Parameters

### `Type` [in]

Type: **long**

The object type. See [ITextRange2::GetInlineObject](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange2-getinlineobject) for a table of definitions.

### `Align` [in]

Type: **long**

The object alignment. See [ITextRange2::GetInlineObject](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange2-getinlineobject) for a table of definitions.

### `Char` [in]

Type: **long**

The object character.

### `Char1` [in]

Type: **long**

The object character.

### `Char2` [in]

Type: **long**

The object character.

### `Count` [in]

Type: **long**

The count of strings (arguments) to concatenate.

### `TeXStyle` [in]

Type: **long**

The TeX style.

### `cCol` [in]

Type: **long**

The count of columns (**tomArray** only).

### `pRange` [in]

Type: **[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)***

The specifying range that points at the desired formatting.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

See [ITextRange2::GetInlineObject](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange2-getinlineobject) for a more detailed discussion of the arguments.

## See also

[ITextStrings](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstrings)