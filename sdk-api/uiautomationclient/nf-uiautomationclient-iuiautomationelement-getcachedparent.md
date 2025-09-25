# IUIAutomationElement::GetCachedParent

## Description

Retrieves from the cache the parent of this UI Automation element.

## Parameters

### `parent` [out, retval]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)****

Receives a pointer to the cached parent element.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

**Conceptual**

[GetCachedChildren](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-getcachedchildren)

[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)

[Obtaining UI Automation Elements](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-obtainingelements)

**Reference**

[UI Automation Tree Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-treeoverview)