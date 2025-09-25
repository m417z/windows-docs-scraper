# PFAXROUTEDELETEFILE callback function

## Description

A fax routing method calls the *FaxRouteDeleteFile* callback function to delete a file from the fax file list associated with a received fax document.

## Parameters

### `JobId` [in]

Type: **DWORD**

Specifies a unique number that identifies the fax job that received the fax document.

### `FileName` [in]

Type: **LPCWSTR**

Pointer to a constant null-terminated Unicode character string. The string contains the fully qualified path and name of the file to delete from the fax file list associated with the received fax document.

## Return value

Type: **LONG**

If the function succeeds, the return value is the file number of the file deleted from the fax file list associated with the received fax.

If the function fails, the return value is 1. To get extended error information, the fax service calls [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A fax routing method can use the *FaxRouteDeleteFile* function to remove a file that a different routing method added to the fax file list. For more information, see [Fax File Lists](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-file-lists).

The fax service passes a pointer to the *FaxRouteDeleteFile* callback function when the fax service calls the [FaxRouteInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nf-faxroute-faxrouteinitialize) function. The service passes the pointer in a [FAX_ROUTE_CALLBACKROUTINES](https://learn.microsoft.com/windows/desktop/api/faxroute/ns-faxroute-fax_route_callbackroutines) structure.

The **PFAXROUTEDELETEFILE** data type defines a pointer to a *FaxRouteDeleteFile* function.

**Note** A fax routing method cannot remove the initial Tagged Image File Format Class F (TIFF Class F) file from the fax file list. For information about Tagged Image File Format (TIFF) files, see [Fax Image Format](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-image-format). .

## See also

[FAX_ROUTE_CALLBACKROUTINES](https://learn.microsoft.com/windows/desktop/api/faxroute/ns-faxroute-fax_route_callbackroutines)

[Fax Routing Extension Application Programming Interface Overview](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-about-the-fax-routing-extension-api)

[Fax Routing Extension Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-routing-extension-functions)

[FaxRouteAddFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxrouteaddfile)

[FaxRouteGetFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxroutegetfile)

[FaxRouteInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nf-faxroute-faxrouteinitialize)