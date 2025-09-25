# IUIAutomationElement7::FindAllWithOptionsBuildCache

## Description

Finds all matching elements in the specified order, but also caches their properties and patterns.

## Parameters

### `scope` [in]

Type: **[TreeScope](https://learn.microsoft.com/windows/win32/api/uiautomationclient/ne-uiautomationclient-treescope)**

The scope of the request.

When an element is retrieved, caching can be performed for only the element itself (the default behavior), or for the element and its children or descendants. This property describes the scope of the request.

### `condition` [in]

Type: **[IUIAutomationCondition](https://learn.microsoft.com/windows/win32/api/uiautomationclient/nn-uiautomationclient-iuiautomationcondition)**

The primary interface for conditions used in filtering when searching for elements in the UI Automation tree.

### `cacheRequest` [in]

Type: **[IUIAutomationCacheRequest](https://learn.microsoft.com/windows/win32/api/uiautomationclient/nn-uiautomationclient-iuiautomationcacherequest)**

A pointer to a cache request that specifies the control patterns and properties to include in the cache.

### `traversalOptions` [in]

Type: **[TreeTraversalOptions](https://learn.microsoft.com/windows/win32/api/uiautomationclient/ne-uiautomationclient-treetraversaloptions)**

The tree navigation order.

### `root` [in]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/win32/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)**

A pointer to the element with which to begin the search.

### `found` [out, retval]

Receives a pointer to an array of matching elements. Returns an empty array if no matching element is found.

## Return value

Returns **S_OK** if successful, otherwise an **HRESULT** error code.

## See also

[IUIAutomationElement7](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement7)