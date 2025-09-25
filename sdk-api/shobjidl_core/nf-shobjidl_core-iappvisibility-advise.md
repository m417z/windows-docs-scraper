# IAppVisibility::Advise

## Description

Registers an advise sink object to receive notification of changes to the display.

## Parameters

### `pCallback` [in]

The client's advise sink that receives outgoing calls from the connection point.

### `pdwCookie` [out]

A token that uniquely identifies this connection. Use this token to delete the connection by passing it to the [Unadvise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iappvisibility-unadvise) method.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | *pdwCookie* is **NULL**. |

## See also

[IAppVisibility](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iappvisibility)

[IAppVisibilityEvents](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iappvisibilityevents)