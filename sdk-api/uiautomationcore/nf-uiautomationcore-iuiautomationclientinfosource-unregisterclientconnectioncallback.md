# UnregisterClientConnectionCallback function

## Description

Unregisters a previously registered connection callback.

## Parameters

### `handle` [in]

A handle to the previously registered callback.

## Return value

S_OK - If the callback unregistered successfully.

S_FALSE - If the *handle* is not found (callback may have already been unregistered).

E_INVALIDARG - If the handle value is invalid.

## Remarks

Safe to call multiple times with the same handle.

After successful unregistration, the callback will no longer be invoked.

The callback interface can be released after successful unregistration.

## See also

[RegisterClientConnectionCallback](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nf-uiautomationcore-iuiautomationclientinfosource-registerclientconnectioncallback)