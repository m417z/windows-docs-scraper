# FaxRouteSetRoutingInfo function

## Description

The **FaxRouteSetRoutingInfo** function modifies routing configuration data for a specific fax device. Each fax routing extension DLL must export the **FaxRouteSetRoutingInfo** function.

## Parameters

### `RoutingGuid` [in]

Type: **LPCWSTR**

Pointer to a constant null-terminated Unicode character string that contains the GUID for the fax routing method.

### `DeviceId` [in]

Type: **DWORD**

Specifies the device identifier of the fax device that will have its routing configuration data modified.

### `RoutingInfo` [in]

Type: **const BYTE***

Pointer to a buffer that provides the fax routing configuration data.

### `RoutingInfoSize` [in]

Type: **DWORD**

Specifies the size, in bytes, of the buffer pointed to by the *RoutingInfo* parameter.

## Return value

Type: **BOOL**

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, the fax service calls [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The fax service calls the **FaxRouteSetRoutingInfo** function to modify routing configuration data for a specific fax device.

## See also

[Fax Routing Extension Application Programming Interface Overview](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-about-the-fax-routing-extension-api)

[Fax Routing Extension Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-routing-extension-functions)

[FaxRouteGetRoutingInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nf-faxroute-faxroutegetroutinginfo)