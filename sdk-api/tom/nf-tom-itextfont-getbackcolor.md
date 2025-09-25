# ITextFont::GetBackColor

## Description

Gets the text background (highlight) color.

## Parameters

### `pValue`

Type: **long***

The text background color. It can be one of the following values.

| Value | Meaning |
| --- | --- |
| A [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value | The high-order byte is zero, and the three low-order bytes specify an RGB color. |
| A value returned by [PALETTEINDEX](https://learn.microsoft.com/previous-versions/dd162770(v=vs.85)) | The high-order byte is 1, and the [LOWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632659(v=vs.85)) specifies the index of a logical-color palette entry. |
| **tomAutocolor** (-9999997) | Indicates the range uses the default system background color. |

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The font object is attached to a range that has been deleted. |

## See also

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

**Conceptual**

[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)

**Other Resources**

[PALETTEINDEX](https://learn.microsoft.com/previous-versions/dd162770(v=vs.85))

**Reference**

[SetBackColor](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-setbackcolor)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)