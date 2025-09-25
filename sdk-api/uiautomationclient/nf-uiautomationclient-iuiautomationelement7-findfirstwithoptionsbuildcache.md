# IUIAutomationElement7::FindFirstWithOptionsBuildCache

## Description

Finds the first matching element in the specified order, but also caches its properties and pattern.

## Parameters

### `scope` [in]

A combination of values specifying the scope of the search.

### `condition` [in]

A pointer to a condition that represents the criteria to match.

### `cacheRequest` [in]

A pointer to a cache request that specifies the control patterns and properties to include in the cache.

### `traversalOptions`

Enumeration value specifying the tree navigation order.

### `root` [in, optional]

A pointer to the element with which to begin the search.

### `found` [out, retval]

Receives a pointer to the element. **NULL** is returned if no matching element is found.

## Return value

Returns **S_OK** if successful, otherwise an **HRESULT** error code.

## See also

[IUIAutomationElement7](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement7)