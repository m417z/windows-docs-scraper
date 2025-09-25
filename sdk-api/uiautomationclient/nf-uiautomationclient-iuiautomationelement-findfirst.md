# IUIAutomationElement::FindFirst

## Description

Retrieves the first child or descendant element that matches the specified condition.

## Parameters

### `scope` [in]

Type: **[TreeScope](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-treescope)**

A combination of values specifying the scope of the search.

### `condition` [in]

Type: **[IUIAutomationCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcondition)***

A pointer to a condition that represents the criteria to match.

### `found` [out, retval]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)****

Receives a pointer to the element. **NULL** is returned if no matching element is found.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The scope of the search is relative to the element on which the method is called. Elements are returned in the order in which they were encountered in the tree.

This function cannot search for ancestor elements in the Microsoft UI Automation tree; that is, [TreeScope_Ancestors](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-treescope) is not a valid value for the *scope* parameter.

When searching for top-level windows on the desktop, be sure to specify [TreeScope_Children](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-treescope) in the *scope* parameter, not [TreeScope_Descendants](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-treescope). A search through the entire subtree of the desktop could iterate through thousands of items and lead to a stack overflow.

If your client application might try to find elements in its own user interface, you must make all UI Automation calls on a separate thread.

This function ignores elements in the raw tree. Call [FindFirstBuildCache](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-findfirstbuildcache) to search the raw tree by specifying the appropriate [TreeScope](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-treescope) on the [IUIAutomationCacheRequest](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcacherequest) passed to that function.

## See also

**Conceptual**

[FindAll](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-findall)

[FindAllBuildCache](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-findallbuildcache)

[FindFirstBuildCache](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-findfirstbuildcache)

[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)

[Obtaining UI Automation Elements](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-obtainingelements)

**Reference**