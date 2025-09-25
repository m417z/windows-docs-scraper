# IExplorerBrowserEvents::OnViewCreated

## Description

Notifies clients that the view of the Explorer browser has been created and can be modified.

## Parameters

### `psv` [in]

Type: **[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)***

A pointer to an [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An Explorer browser calls this method to enable the client to perform any modifications to the Explorer browser view before it is shown; for example, to set view modes or folder flags.