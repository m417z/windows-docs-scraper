# CdromEnableDigitalPlayback function

## Description

Enables digital playback for the specified CD-ROM or DVD drive.

## Parameters

### `DevInfo` [in]

A handle to a device information set listing the devices for which information is to be returned. This handle is typically returned by the **SetupDiGetClassDevs** or **SetupDiGetClassDevsEx** function.

### `DevInfoData` [in]

A pointer to an **SP_DEVINFO_DATA** structure that defines the device instance.

### `ForceUnknown` [in]

If this member is **TRUE**, playback is enabled even if the drive is not known to be good.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is an error code.

## Remarks

To disable digital playback for the specified CD-ROM or DVD drive, use the [CdromDisableDigitalPlayback](https://learn.microsoft.com/windows/desktop/api/storprop/nf-storprop-cdromdisabledigitalplayback) function. To determine whether digital playback is enabled or disabled, use the [CdromIsDigitalPlaybackEnabled](https://learn.microsoft.com/windows/desktop/api/storprop/nf-storprop-cdromisdigitalplaybackenabled) function.

This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to StorProp.dll.

## See also

[CdromDisableDigitalPlayback](https://learn.microsoft.com/windows/desktop/api/storprop/nf-storprop-cdromdisabledigitalplayback)

[CdromIsDigitalPlaybackEnabled](https://learn.microsoft.com/windows/desktop/api/storprop/nf-storprop-cdromisdigitalplaybackenabled)

[CdromKnownGoodDigitalPlayback](https://learn.microsoft.com/windows/desktop/api/storprop/nf-storprop-cdromknowngooddigitalplayback)

[Device Management Functions](https://learn.microsoft.com/windows/desktop/DevIO/device-management-functions)