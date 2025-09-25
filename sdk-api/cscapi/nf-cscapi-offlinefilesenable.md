# OfflineFilesEnable function

## Description

Enables or disables the Offline Files feature.

## Parameters

### `bEnable` [in]

Specify **TRUE** to enable Offline Files, or **FALSE** to disable.

### `pbRebootRequired` [out]

Receives **TRUE** if a system restart is necessary to apply the desired configuration, or **FALSE** otherwise.

## Return value

Returns **ERROR_SUCCESS** if successful or a Win32 error value otherwise.

## Remarks

The Offline Files feature is implemented in two parts, the Offline Files service and the CSC driver. When the Offline Files feature is enabled, this means that the CSC driver's start type is set to SERVICE_SYSTEM_START and the Offline Files service's start type is set to SERVICE_AUTO_START. If the driver is not already running, the caller must restart the computer after calling this method.

Disabling Offline Files disables both the service and the driver. To disable the feature, the caller must restart the computer after calling this method.

The caller must be an administrator on the local computer.