# CdromKnownGoodDigitalPlayback function

## Description

Determines whether the specified CD-ROM or DVD drive has digital playback that is known to be good.

## Parameters

### `HDevInfo` [in]

A handle to a device information set listing the devices for which information is to be returned. This handle is typically returned by the **SetupDiGetClassDevs** or **SetupDiGetClassDevsEx** function.

### `DevInfoData` [in]

A pointer to an **SP_DEVINFO_DATA** structure that defines the device instance.

## Return value

If digital playback is good, the return value is **TRUE**. Otherwise, the return value is **FALSE**.

## Remarks

This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Storprop.dll.

## See also

[Device Management Functions](https://learn.microsoft.com/windows/desktop/DevIO/device-management-functions)