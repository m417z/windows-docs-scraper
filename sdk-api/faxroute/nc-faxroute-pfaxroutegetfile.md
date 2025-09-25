# PFAXROUTEGETFILE callback function

## Description

A fax routing method calls the **FaxRouteGetFile** callback function to retrieve the name of a specific file from the fax file list associated with a received fax document.

## Parameters

### `JobId` [in]

Type: **DWORD**

Specifies a unique number that identifies the fax job that received the fax document.

### `Index` [in]

Type: **DWORD**

Specifies a unique number that identifies the requested file.

### `FileNameBuffer` [out]

Type: **LPWSTR**

Pointer to a buffer that receives a null-terminated Unicode character string that contains the requested file name. For more information, see the following Remarks section.

### `RequiredSize` [in, out]

Type: **LPDWORD**

Pointer to an unsigned **DWORD** variable. If the *FileNameBuffer* parameter is **NULL**, receives the required size, in bytes, of the buffer pointed to by the *FileNameBuffer* parameter. If *FileNameBuffer* parameter is not **NULL**, this variable indicates the output buffer size. For more information, see the following Remarks section.

## Return value

Type: **BOOL**

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, the fax service calls [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The fax routing method must call the *FaxRouteGetFile* function twice. The first time the routing method calls *FaxRouteGetFile* it must pass a null pointer in the *FileNameBuffer* parameter. The fax service sets the *RequiredSize* parameter to the size required for the *FileNameBuffer* parameter. The fax routing method must allocate the memory required for the buffer from the heap specified by the [FaxRouteInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nf-faxroute-faxrouteinitialize) function, and call *FaxRouteGetFile* again. The second time the routing method calls *FaxRouteGetFile* it must pass a valid pointer in the *FileNameBuffer* parameter.

The fax service passes a pointer to the *FaxRouteGetFile* callback function when the fax service calls [FaxRouteInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nf-faxroute-faxrouteinitialize). The service passes the pointer in a [FAX_ROUTE_CALLBACKROUTINES](https://learn.microsoft.com/windows/desktop/api/faxroute/ns-faxroute-fax_route_callbackroutines) structure.

The **PFAXROUTEGETFILE** data type is a pointer to a *FaxRouteGetFile* function.

For more information, see [Fax File Lists](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-file-lists).

## See also

[FAX_ROUTE_CALLBACKROUTINES](https://learn.microsoft.com/windows/desktop/api/faxroute/ns-faxroute-fax_route_callbackroutines)

[Fax Routing Extension Application Programming Interface Overview](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-about-the-fax-routing-extension-api)

[Fax Routing Extension Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-routing-extension-functions)

[FaxRouteInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nf-faxroute-faxrouteinitialize)