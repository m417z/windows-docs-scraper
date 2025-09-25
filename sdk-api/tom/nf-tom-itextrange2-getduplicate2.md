# ITextRange2::GetDuplicate2

## Description

Gets a duplicate of a range object.

## Parameters

### `ppRange` [out, retval]

Type: **ITextRange2****

The duplicate range.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If this range is an [ITextSelection2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextselection2) object, the duplicate returned is an [ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2) object. See the [ITextRange::FindText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-findtext) method for more information.

## See also

[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)