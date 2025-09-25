# IUIAutomationElement7::FindFirstWithOptions

## Description

Finds the first matching element in the specified order.

## Parameters

### `scope` [in]

A combination of values specifying the scope of the search.

### `condition` [in]

A pointer to a condition that represents the criteria to match.

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