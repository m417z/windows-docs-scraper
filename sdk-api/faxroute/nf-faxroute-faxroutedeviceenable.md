# FaxRouteDeviceEnable function

## Description

The **FaxRouteDeviceEnable** function allows a fax routing extension DLL to query, enable, or disable a fax routing method for a specific fax device. Each fax routing extension must export the **FaxRouteDeviceEnable** function.

## Parameters

### `RoutingGuid` [in]

Type: **LPCWSTR**

Pointer to a constant null-terminated Unicode character string that contains the GUID for the fax routing method of interest.

### `DeviceId` [in]

Type: **DWORD**

Specifies a **DWORD** variable that is the device identifier for the fax device of interest.

### `Enabled` [in]

Type: **LONG**

Specifies an enabled status for the fax routing method and fax device combination specified by the *RoutingGuid* and *DeviceId* parameters.

The *Enabled* parameter can have one of the following values.

#### QUERY_STATUS

Return the current status of the specified routing method on the specified fax device. A value of **TRUE** indicates the routing method is enabled on the device; a value of **FALSE** indicates the routing method is disabled on the device.

#### STATUS_DISABLE

Disable the specified fax routing method on the specified fax device.

#### STATUS_ENABLE

Enable the specified fax routing method on the specified fax device.

## Return value

Type: **BOOL**

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, the fax service calls [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

This function will return ERROR_BAD_CONFIGURATION if you attempt to refer to a device that is not configured, such as a folder that has not been specified, or a printer that does not exist on your network.

## See also

[Fax Routing Extension Application Programming Interface Overview](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-about-the-fax-routing-extension-api)

[Fax Routing Extension Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-routing-extension-functions)

[FaxRouteDeviceChangeNotification](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nf-faxroute-faxroutedevicechangenotification)