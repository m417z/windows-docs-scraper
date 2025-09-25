# WLX_DISPATCH_VERSION_1_4 structure

## Description

The **WLX_DISPATCH_VERSION_1_4** structure defines the format of the [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) version 1.4 function dispatch table passed to the [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLL in the
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) call.

This dispatch table is used if the GINA DLL specifies version 1.4 in its implementation of
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

### `WlxGetSourceDesktop`

Pointer to a [WlxGetSourceDesktop](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_get_source_desktop) function.

### `WlxSetReturnDesktop`

Pointer to a [WlxSetReturnDesktop](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_set_return_desktop) function.

### `WlxCreateUserDesktop`

Pointer to a [WlxCreateUserDesktop](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_create_user_desktop) function.

### `WlxChangePasswordNotifyEx`

Pointer to a [WlxChangePasswordNotifyEx](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_change_password_notify_ex) function.

### `WlxCloseUserDesktop`

Pointer to a [WlxCloseUserDesktop](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_close_user_desktop) function.

### `WlxSetOption`

Pointer to a [WlxSetOption](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_set_option) function.

### `WlxGetOption`

Pointer to a [WlxGetOption](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_get_option) function.

### `WlxWin31Migrate`

Pointer to a [WlxWin31Migrate](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_win31_migrate) function.

### `WlxQueryClientCredentials`

Pointer to a [WlxQueryClientCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_client_credentials) function.

### `WlxQueryInetConnectorCredentials`

Pointer to a [WlxQueryInetConnectorCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_ic_credentials) function.

### `WlxDisconnect`

Pointer to a [WlxDisconnect](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_disconnect) function.

### `WlxQueryTerminalServicesData`

Pointer to a [WlxQueryTerminalServicesData](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_terminal_services_data) function.

### `WlxQueryConsoleSwitchCredentials`

Pointer to a [WlxQueryConsoleSwitchCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_consoleswitch_credentials) function.

### `WlxQueryTsLogonCredentials`

Pointer to a [WlxQueryTsLogonCredentials](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_ts_logon_credentials) function.