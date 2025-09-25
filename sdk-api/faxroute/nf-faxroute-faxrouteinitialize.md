# FaxRouteInitialize function

## Description

The fax service calls the **FaxRouteInitialize** function once, each time the service starts, to initialize the fax routing extension DLL. Each fax routing extension DLL must export the **FaxRouteInitialize** function.

## Parameters

### `HeapHandle` [in]

Type: **HANDLE**

Handle to an initialized heap. The fax routing extension DLL must use the Win32 [heap functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions) to allocate all memory from this heap.

### `FaxRouteCallbackRoutines` [in]

Type: **PFAX_ROUTE_CALLBACKROUTINES**

Pointer to a [FAX_ROUTE_CALLBACKROUTINES](https://learn.microsoft.com/windows/desktop/api/faxroute/ns-faxroute-fax_route_callbackroutines) structure that contains pointers to the callback functions the fax service supplies. The structure contains pointers to the [FaxRouteAddFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxrouteaddfile), [FaxRouteDeleteFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxroutedeletefile), [FaxRouteGetFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxroutegetfile), [FaxRouteEnumFiles](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxrouteenumfiles), and [FaxRouteModifyRoutingData](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxroutemodifyroutingdata) functions.

The fax routing extension DLL must store these pointers in a global variable for later use.

## Return value

Type: **BOOL**

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, the fax service calls [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The fax routing extension DLL should not perform provider-specific initialization when the fax service calls the [DllMain](https://learn.microsoft.com/windows/desktop/Dlls/dllmain) function. Instead, the extension should do this when the fax service calls the **FaxRouteInitialize** function.

For more information, see [Fax Routing Extension Registration](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-routing-extension-registration) and [Fax File Lists](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-file-lists).

## See also

[FAX_ROUTE_CALLBACKROUTINES](https://learn.microsoft.com/windows/desktop/api/faxroute/ns-faxroute-fax_route_callbackroutines)

[Fax Routing Extension Application Programming Interface Overview](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-about-the-fax-routing-extension-api)

[Fax Routing Extension Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-routing-extension-functions)

[FaxRouteAddFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxrouteaddfile)

[FaxRouteDeleteFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxroutedeletefile)

[FaxRouteEnumFiles](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxrouteenumfiles)

[FaxRouteGetFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxroutegetfile)

[FaxRouteModifyRoutingData](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxroutemodifyroutingdata)