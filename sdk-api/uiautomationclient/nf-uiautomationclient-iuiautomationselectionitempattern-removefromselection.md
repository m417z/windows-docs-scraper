# IUIAutomationSelectionItemPattern::RemoveFromSelection

## Description

Removes this element from the selection.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An error code is returned if this element is the only one in the selection and the selection container requires at least one element to be selected.

## See also

[AddToSelection](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationselectionitempattern-addtoselection)

[CurrentIsSelectionRequired](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationselectionpattern-get_currentisselectionrequired)

[IUIAutomationSelectionItemPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationselectionitempattern)

[Select](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationselectionitempattern-select)