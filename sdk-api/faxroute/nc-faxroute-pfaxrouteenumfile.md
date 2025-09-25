# PFAXROUTEENUMFILE callback function

## Description

The *FaxRouteEnumFile* callback function receives the file names in the fax file list associated with a received fax document. This function receives a file name in the fax file list associated with a received fax document, and executes a procedure defined by the routing extension. It can return a nonzero value to proceed to the next file name in the fax file list, or zero to stop [FaxRouteEnumFiles](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxrouteenumfiles).

*FaxRouteEnumFile* is a placeholder for a function name defined by the fax routing extension DLL. The **PFAXROUTEENUMFILE** data type is a pointer to a *FaxRouteEnumFile* function.

## Parameters

### `JobId` [in]

Type: **DWORD**

Specifies a unique number that identifies the fax job that received the fax document.

### `GuidOwner` [in]

Type: **GUID***

Pointer to the GUID associated with the fax routing method that added the file to the fax file list. (This file is specified by the *FileName* parameter.)

### `GuidCaller` [in]

Type: **GUID***

Pointer to the GUID associated with the fax routing method that called the [FaxRouteEnumFiles](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxrouteenumfiles) function. (*FaxRouteEnumFiles* passes a pointer to the *FaxRouteEnumFile* function.) Note that this parameter has the same value as the *Guid* parameter of *FaxRouteEnumFiles*. The *GuidCaller* parameter can be **NULL**.

### `FileName` [in]

Type: **LPCWSTR**

Pointer to a constant null-terminated Unicode character string. The fax service sets this variable to the fully qualified path and name of one file in the fax file list associated with the received fax document.

### `Context` [in, out]

Type: **PVOID**

Pointer to an extension-defined value supplied by the fax routing method identified by the *GuidCaller* parameter. This is an opaque value that the [FaxRouteEnumFiles](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxrouteenumfiles) function passes to *FaxRouteEnumFile*.

## Return value

Type: **BOOL**

The function returns a nonzero value to continue enumeration, or zero to stop enumeration.

## Remarks

The fax routing extension DLL must register the *FaxRouteEnumFile* callback function by passing its address to the [FaxRouteEnumFiles](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxrouteenumfiles) function.

For more information, see [Fax File Lists](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-file-lists).

## See also

[Fax Routing Extension Application Programming Interface Overview](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-about-the-fax-routing-extension-api)

[Fax Routing Extension Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-routing-extension-functions)

[FaxRouteEnumFiles](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxrouteenumfiles)