# IUIAutomationExpandCollapsePattern::Expand

## Description

Displays all child nodes, controls, or content of the element.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This is a blocking method that returns after the element has been expanded.

There are cases when a element that is marked as a leaf node might not know whether it has children until either the [IUIAutomationExpandCollapsePattern::Collapse](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationexpandcollapsepattern-collapse) or the **IUIAutomationExpandCollapsePattern::Expand** method is called. This behavior is possible with a tree view control that does delayed loading of its child items. For example, Microsoft Windows Explorer might display the expand icon for a node even though there are currently no child items; when the icon is clicked, the control polls for child items, finds none, and removes the expand icon. In these cases clients should listen for a property-changed event on the [IUIAutomationExpandCollapsePattern::CurrentExpandCollapseState](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationexpandcollapsepattern-get_currentexpandcollapsestate) property.

## See also

[IUIAutomationExpandCollapsePattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationexpandcollapsepattern)