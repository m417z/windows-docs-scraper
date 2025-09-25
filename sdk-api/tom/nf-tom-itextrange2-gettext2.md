# ITextRange2::GetText2

## Description

Gets the text in this range according to the specified conversion flags.

## Parameters

### `Flags` [in]

Type: **long**

The flags controlling how the text is retrieved. The flags can include a combination of the following values. Specifying a *Flags* value of 0 is the same as calling the [ITextRange::GetText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-gettext) method.

#### tomAdjustCRLF

#### tomUseCRLF

#### tomIncludeNumbering

#### tomNoHidden

#### tomNoMathZoneBrackets

#### tomTextize

#### tomAllowFinalEOP

#### tomTranslateTableCell

#### tomFoldMathAlpha

#### tomLanguageTag

### `pbstr` [out]

Type: **BSTR***

The text in the range.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## Remarks

This method includes the special flag **tomLanguageTag** to get the BCP-47 language tag for the range. This is an industry standard language tag which may be preferable to the language code identifier (LCID) obtained by calling [ITextFont::GetLanguageID](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-getlanguageid).

## See also

[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)

[ITextRange2::SetText2](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange2-settext2)