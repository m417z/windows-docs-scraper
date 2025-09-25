# ITextPara::ClearAllTabs

## Description

Clears all tabs, reverting to equally spaced tabs with the default tab spacing.

## Return value

Type: **HRESULT**

If **ITextPara::ClearAllTabs** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **CO_E_RELEASED** | The paragraph format object is attached to a range that has been deleted. |

## See also

[AddTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-addtab)

**Conceptual**

[DeleteTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-deletetab)

[GetDefaultTabStop](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-getdefaulttabstop)

[GetListTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getlisttab)

[GetTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-gettab)

[GetTabCount](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-gettabcount)

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[SetListTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setlisttab)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)