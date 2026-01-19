# RegisterClientConnectionCallback function

## Description

Registers a connection callback.

## Parameters

### `callback` [in]

The callback that is being registered.

### `handle` [out]

A handle to the callback (for later unregistration).

## Return value

S_OK - If the callback was registered successfully.

E_INVALIDARG - If the callback or handle parameter is null.

E_OUTOFMEMORY - If memory allocation for registration failed.

## Remarks

Multiple callbacks can be registered and will be called in order.

The callback interface must remain valid until explicitly unregistered.

Store the returned handle to unregister the callback later.

Callbacks are invoked synchronously on the UIA system thread.

## See also

[UnregisterClientConnectionCallback function](https://learn.microsoft.com/windows/win32/api/uiautomationcore/nf-uiautomationcore-iuiautomationclientinfosource-unregisterclientconnectioncallback)