# OfflineFilesQueryStatus function

## Description

Determines whether the Offline Files feature is enabled and, if so, whether it is active.

## Parameters

### `pbActive` [out]

Receives **TRUE** if both the CSC driver and Offline Files Service are in the running state, or **FALSE** otherwise. This parameter is optional and can be **NULL**.

### `pbEnabled` [out]

Receives **TRUE** if the CSC driver's start type is set to **SERVICE_SYSTEM_START** and the Offline Files service's start type is set to **SERVICE_AUTO_START**, or **FALSE** otherwise. This parameter is optional and can be **NULL**.

## Return value

Returns **ERROR_SUCCESS** if successful or a Win32 error value otherwise.

## Remarks

If the values returned in the *pbActive* and *pbEnabled* parameters are not both **TRUE**, the caller must restart the computer to enable or disable the Offline Files feature. If one of the values is still **FALSE** after the computer is restarted, check the system event logs to identify the problem with starting either the CSC driver or the Offline Files service.

## See also

[OfflineFilesQueryStatusEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscapi/nf-cscapi-offlinefilesquerystatusex)