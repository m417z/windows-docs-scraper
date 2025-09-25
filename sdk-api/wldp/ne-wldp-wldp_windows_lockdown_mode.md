## Description

Describes the secure modes (S modes) for a Windows device. Used primarily in [**WldpQueryWindowsLockdownMode**](https://learn.microsoft.com/windows/win32/api/wldp/nf-wldp-wldpquerywindowslockdownmode).

## Constants

### `WLDP_WINDOWS_LOCKDOWN_MODE_UNLOCKED`

Unlocked. Used primarily for Windows devices without the S mode.

### `WLDP_WINDOWS_LOCKDOWN_MODE_TRIAL`

Trial. Used primarily for a Windows 10 trial device with the S mode. Trial mode is a special case for Windows 10 devices with the S mode: policies are enforced, but there is no anti-rollback protection for the enforcement of the policy.

### `WLDP_WINDOWS_LOCKDOWN_MODE_LOCKED`

Locked. Used primarily for a Windows 10 device with the S mode. A device that is locked will enforce the signed Device Guard policies shipped with the Windows 10 OS image with the S mode.

### `WLDP_WINDOWS_LOCKDOWN_MODE_MAX`

The maximum enumeration value.

## Remarks

## See also