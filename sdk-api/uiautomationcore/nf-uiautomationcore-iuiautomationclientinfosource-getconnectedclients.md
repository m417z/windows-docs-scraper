# GetConnectedClients function

## Description

Retrieves information about currently connected UI Automation clients.

## Parameters

### `clients` [out, retval]

A SAFEARRAY of [IUIAutomationClientInfo](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nn-uiautomationcore-iuiautomationclientinfo) interface pointers.

## Return value

S_OK - If the UI Automation client information was retrieved successfully or the *clients* SAFEARRAY is empty (no clients connected).

E_INVALIDARG - If *clients* is null.

E_OUTOFMEMORY - If memory allocation for the client array failed.

## Remarks

Caller must destroy the SAFEARRAY using the [SafeArrayDestroy function](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-safearraydestroy).

The returned interfaces provide a snapshot at the time of the call.

Client connections may change between calls to this method.

## See also