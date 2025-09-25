# IBrowserService2::SetActivateState

## Description

Deprecated. Updates the value of the **_uActivateState** member of the [BASEBROWSERDATA](https://learn.microsoft.com/windows/desktop/api/shdeprecated/ns-shdeprecated-basebrowserdatalh) structure, which tracks whether the browser view window is in an activated state. The derived class makes this call to the base class.

## Parameters

### `u` [in]

Type: **UINT**

The activation state of the window. This is always the SVUIA_ACTIVATE_FOCUS (0x0002) value from the [SVUIA_STATUS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-svuia_status) enumeration defined in Shobjidl.h.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.