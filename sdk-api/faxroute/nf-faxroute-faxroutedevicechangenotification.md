# FaxRouteDeviceChangeNotification function

## Description

The fax service calls the **FaxRouteDeviceChangeNotification** function to inform a fax routing extension DLL that a fax device has been removed from the fax server, or that a new fax device has been installed. Each fax routing extension must export the **FaxRouteDeviceChangeNotification** function.

## Parameters

### `DeviceId` [in]

Type: **DWORD**

Specifies a **DWORD** variable that is the device identifier of the fax device that has been removed or installed.

### `NewDevice` [in]

Type: **BOOL**

Specifies a Boolean variable that indicates whether the *DeviceId* parameter identifies a new device. If this parameter is equal to **TRUE**, the device is a new device. For more information, see the following Remarks section.

## Return value

Type: **BOOL**

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, the fax service calls [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the *NewDevice* parameter is equal to **TRUE**, it indicates that the fax service detects the installation of a new fax device. The fax routing extension must perform any initialization procedures necessary to enable the extension to route inbound fax transmissions using the new device.

If the *NewDevice* parameter is equal to **FALSE**, it indicates that the fax service detects the removal of the fax device identified by the *DeviceId* parameter. The fax routing extension should perform required cleanup routines at this time.

## See also

[Fax Routing Extension Application Programming Interface Overview](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-about-the-fax-routing-extension-api)

[Fax Routing Extension Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-routing-extension-functions)

[FaxRouteDeviceEnable](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nf-faxroute-faxroutedeviceenable)