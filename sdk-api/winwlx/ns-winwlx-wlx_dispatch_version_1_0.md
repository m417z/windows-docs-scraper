# WLX_DISPATCH_VERSION_1_0 structure

## Description

[The WLX_DISPATCH_VERSION_1_0 structure is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **WLX_DISPATCH_VERSION_1_0** structure defines the format of the [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) version 1.0 function dispatch table passed to your [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLL in the
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) call.

This dispatch table is used if your GINA DLL specifies version 1.0 in its implementation of
[WlxNegotiate](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxnegotiate).

## Members

### `WlxUseCtrlAltDel`

Pointer to a [WlxUseCtrlAltDel](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_use_ctrl_alt_del) function.

### `WlxSetContextPointer`

Pointer to a [WlxSetContextPointer](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_set_context_pointer) function.

### `WlxSasNotify`

Pointer to a [WlxSasNotify](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_sas_notify) function.

### `WlxSetTimeout`

Pointer to a [WlxSetTimeout](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_set_timeout) function.

### `WlxAssignShellProtection`

Pointer to a [WlxAssignShellProtection](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_assign_shell_protection) function.

### `WlxMessageBox`

Pointer to a [WlxMessageBox](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_message_box) function.

### `WlxDialogBox`

Pointer to a [WlxDialogBox](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_dialog_box) function.

### `WlxDialogBoxParam`

Pointer to a [WlxDialogBoxParam](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_dialog_box_param) function.

### `WlxDialogBoxIndirect`

Pointer to a [WlxDialogBoxIndirect](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_dialog_box_indirect) function.

### `WlxDialogBoxIndirectParam`

Pointer to a [WlxDialogBoxIndirectParam](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_dialog_box_indirect_param) function.

### `WlxSwitchDesktopToUser`

Pointer to a [WlxSwitchDesktopToUser](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_switch_desktop_to_user) function.

### `WlxSwitchDesktopToWinlogon`

Pointer to a [WlxSwitchDesktopToWinlogon](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_switch_desktop_to_winlogon) function.

### `WlxChangePasswordNotify`

Pointer to a [WlxChangePasswordNotify](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_change_password_notify) function.

## See also

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)