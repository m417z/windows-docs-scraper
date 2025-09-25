# ITextRange2::GetCount

## Description

Gets the count of subranges, including the active subrange in the current range.

## Parameters

### `pCount` [out, retval]

Type: **long***

The count of subranges not including the active one.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If you select a range with no or one character, the count will be 1. But if you select a word and then move to a different location, and select a second word not touching the first, then the count is 2.

See [ITextRange2::AddSubrange](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange2-addsubrange) to add subranges programmatically.

## See also

[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)