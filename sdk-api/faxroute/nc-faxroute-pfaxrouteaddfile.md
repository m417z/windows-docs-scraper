# PFAXROUTEADDFILE callback function

## Description

A fax routing method calls the *FaxRouteAddFile* callback function to add a file to the fax file list associated with a received fax document.

## Parameters

### `JobId` [in]

Type: **DWORD**

Specifies a unique number that identifies the fax job that received the fax document.

### `FileName` [in]

Type: **LPCWSTR**

Pointer to a constant null-terminated Unicode character string. The string contains the fully qualified path and name of the file to add to the fax file list associated with the received fax document.

### `Guid` [in]

Type: **GUID***

Pointer to a null-terminated Unicode character string that contains the GUID for the fax routing method that is adding the file.

## Return value

Type: **LONG**

If the function succeeds, the return value is the file number of the file added to the fax file list associated with the received fax.

If the function fails, the return value is 1. To get extended error information, the fax service calls [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The fax service passes a pointer to the *FaxRouteAddFile* callback function when the fax service calls the [FaxRouteInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nf-faxroute-faxrouteinitialize) function. The service passes the pointer in a [FAX_ROUTE_CALLBACKROUTINES](https://learn.microsoft.com/windows/desktop/api/faxroute/ns-faxroute-fax_route_callbackroutines) structure.

The **PFAXROUTEADDFILE** data type defines a pointer to a *FaxRouteAddFile* function.

For more information, see [Fax File Lists](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-file-lists).

## See also

[FAX_ROUTE_CALLBACKROUTINES](https://learn.microsoft.com/windows/desktop/api/faxroute/ns-faxroute-fax_route_callbackroutines)

[Fax Routing Extension Application Programming Interface Overview](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-about-the-fax-routing-extension-api)

[Fax Routing Extension Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-routing-extension-functions)

[FaxRouteDeleteFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxroutedeletefile)

[FaxRouteGetFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxroutegetfile)

[FaxRouteInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nf-faxroute-faxrouteinitialize)