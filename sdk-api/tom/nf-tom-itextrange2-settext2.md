# ITextRange2::SetText2

## Description

Sets the text of this range.

## Parameters

### `Flags` [in]

Type: **long**

Flags controlling how the text is inserted in the range. The flag can be one of the following values:

#### tomUnicodeBiDi

#### tomMathCFCheck

#### tomUnlink

#### tomUnhide

#### tomCheckTextLimit

#### tomLanguageTag

### `bstr` [in]

Type: **BSTR**

The new text.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## Remarks

If the *bstr* parameter is **NULL**, the text in the range is deleted.

This method is similar to [ITextRange:: SetText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-settext), but lets the client specify flags that control various insertion options, including the special flag **tomLanguageTag** to get the BCP-47 language tag for the range. This is an industry standard language tag that may be preferable to [ITextFont::SetLanguageID](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-setlanguageid), which uses a language code identifier (LCID).

## See also

[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)

[ITextRange2::GetText2](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange2-gettext2)