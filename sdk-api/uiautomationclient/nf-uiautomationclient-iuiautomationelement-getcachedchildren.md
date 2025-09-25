# IUIAutomationElement::GetCachedChildren

## Description

Retrieves the cached child elements of this UI Automation element.

## Parameters

### `children` [out, retval]

Type: **[IUIAutomationElementArray](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelementarray)****

Receives a pointer to a collection of the cached child elements.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The view of the returned collection is determined by the TreeFilter property of the [IUIAutomationCacheRequest](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcacherequest) that was active when this element was obtained.

Children are cached only if the scope of the cache request included [TreeScope_Subtree](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-treescope), [TreeScope_Children](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-treescope), or [TreeScope_Descendants](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-treescope).

If the cache request specified that children were to be cached at this level, but there are no children, the value of this property is 0. However, if no request was made to cache children at this level, an attempt to retrieve the property returns an error.

## See also

**Conceptual**

[GetCachedParent](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-getcachedparent)

[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)

[Obtaining UI Automation Elements](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-obtainingelements)

**Reference**

[UI Automation Tree Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-treeoverview)