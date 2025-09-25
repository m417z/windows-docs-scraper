# ITextFont::GetSize

## Description

Gets the font size.

## Parameters

### `pValue`

Type: **float***

The font size, in floating-point points.

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

[SetSize](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-setsize)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)