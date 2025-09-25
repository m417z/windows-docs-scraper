# IUIAutomationElement7::FindAllWithOptions

## Description

Find all matching elements in the specified order.

## Parameters

### `scope`

A combination of values specifying the scope of the search.

### `condition` [in]

A pointer to a condition that represents the criteria to match.

### `traversalOptions`

Enumeration value specifying the tree navigation order.

### `root` [in, optional]

A pointer to the element with which to begin the search.

### `found` [out]

Receives a pointer to an array of matching elements. Returns an empty array if no matching element is found.

## Return value

Returns **S_OK** if successful, otherwise an **HRESULT** error code.

## See also

[IUIAutomationElement7](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement7)