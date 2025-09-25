# WSMAN_SHELL_DISCONNECT_INFO structure

## Description

Specifies the maximum duration, in milliseconds, the shell will stay open after the client has disconnected.

## Members

### `idleTimeoutMs`

Specifies the maximum time in milliseconds that the shell will stay open after the client has disconnected. When this maximum duration has been exceeded, the shell will be deleted. Specifying this value overrides the initial idle timeout value that is set as part of the [WSMAN_SHELL_STARTUP_INFO](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_shell_startup_info_v10) structure in the [WSManCreateShell](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancreateshell) method.

## Remarks

When the maximum duration is exceeded, the shell is automatically deleted. This value overrides the initial idle timeout that is set as part of [WSMAN_SHELL_STARTUP_INFO](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_shell_startup_info_v10) structure in [WSManCreateShell](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancreateshell).