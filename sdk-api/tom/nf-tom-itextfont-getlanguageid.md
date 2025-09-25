# ITextFont::GetLanguageID

## Description

Gets the language ID or language code identifier (LCID).

## Parameters

### `pValue`

Type: **long***

The language ID or LCID. The low word contains the language identifier. The high word is either zero or it contains the high word of the LCID. To retrieve the language identifier, mask out the high word. For more information, see [Locale Identifiers](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers).

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The font object is attached to a range that has been deleted. |

## Remarks

To get the BCP-47 language tag, such as "en-US", call `ITextRange2::GetText2(pBstr, tomLanguageTag)`, where *pBstr* specifies the desired language tag.

## See also

**Conceptual**

[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)

**Reference**

[SetLanguageID](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-setlanguageid)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)