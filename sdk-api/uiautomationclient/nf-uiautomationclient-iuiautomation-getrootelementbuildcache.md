# IUIAutomation::GetRootElementBuildCache

## Description

Retrieves the UI Automation element that represents the desktop, prefetches the requested properties and control patterns, and stores the prefetched items in the cache.

## Parameters

### `cacheRequest` [in]

Type: **[IUIAutomationCacheRequest](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcacherequest)***

A pointer to the cache request, which specifies the properties and control patterns to store in the cache.

### `root` [out, retval]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)****

Receives a pointer to the UI Automation element.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You can use the root element as a starting point for finding other elements, using the [FindAll](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-findall) and [FindFirst](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-findfirst) methods.

When searching from the root element, be sure to specify [TreeScope_Children](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-treescope) in the scope of the search, not [TreeScope_Descendants](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-treescope). A search through the entire subtree of the desktop could iterate through thousands of items and lead to a stack overflow.

## See also

[IUIAutomation](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomation)

[IUIAutomation::GetRootElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-getrootelement)