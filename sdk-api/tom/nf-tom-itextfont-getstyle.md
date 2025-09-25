# ITextFont::GetStyle

## Description

Gets the character style handle of the characters in a range.

## Parameters

### `pValue`

Type: **long***

The character style handle.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The font object is attached to a range that was deleted. |

For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

## Remarks

The Text Object Model (TOM) version 1.0 does not specify the meanings of the style handles. The meanings depend on other facilities of the text system that implements TOM.

## See also

**Conceptual**

[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)

**Reference**

[SetStyle](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-setstyle)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)