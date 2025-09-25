# IUIAutomationElement::FindFirstBuildCache

## Description

Retrieves the first child or descendant element that matches the specified condition, prefetches the requested properties and control patterns, and stores the prefetched items in the cache.

## Parameters

### `scope` [in]

Type: **[TreeScope](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-treescope)**

A combination of values specifying the scope of the search.

### `condition` [in]

Type: **[IUIAutomationCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcondition)***

A pointer to a condition that represents the criteria to match.

### `cacheRequest` [in]

Type: **[IUIAutomationCacheRequest](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcacherequest)***

A pointer to a cache request that specifies the control patterns and properties to include in the cache.

### `found` [out, retval]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)****

Receives a pointer to the matching element, or **NULL** if no matching element is found.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The scope of the search is relative to the element on which the method is called. Elements are returned in the order in which they were encountered in the tree.

This function cannot search for ancestor elements in the Microsoft UI Automation tree; that is, [TreeScope_Ancestors](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-treescope) is not a valid value for the *scope* parameter.

When searching for top-level windows on the desktop, be sure to specify [TreeScope_Children](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-treescope) in the *scope* parameter, not [TreeScope_Descendants](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-treescope). A search through the entire subtree of the desktop could iterate through thousands of items and lead to a stack overflow.

If your client application might try to find elements in its own user interface, you must make all UI Automation calls on a separate thread.

To search the raw tree, specify the appropriate [TreeScope](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-treescope) in the *cacheRequest* parameter.

## See also

[Caching UI Automation Properties and Control Patterns](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-cachingforclients)

**Conceptual**

[FindAll](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-findall)

[FindAllBuildCache](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-findallbuildcache)

[FindFirst](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-findfirst)

[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)

[Obtaining UI Automation Elements](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-obtainingelements)

**Reference**