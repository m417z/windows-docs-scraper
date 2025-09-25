# RasGetCountryInfoA function

## Description

The
**RasGetCountryInfo** function retrieves country/region-specific dialing information from the Windows Telephony list of countries/regions.

For more information about country/region-specific dialing information and [Telephony Application Programming Interface (TAPI)](https://learn.microsoft.com/windows/desktop/Tapi/telephony-application-programming-interfaces) country/region identifiers, see the TAPI portion of the Platform Software Development Kit (SDK).

## Parameters

### `unnamedParam1` [in, out]

Pointer to a
[RASCTRYINFO](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376731(v=vs.85)) structure that, on output, receives the country/region-specific dialing information followed by additional bytes for a country/region description string.

On input, set the **dwSize** member of the structure to sizeof([RASCTRYINFO](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376731(v=vs.85))) to identify the version of the structure. Also, set the **dwCountryId** member to the TAPI country/region identifier of the country/region for which to get information.

Allocate at least 256 bytes for the buffer.

### `unnamedParam2` [in, out]

Pointer to a variable that, on input, specifies the size, in bytes, of the buffer pointed to by the *lpRasCtryInfo* parameter.

On output, this variable receives the number of bytes required.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_USER_BUFFER** | The address or buffer specified by *lpRasCtryInfo* is invalid. |
| **ERROR_INVALID_PARAMETER** | The **dwCountryId** member of the structure pointed to by *lpRasCtryInfo* was not a valid value. |
| **ERROR_BUFFER_TOO_SMALL** | The size of the *lpRasCtryInfo* buffer specified by the *lpdwSize* parameter was not large enough to store the information for the country/region identified by the **dwCountryId** member. The function returns the required buffer size in the variable pointed to by *lpdwSize*. |
| **ERROR_TAPI_CONFIGURATION** | TAPI subsystem information was corrupted. |

## Remarks

To enumerate information for all countries/regions in the Windows Telephony list, set the **dwCountryId** member of the
[RASCTRYINFO](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376731(v=vs.85)) structure to 1 in the initial
**RasGetCountryInfo** call. This causes the function to return information for the first country/region in the list. The value returned in the **dwNextCountryID** member is the country/region identifier of the next country/region in the list. Use this value in repeated calls to
**RasGetCountryInfo** until **dwNextCountryID** returns zero, indicating the last country/region in the list.

> [!NOTE]
> The ras.h header defines RasGetCountryInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RASCTRYINFO](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376731(v=vs.85))

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)