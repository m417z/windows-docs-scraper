# ITextPara::GetTab

## Description

Retrieves tab parameters (displacement, alignment, and leader style) for a specified tab.

## Parameters

### `iTab`

Type: **long**

Index of tab for which to retrieve info. It can be either a numerical index or a special value (see the following table). Since tab indexes are zero-based, *iTab* = zero gets the first tab defined, *iTab* = 1 gets the second tab defined, and so forth. The following table summarizes all of the possible values of *iTab*.

| *iTab* | Value | Meaning |
| --- | --- | --- |
| tomTabBack | –3 | Get tab previous to * *ptbPos* |
| tomTabNext | –2 | Get tab following * *ptbPos* |
| tomTabHere | –1 | Get tab at * *ptbPos* |
|  | >= 0 | Get tab with index of *iTab* (and ignore *ptbPos*). |

### `ptbPos`

Type: **float***

The tab displacement, in floating-point points. The value of * *ptbPos* is zero if the tab does not exist and the value of * *ptbPos* is tomUndefined if there are multiple values in the associated range.

### `ptbAlign`

Type: **long***

The tab alignment. For more information, see [ITextPara::AddTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-addtab).

### `ptbLeader`

Type: **long***

The tab leader-character style. For more information, see [ITextPara::AddTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-addtab).

## Return value

Type: **HRESULT**

If **ITextPara::GetTab** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |
| **S_FALSE** | There is no tab corresponding to iTab. |

## See also

[AddTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-addtab)

[ClearAllTabs](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-clearalltabs)

**Conceptual**

[DeleteTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-deletetab)

[GetListTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getlisttab)

[GetTabCount](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-gettabcount)

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[SetListTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setlisttab)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)