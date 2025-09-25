# ITextRange2::GetCch

## Description

Gets the count of characters in a range.

## Parameters

### `pcch` [out, retval]

Type: **long***

The signed count of characters.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The count of characters is the difference between the character position of the active end of the range, and the character position of the anchor end. Some Text Object Model (TOM) implementations might include active ends only for a selection (represented by the [ITextSelection](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextselection) interface). The rich edit control's TOM implementation of a text range (represented by the [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange) interface) also has active ends.

## See also

[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)