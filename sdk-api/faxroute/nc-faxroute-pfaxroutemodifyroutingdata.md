# PFAXROUTEMODIFYROUTINGDATA callback function

## Description

A fax routing method calls the *FaxRouteModifyRoutingData* callback function to modify the routing data for a subsequent fax routing method.

## Parameters

### `JobId` [in]

Type: **DWORD**

Specifies a unique number that identifies the fax job that received the fax document.

### `RoutingGuid` [in]

Type: **LPCWSTR**

Pointer to a constant null-terminated Unicode character string that specifies the GUID of the fax routing method to modify.

### `RoutingData` [in]

Type: **LPBYTE**

Pointer to a buffer that contains additional routing data defined by the routing extension. For more information, see the following Remarks section.

The fax routing method that calls the *FaxRouteModifyRoutingData* function and the routing method specified by the *RoutingGuid* parameter must interpret the data in the *RoutingData* parameter.

### `RoutingDataSize` [in]

Type: **DWORD**

Specifies a **DWORD** variable that is the size, in bytes, of the buffer pointed to by the *RoutingData* parameter.

## Return value

Type: **BOOL**

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, the fax service calls [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The fax service passes a pointer to the *FaxRouteModifyRoutingData* function when the fax service calls [FaxRouteInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nf-faxroute-faxrouteinitialize). The service passes the pointer in a [FAX_ROUTE_CALLBACKROUTINES](https://learn.microsoft.com/windows/desktop/api/faxroute/ns-faxroute-fax_route_callbackroutines) structure.

The **PFAXROUTEMODIFYROUTINGDATA** data type defines a pointer to a *FaxRouteModifyRoutingData* function.

A fax routing method can call the *FaxRouteModifyRoutingData* callback function to change the routing information for a subsequent routing method. The function does this by modifying the **RoutingInfoData** member of the [FAX_ROUTE](https://learn.microsoft.com/windows/desktop/api/faxroute/ns-faxroute-fax_route) structure that applies to the subsequent method. This allows a fax routing extension to retrieve user-defined routing data and to provide additional callback information to a different routing method. When the subsequent routing method executes, it processes the received fax transmission using the modified routing data.

The fax routing method specified by the *RoutingGuid* parameter must have a lower priority and must run after the calling routing method. The priority level determines the relative order in which the fax service calls the fax routing methods when the service receives a fax document.

## See also

[FAX_ROUTE](https://learn.microsoft.com/windows/desktop/api/faxroute/ns-faxroute-fax_route)

[FAX_ROUTE_CALLBACKROUTINES](https://learn.microsoft.com/windows/desktop/api/faxroute/ns-faxroute-fax_route_callbackroutines)

[Fax Routing Extension Application Programming Interface Overview](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-about-the-fax-routing-extension-api)

[Fax Routing Extension Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-routing-extension-functions)

[FaxRouteInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nf-faxroute-faxrouteinitialize)

[FaxRouteMethod](https://learn.microsoft.com/windows/desktop/api/faxroute/nc-faxroute-pfaxroutemethod)