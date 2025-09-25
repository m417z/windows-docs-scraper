# OfflineFilesQueryStatusEx function

## Description

Determines whether the Offline Files feature is enabled and, if so, whether it is active and available. This function is identical to the [OfflineFilesQueryStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscapi/nf-cscapi-offlinefilesquerystatus) function, except that it has an additional output parameter.

## Parameters

### `pbActive` [out]

Receives **TRUE** if both the CSC driver and Offline Files Service are in the running state, or **FALSE** otherwise. This parameter is optional and can be **NULL**.

### `pbEnabled` [out]

Receives **TRUE** if the CSC driver's start type is set to **SERVICE_SYSTEM_START** and the Offline Files service's start type is set to **SERVICE_AUTO_START**, or **FALSE** otherwise. This parameter is optional and can be **NULL**.

### `pbAvailable` [out]

Receives **TRUE** if the Offline Files Service is ready to be started without requiring the computer to be restarted, or **FALSE** otherwise. This parameter is optional and can be **NULL**.

## Return value

Returns **ERROR_SUCCESS** if successful or a Win32 error value otherwise.

## Remarks

If the *pbAvailable* parameter is **TRUE** on return, the caller can use the [OfflineFilesStart](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscapi/nf-cscapi-offlinefilesstart) function to start the Offline Files feature.

## See also

[OfflineFilesQueryStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscapi/nf-cscapi-offlinefilesquerystatus)