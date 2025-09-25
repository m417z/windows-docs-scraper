# ITextStory::GetText

## Description

Gets the text in a story according to the specified conversion flags.

## Parameters

### `Flags` [in]

Type: **long**

The conversion flags.

A *Flags* value of 0 retrieves text the same as [ITextRange::GetText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-gettext). Other values include the following.

#### tomAdjustCRLF

#### tomAllowFinalEOP

#### tomFoldMathAlpha

#### tomIncludeNumbering

#### tomNoHidden

#### tomNoMathZoneBrackets

#### tomLanguageTag

#### tomTextize

#### tomTranslateTableCell

#### tomUseCRLF

### `pbstr` [out]

Type: **BSTR***

The text in the story.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## Remarks

This method is similar to using [ITextRange2::GetText2](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange2-gettext2) for a whole story, but it doesn’t require a range.

## See also

[ITextStory](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstory)

[ITextStory::SetText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextstory-settext)