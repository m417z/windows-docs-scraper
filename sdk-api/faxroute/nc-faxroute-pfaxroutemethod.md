## Description

The **FaxRouteMethod** function is a placeholder for a function name defined by the fax routing extension DLL. This function executes a defined fax routing procedure.

The fax routing extension DLL can export multiple fax routing methods. The fax routing extension must export one uniquely named **FaxRouteMethod** function for each fax routing method it exports. It is recommended that each function name describe the functionality of the particular fax routing method. The fax service calls the **FaxRouteMethod** functions, in order of priority, after the service receives a fax document.

## Parameters

### `unnamedParam1`

Type: **const [FAX_ROUTE](https://learn.microsoft.com/windows/win32/api/faxroute/ns-faxroute-fax_route)***

Pointer to a [FAX_ROUTE](https://learn.microsoft.com/windows/win32/api/faxroute/ns-faxroute-fax_route) structure that contains information about the received fax document.

### `unnamedParam2`

Type: **PVOID***

Pointer to a variable that receives a pointer to a buffer that contains retry information for the fax routing method. This parameter can be equal to **NULL**. For more information, see the following Remarks section.

### `unnamedParam3`

Type: **LPDWORD**

Pointer to an unsigned **DWORD** variable that receives the size, in bytes, of the buffer pointed to by the *FailureData* parameter.

## Return value

Type: **BOOL**

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, the fax service calls [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A fax routing method can manipulate the received Tagged Image File Format Class F (TIFF Class F) file. For example, one routing method could route the received Tagged Image File Format (TIFF) file to a specific destination such as a printer, or deliver the file in an email message to a user. Another routing method could convert the TIFF file to text using optical character recognition (OCR) technology, and then create a Microsoft Word document from the text. A fax routing method cannot delete or modify the TIFF file. For information about TIFF files, see [Fax Image Format](https://msdn.microsoft.com/d7840c10-6059-40ed-9040-50eefefc7349)..

If you want the fax service to retry a failed routing method at a later time, the fax routing method must take the following steps.

### To specify that the fax service retry a fax routing method

1. Allocate a buffer to hold retry information for the fax routing method. The fax routing method must allocate the memory required for the buffer from the heap specified by the [FaxRouteInitialize](https://learn.microsoft.com/windows/win32/api/faxroute/nf-faxroute-faxrouteinitialize) function.
2. Fill the buffer with the information required to retry the fax routing method.
3. Set the *FailureData* parameter of the **FaxRouteMethod** function to a valid pointer value.

## See also

[FAX_ROUTE](https://learn.microsoft.com/windows/win32/api/faxroute/ns-faxroute-fax_route)

[Fax Routing Extension Application Programming Interface Overview](https://msdn.microsoft.com/f8bdf0de-9455-45d1-9271-3929e0429d5c)

[Fax Routing Extension Functions](https://msdn.microsoft.com/339f7fb6-64eb-403e-91be-210501042a25)

[FaxRouteAddFile](https://learn.microsoft.com/windows/win32/api/faxroute/nc-faxroute-pfaxrouteaddfile)

[FaxRouteDeleteFile](https://learn.microsoft.com/windows/win32/api/faxroute/nc-faxroute-pfaxroutedeletefile)

[FaxRouteEnumFiles](https://learn.microsoft.com/windows/win32/api/faxroute/nc-faxroute-pfaxrouteenumfiles)

[FaxRouteGetFile](https://learn.microsoft.com/windows/win32/api/faxroute/nc-faxroute-pfaxroutegetfile)

[FaxRouteInitialize](https://learn.microsoft.com/windows/win32/api/faxroute/nf-faxroute-faxrouteinitialize)

[FaxRouteModifyRoutingData](https://learn.microsoft.com/windows/win32/api/faxroute/nc-faxroute-pfaxroutemodifyroutingdata)