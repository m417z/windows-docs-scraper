# IUIAutomationVirtualizedItemPattern::Realize

## Description

Creates a full UI Automation element for a virtualized item.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A virtualized item is represented by a placeholder automation element in the UI Automation tree. The **Realize** method causes the provider to make full information available for the item so that a full UI Automation element can be created for the item.

## See also

**Conceptual**

[IUIAutomationVirtualizedItemPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationvirtualizeditempattern)

**Reference**

[Working with Virtualized Items](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-workingwithvirtualizeditems)