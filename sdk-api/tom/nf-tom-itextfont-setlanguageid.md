# ITextFont::SetLanguageID

## Description

Sets the language ID or language code identifier (LCID).

## Parameters

### `Value` [in]

Type: **long**

The new language identifier. The low word contains the language identifier. The high word is either zero or it contains the high word of the locale identifier LCID. For more information, see [Locale Identifiers](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers).

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The font object is attached to a range that has been deleted. |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## Remarks

If the high nibble of *Value* is [tomCharset](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants), set the *charrep* from the *charset* in the low byte and the pitch and family from the next byte. See also [ITextFont2::SetCharRep](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont2-setcharrep).

If the high nibble of *Value* is [tomCharRepFromLcid](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants), set the *charrep* from the LCID and set the LCID as well. See [ITextFont::GetLanguageID](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-getlanguageid) for more information.

To set the BCP-47 language tag, such as "en-US", call [ITextRange2::SetText2](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange2-settext2) and set the [tomLanguageTag](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants) and *bstr* with the language tag.

## See also

**Conceptual**

[GetLanguageID](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-getlanguageid)

[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)