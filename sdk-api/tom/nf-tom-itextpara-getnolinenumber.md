# ITextPara::GetNoLineNumber

## Description

Determines whether paragraph numbering is enabled.

## Parameters

### `pValue`

Type: **long***

A variable that is one of the following values:

| Value | Meaning |
| --- | --- |
| tomTrue | Line numbering is disabled. |
| tomFalse | Line numbering is enabled. |
| tomUndefined | The property is undefined. |

## Return value

Type: **HRESULT**

If **ITextPara::GetNoLineNumber** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## Remarks

Paragraph numbering is when the paragraphs of a range are numbered. The number appears on the first line of a paragraph.

## See also

**Conceptual**

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[SetNoLineNumber](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setnolinenumber)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)