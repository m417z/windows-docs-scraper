# IBrowserService2::_UIActivateView

## Description

Deprecated. Allows a derived class to request that the base class update the browser view.

## Parameters

### `uState` [in]

Type: **UINT**

A member of the [SVUIA_STATUS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-svuia_status) enumeration declaring the browser view's state value.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.