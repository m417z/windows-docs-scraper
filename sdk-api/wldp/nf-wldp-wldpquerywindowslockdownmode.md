## Description

Retrieves the current Windows secure mode. Windows can be in locked mode, unlocked normal mode, or trial mode.

## Parameters

### `lockdownMode`

On success, returns a [**PWLDP\_WINDOWS\_LOCKDOWN\_MODE**](https://learn.microsoft.com/windows/win32/api/wldp/ne-wldp-wldp_windows_lockdown_mode) that indicates the secure mode for the current Windows 10 device.

## Return value

This method returns **S\_OK** if successful or a failure code otherwise.

## Remarks

## See also