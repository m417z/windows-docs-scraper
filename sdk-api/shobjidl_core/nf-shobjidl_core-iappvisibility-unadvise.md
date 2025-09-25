# IAppVisibility::Unadvise

## Description

Cancels a connection that was previously established by using [Advise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iappvisibility-advise).

## Parameters

### `dwCookie` [in]

A token that uniquely identifies the connection to cancel, which is provided by a previous call to the [Advise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iappvisibility-advise) method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAppVisibility](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iappvisibility)

[IAppVisibilityEvents](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iappvisibilityevents)