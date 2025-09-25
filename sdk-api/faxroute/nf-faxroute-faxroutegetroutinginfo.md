# FaxRouteGetRoutingInfo function

## Description

The **FaxRouteGetRoutingInfo** function queries the fax routing extension DLL to obtain routing configuration data for a specific fax device. Each fax routing extension DLL must export the **FaxRouteGetRoutingInfo** function.

## Parameters

### `RoutingGuid` [in]

Type: **LPCWSTR**

Pointer to a constant null-terminated Unicode character string that contains the GUID for the fax routing method.

### `DeviceId` [in]

Type: **DWORD**

Specifies the identifier of the fax device to query.

### `RoutingInfo` [in]

Type: **LPBYTE**

Pointer to a buffer that receives the fax routing configuration data.

### `RoutingInfoSize` [out]

Type: **LPDWORD**

Pointer to an unsigned **DWORD** variable that specifies the size, in bytes, of the buffer pointed to by the *RoutingInfo* parameter. For more information, see the following Remarks section.

## Return value

Type: **BOOL**

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, the fax service calls [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The fax service calls the **FaxRouteGetRoutingInfo** function twice. On the first call to the function the fax service passes a null pointer in the *RoutingInfo* parameter. The fax routing extension DLL must set the *RoutingInfoSize* parameter to the size required for the *RoutingInfo* buffer. The fax service calls **FaxRouteGetRoutingInfo** a second time with a valid pointer to the *RoutingInfo* buffer.

## See also

[Fax Routing Extension Application Programming Interface Overview](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-about-the-fax-routing-extension-api)

[Fax Routing Extension Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-routing-extension-functions)

[FaxRouteSetRoutingInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nf-faxroute-faxroutesetroutinginfo)