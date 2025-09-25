# RASADFUNCA callback function

## Description

The
**RASADFunc** function is an application-defined callback function that is used to provide a customized user interface for autodialing.

## Parameters

### `unnamedParam1`

### `unnamedParam2`

### `unnamedParam3`

### `unnamedParam4`

#### - lpAutoDialParams [in]

Pointer to a
[RASADPARAMS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376719(v=vs.85)) structure that indicates how to position the window of the AutoDial user interface. The structure can also specify a parent window for the AutoDial window.

#### - lpdwRetCode [out]

Pointer to a variable that receives a value if the function performs the dialing operation. If the dialing operation succeeds, set this variable to **ERROR_SUCCESS**. If the dialing operation fails, set it to a nonzero value.

#### - lpszEntry [in]

Pointer to a **null**-terminated string that specifies the phone-book entry to use.

#### - lpszPhonebook [in]

Pointer to a **null**-terminated string that specifies the full path and file name of a phone-book (PBK) file. If this parameter is **NULL**, the function uses the current default phone-book file. The default phone-book file is the one selected by the user in the **User Preferences** property sheet of the **Dial-Up Networking** dialog box.

**Windows Me/98/95:** This parameter is always **NULL**. Dial-up networking stores phone-book entries in the registry rather than in a phone-book file.

## Return value

If the application performs the dialing operation, return **TRUE**. Use the *lpdwRetCode* parameter to indicate the results of the dialing operation.

If the application does not perform the dialing operation, return **FALSE**. In this case, the system uses the default user interface for dialing.

## Remarks

When the system starts an AutoDial operation for a phone-book entry with a custom AutoDial handler, it calls the specified
**RASADFunc**. The
**RASADFunc** can start a thread to perform the custom-dialing operation. The
**RASADFunc** function returns **TRUE** to indicate that it took over the dialing, or **FALSE** to allow the system to perform the dialing.

If the
**RASADFunc** function performs the dialing operation, it presents its own user interface for dialing and calls the
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) function to do the actual dialing. The
**RASADFunc** then returns **TRUE** to indicate that it took over the dialing. When the dialing operation has been completed, set the variable pointed to by the *lpdwRetCode* parameter to indicate success or failure.

The AutoDial DLL must provide both a **RASADFUNCA** (ANSI) and a **RASADFUNCW** (Unicode) version of the
**RASADFunc** handler. To enable a
**RASADFunc** AutoDial handler for a phone-book entry, use the
[RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85)) structure in a call to the
[RasSetEntryProperties](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetentrypropertiesa) function. The **szAutodialDll** member specifies the name of the DLL that contains the handler, and the **szAutodialFunc** member specifies the exported name of the handler. The **szAutodialFunc** member should not include the "A" or "W" suffix.

**RASADFunc** is a placeholder for the library-defined function name. The **RASADFUNC** type is a pointer to a
**RASADFunc** function.

> [!NOTE]
> The ras.h header defines RASADFUNC as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85))

[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala)

[RasSetEntryProperties](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetentrypropertiesa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)