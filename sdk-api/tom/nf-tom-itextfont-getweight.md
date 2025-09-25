# ITextFont::GetWeight

## Description

Gets the font weight for the characters in a range.

## Parameters

### `pValue`

Type: **long***

The font weight. The
Bold property is a binary version of the
Weight property that sets the weight to **FW_BOLD**. The font weight exists in the
[LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure and the
[IFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ifont) interface. Windows defines the following degrees of font weight.

| Font weight | Value |
| --- | --- |
| **FW_DONTCARE** | 0 |
| **FW_THIN** | 100 |
| **FW_EXTRALIGHT** | 200 |
| **FW_LIGHT** | 300 |
| **FW_NORMAL** | 400 |
| **FW_MEDIUM** | 500 |
| **FW_SEMIBOLD** | 600 |
| **FW_BOLD** | 700 |
| **FW_EXTRABOLD** | 800 |
| **FW_HEAVY** | 900 |

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The font object is attached to a range that has been deleted. |

## See also

**Conceptual**

[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)

**Reference**

[SetWeight](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-setweight)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)