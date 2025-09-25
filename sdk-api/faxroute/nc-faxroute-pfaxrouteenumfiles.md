# PFAXROUTEENUMFILES callback function

## Description

A fax routing method calls the *FaxRouteEnumFiles* callback function to enumerate the files in the fax file list associated with a received fax document.

[FaxRoutingMethod](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxroutingmethod) passes a pointer to the [FaxRouteEnumFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxrouteenumfile) callback function if it calls *FaxRouteEnumFiles*.

## Parameters

### `JobId` [in]

Type: **DWORD**

Specifies a unique number that identifies the fax job that received the fax document.

### `Guid` [in]

Type: **GUID***

Pointer to a null-terminated Unicode character string that contains the GUID for the fax routing method.

### `FileEnumerator` [in]

Type: **PFAXROUTEENUMFILE**

Pointer to a [FaxRouteEnumFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxrouteenumfile) callback function defined by the fax routing extension. *FaxRouteEnumFile* receives the file names in the fax file list associated with the received fax document.

### `Context` [in, out]

Type: **PVOID**

Pointer to an extension-defined value that *FaxRouteEnumFiles* passes to the [FaxRouteEnumFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxrouteenumfile) function. The fax routing method can define this value.

## Return value

Type: **BOOL**

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, the fax service calls [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The fax service passes a pointer to the *FaxRouteEnumFiles* callback function when the fax service calls the [FaxRouteInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nf-faxroute-faxrouteinitialize) function. The service passes the pointer in a [FAX_ROUTE_CALLBACKROUTINES](https://learn.microsoft.com/windows/desktop/api/faxroute/ns-faxroute-fax_route_callbackroutines) structure.

The **PFAXROUTEENUMFILES** data type defines a pointer to a *FaxRouteEnumFiles* function.

The fax routing extension DLL must supply the [FaxRouteEnumFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxrouteenumfile) function specified by the *FileEnumerator* parameter. The fax service calls *FaxRouteEnumFile* to enumerate the files in the fax file list for the fax routing method. The fax service calls *FaxRouteEnumFile* once for each file in the fax file list.

For more information, see [Fax File Lists](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-file-lists).

## See also

[FAX_ROUTE_CALLBACKROUTINES](https://learn.microsoft.com/windows/desktop/api/faxroute/ns-faxroute-fax_route_callbackroutines)

[Fax Routing Extension Application Programming Interface Overview](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-about-the-fax-routing-extension-api)

[Fax Routing Extension Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-routing-extension-functions)

[FaxRouteEnumFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxrouteenumfile)

[FaxRouteInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nf-faxroute-faxrouteinitialize)