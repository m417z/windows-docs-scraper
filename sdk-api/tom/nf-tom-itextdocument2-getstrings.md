# ITextDocument2::GetStrings

## Description

Gets a collection of rich-text strings.

## Parameters

### `ppStrs` [out]

Type: **[ITextStrings](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstrings)****

The collection of rich-text strings.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The collection is useful for manipulating rich text, particularly for transforming mathematical text from linear to built-up form, or vice versa.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)