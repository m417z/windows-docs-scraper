# CdromIsDigitalPlaybackEnabled function

## Description

Determines whether digital playback is enabled for the specified CD-ROM or DVD drive.

## Parameters

### `DevInfo` [in]

A handle to a device information set listing the devices for which information is to be returned. This handle is typically returned by the **SetupDiGetClassDevs** or **SetupDiGetClassDevsEx** function.

### `DevInfoData` [in]

A pointer to an **SP_DEVINFO_DATA** structure that defines the device instance.

### `Enabled` [out]

A pointer to a variable that receives **TRUE** if digital playback is enabled, and **FALSE** otherwise.

## Return value

If the function succeeds the return value is **ERROR_SUCCESS**. Otherwise, it is an error code.

## Remarks

To enable digital playback for the specified CD-ROM or DVD drive, use the [CdromEnableDigitalPlayback](https://learn.microsoft.com/windows/desktop/api/storprop/nf-storprop-cdromenabledigitalplayback) function. To disable digital playback for the specified CD-ROM or DVD drive, use the [CdromDisableDigitalPlayback](https://learn.microsoft.com/windows/desktop/api/storprop/nf-storprop-cdromdisabledigitalplayback) function.

This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to StorProp.dll.

## See also

[CdromDisableDigitalPlayback](https://learn.microsoft.com/windows/desktop/api/storprop/nf-storprop-cdromdisabledigitalplayback)

[CdromEnableDigitalPlayback](https://learn.microsoft.com/windows/desktop/api/storprop/nf-storprop-cdromenabledigitalplayback)

[Device Management Functions](https://learn.microsoft.com/windows/desktop/DevIO/device-management-functions)