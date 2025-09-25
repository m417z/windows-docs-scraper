# ORASADFUNC callback function

## Description

The
**ORASADFunc** function is an application-defined callback function that is used to provide a customized user interface for autodialing.

This prototype is provided for compatibility with earlier versions of Windows. New applications should use the
[RASADFunc](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rasadfunca) callback function. Support for this prototype may be removed in future versions of RAS.

## Parameters

### `unnamedParam1`

### `unnamedParam2`

### `unnamedParam3`

### `unnamedParam4`

#### - dwFlags [in]

Reserved; must be zero.

#### - hwndOwner [in]

Handle of the owner window.

#### - lpdwRetCode [in]

Pointer to a variable that the callback function fills in with the results of the dialing operation. If the dialing operation succeeds, set this variable to ERROR_SUCCESS. If the dialing operation fails, set it to a nonzero value.

#### - lpszEntry [in]

Pointer to a null-terminated string that specifies the phone-book entry to use.

## Return value

If the callback function performs the dialing operation, return **TRUE**. Use the *lpdwRetCode* parameter to indicate the results of the dialing operation.

If the callback function does not perform the dialing operation, return **FALSE**. In this case, the system uses the default user interface for dialing.

## Remarks

If the
**ORASADFunc** function performs the dialing operation, it presents its own user interface for dialing and calls the
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) function to do the actual dialing. The
**ORASADFunc** then returns **TRUE** to indicate that it took over the dialing. When the dialing operation has been completed, set the variable pointed to by *lpdwRetCode* to indicate success or failure.

To enable an
**ORASADFunc** handler for a phone-book entry, use the
[RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85)) structure in a call to the
[RasSetEntryProperties](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetentrypropertiesa) function. The **szAutodialDll** member specifies the name of the DLL that contains the handler, and the **szAutodialDll** member specifies the exported name of the handler.

The
**ORASADFunc** function is a placeholder for the library-defined function name. The **ORASADFUNC** type is a pointer to an
**ORASADFunc** function.

## See also

[RASADFunc](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rasadfunca)

[RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85))

[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala)

[RasSetEntryProperties](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetentrypropertiesa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)