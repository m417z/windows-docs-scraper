# ICommDlgBrowser2::Notify

## Description

Called by a Shell view to notify the common dialog box hosting it that an event has occurred.

## Parameters

### `ppshv`

Type: **[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)***

A pointer to the [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) interface of the hosted view.

### `dwNotifyType`

Type: **DWORD**

A flag that can take one of the following two values.

#### CDB2N_CONTEXTMENU_START

Indicates that the shortcut menu is about to be displayed.

#### CDB2N_CONTEXTMENU_DONE

Indicates that the shortcut menu is no longer displayed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ICommDlgBrowser2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icommdlgbrowser2)