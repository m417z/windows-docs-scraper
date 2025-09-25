# ITextFont::SetBackColor

## Description

Sets the background color.

## Parameters

### `Value` [in]

Type: **long**

The new background color. It can be one of the following.

| Value | Meaning |
| --- | --- |
| A [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value. | An RGB color. |
| A value returned by [PALETTEINDEX](https://learn.microsoft.com/previous-versions/dd162770(v=vs.85)) | A palette index. |
| **tomUndefined** | No change. |
| **tomAutoColor** | Use the default background color. |

If *Value* contains an RGB color, generate the [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) by using the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The font object is attached to a range that has been deleted. |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## See also

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

**Conceptual**

[GetBackColor](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-getbackcolor)

[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)

**Other Resources**

[PALETTEINDEX](https://learn.microsoft.com/previous-versions/dd162770(v=vs.85))

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)