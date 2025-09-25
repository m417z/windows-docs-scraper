# ITextPara::GetLeftIndent

## Description

Retrieves the distance used to indent all lines except the first line of a paragraph. The distance is relative to the left margin.

## Parameters

### `pValue`

Type: **float***

The left indentation, in floating-point points.

## Return value

Type: **HRESULT**

If **ITextPara::GetLeftIndent** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## Remarks

To set the left indentation amount, call the [ITextPara::SetIndents](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setindents) method.

To get the first-line indent, call [ITextPara::GetFirstLineIndent](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getfirstlineindent).

## See also

**Conceptual**

[GetFirstLineIndent](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getfirstlineindent)

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[SetIndents](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setindents)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)