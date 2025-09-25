# ITextPara::GetListLevelIndex

## Description

Retrieves the list level index used with paragraphs.

## Parameters

### `pValue`

Type: **long***

A variable that is the list level index. The value of *pValue* can be one of the following.

| Value | Meaning |
| --- | --- |
| 0 | No list. |
| 1 | First-level (outermost) list. |
| 2 | Second-level (nested) list. This is nested under a level 1 list item. |
| 3 | Third-level (nested) list. This is nested under a level 2 list item. |
| and so forth | Nesting continues similarly. |

Up to three levels are common in HTML documents.

## Return value

Type: **HRESULT**

If **ITextPara::GetListLevelIndex** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## See also

**Conceptual**

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[SetListLevelIndex](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setlistlevelindex)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)