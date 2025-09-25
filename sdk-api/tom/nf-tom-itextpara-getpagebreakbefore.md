# ITextPara::GetPageBreakBefore

## Description

Determines whether each paragraph in the range must begin on a new page.

## Parameters

### `pValue`

Type: **long***

A variable that is one of the following values:

| Value | Meaning |
| --- | --- |
| tomTrue | Each paragraph in this range must begin on a new page. |
| tomFalse | The paragraphs in this range do not need to begin on a new page. |
| tomUndefined | The property is undefined. |

## Return value

Type: **HRESULT**

If **ITextPara::GetPageBreakBefore** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## See also

**Conceptual**

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[SetPageBreakBefore](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setpagebreakbefore)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)