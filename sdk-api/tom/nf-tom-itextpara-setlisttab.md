# ITextPara::SetListTab

## Description

Sets the list tab setting, which is the distance between the first indent and the start of the text on the first line.

## Parameters

### `Value` [in]

Type: **float**

New list tab value, in floating-point points.

## Return value

Type: **HRESULT**

If **ITextPara::SetListTab** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Invalid argument. |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## See also

[AddTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-addtab)

[ClearAllTabs](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-clearalltabs)

**Conceptual**

[DeleteTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-deletetab)

[GetListTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getlisttab)

[GetTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-gettab)

[GetTabCount](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-gettabcount)

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)