# UiaRemoveEvent function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Removes a listener for events on a node in the UI Automation tree.

## Parameters

### `hEvent` [in]

Type: **HUIAEVENT**

The event to remove. This value was retrieved from [UiaAddEvent](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/nf-uiautomationcoreapi-uiaaddevent).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.

## Remarks

The callback pointer, the scope, the node, and the list of properties must match exactly the parameters that were sent to the
corresponding [UiaAddEvent](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/nf-uiautomationcoreapi-uiaaddevent).