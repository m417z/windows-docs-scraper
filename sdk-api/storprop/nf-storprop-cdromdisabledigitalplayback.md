# CdromDisableDigitalPlayback function

## Description

Disables digital playback for the specified CD-ROM or DVD drive.

## Parameters

### `DevInfo` [in]

A handle to a device information set listing the devices for which information is to be returned. This handle is typically returned by the [SetupDiGetClassDevs](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdevsw) or [SetupDiGetClassDevsEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdevsexa) function.

### `DevInfoData` [in]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that defines the device instance.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is an error code.

## Remarks

To enable digital playback for the specified CD-ROM or DVD drive, use the [CdromEnableDigitalPlayback](https://learn.microsoft.com/windows/desktop/api/storprop/nf-storprop-cdromenabledigitalplayback) function. To determine whether digital playback is enabled or disabled, use the [CdromIsDigitalPlaybackEnabled](https://learn.microsoft.com/windows/desktop/api/storprop/nf-storprop-cdromisdigitalplaybackenabled) function.

This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to StorProp.dll.

## See also

[CdromEnableDigitalPlayback](https://learn.microsoft.com/windows/desktop/api/storprop/nf-storprop-cdromenabledigitalplayback)

[CdromIsDigitalPlaybackEnabled](https://learn.microsoft.com/windows/desktop/api/storprop/nf-storprop-cdromisdigitalplaybackenabled)

[Device Management Functions](https://learn.microsoft.com/windows/desktop/DevIO/device-management-functions)