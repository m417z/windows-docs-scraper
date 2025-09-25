# ITextPara::GetFirstLineIndent

## Description

Retrieves the amount used to indent the first line of a paragraph relative to the left indent. The left indent is the indent for all lines of the paragraph except the first line.

## Parameters

### `pValue`

Type: **float***

The first-line indentation amount in floating-point points.

## Return value

Type: **HRESULT**

If **ITextPara::GetFirstLineIndent** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## Remarks

To set the first line indentation amount, call the [ITextPara::SetIndents](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setindents) method.

To get and set the indent for all other lines of the paragraph (that is, the left
indent), use [ITextPara::GetLeftIndent](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getleftindent) and [ITextPara::SetIndents](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setindents).

## See also

**Conceptual**

[GetLeftIndent](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getleftindent)

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[SetIndents](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setindents)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)