# ITextRange2::Find

## Description

Searches for math inline functions in text as specified by a source range.

## Parameters

### `pRange` [in]

Type: **[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)***

The formatted text to find in the range's text.

### `Count` [in]

Type: **long**

The number of characters to search through.

### `Flags` [in]

Type: **long**

Flags that control the search as defined for [ITextRange::FindText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-findtext).

### `pDelta` [out]

Type: **long***

A count of the number of characters bypassed.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the string is found, and the math inline functions, if any, are the same as their counterparts in the source range, the range limits are changed to be those of the matched string and length is set equal to the length of the string.

If the string isn't found, the range remains unchanged and length is set equal to 0.

## See also

[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)