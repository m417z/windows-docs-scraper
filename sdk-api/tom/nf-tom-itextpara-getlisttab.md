# ITextPara::GetListTab

## Description

Retrieves the list tab setting, which is the distance between the first-line indent and the text on the first line. The numbered or bulleted text is left-justified, centered, or right-justified at the first-line indent value.

## Parameters

### `pValue`

Type: **float***

The list tab setting. The list tab value is in floating-point points.

## Return value

Type: **HRESULT**

If **ITextPara::GetListTab** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## Remarks

To determine whether the numbered or bulleted text is left-justified, centered, or right-justified, call [ITextPara::GetListAlignment](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getlistalignment).

## See also

[AddTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-addtab)

[ClearAllTabs](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-clearalltabs)

**Conceptual**

[DeleteTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-deletetab)

[GetFirstLineIndent](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getfirstlineindent)

[GetListAlignment](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getlistalignment)

[GetTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-gettab)

[GetTabCount](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-gettabcount)

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[SetListTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setlisttab)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)