# ITextPara::GetTabCount

## Description

Retrieves the tab count.

## Parameters

### `pCount`

Type: **long***

The tab count.

## Return value

Type: **HRESULT**

If **ITextPara::GetTabCount** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## Remarks

The tab count of a new instance can be nonzero, depending on the underlying text engine. For example, Microsoft Word stories begin with no explicit tabs defined, while rich edit instances start with a single explicit tab. To be sure there are no explicit tabs (that is, to set the tab count to zero), call [ITextPara::ClearAllTabs](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-clearalltabs).

## See also

[AddTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-addtab)

[ClearAllTabs](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-clearalltabs)

**Conceptual**

[DeleteTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-deletetab)

[GetListTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getlisttab)

[GetTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-gettab)

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[SetListTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setlisttab)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)