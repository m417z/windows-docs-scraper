# IProtectionPolicyManagerInterop::GetForWindow

## Description

**Note** Windows Information Protection (WIP) policy can be applied on Windows 10, version 1607.

Returns the protection policy manager object associated with the current app window.

## Parameters

### `appWindow` [in]

A handle to the current window.

### `riid` [iid_is] [in, retval]

 Reference to the identifier of the interface describing the type of interface pointer to return in *result*.

### `result`

The protection policy manager object for the current window.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IProtectionPolicyManagerInterop](https://learn.microsoft.com/previous-versions/windows/desktop/api/efswrtinterop/nn-efswrtinterop-iprotectionpolicymanagerinterop)