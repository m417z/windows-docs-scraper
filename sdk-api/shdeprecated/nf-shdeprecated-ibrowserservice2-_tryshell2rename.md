# IBrowserService2::_TryShell2Rename

## Description

Deprecated. Coordinates the renaming of the current browser view when the browser is redirected.

## Parameters

### `psv` [in]

Type: **[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)***

A pointer to an [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) representing the current browser view.

### `pidlNew` [in]

Type: **LPCITEMIDLIST**

A PIDL that indicates the new name of the browser view.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is called in response to [NotifyRedirect](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nf-shdeprecated-ibrowserservice-notifyredirect).