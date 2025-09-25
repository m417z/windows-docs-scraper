# tapiGetLocationInfoA function

## Description

The
**tapiGetLocationInfo** function returns the country or region code and city (area) code that the user has set in the current location parameters in the Telephony Control Panel. The application can use this information to assist the user in forming proper canonical telephone numbers, such as by offering these as defaults when new numbers are entered in a phone book entry or database record.

## Parameters

### `lpszCountryCode`

TBD

### `lpszCityCode`

TBD

#### - lpszCityCodeW

Pointer to a memory location where a **null**-terminated string specifying the city (area) code for the current location is to be returned. The application should allocate at least 8 bytes of storage at this location to hold the string (TAPI does not return more than 8 bytes, including the terminating **NULL**). An empty string (\0) is returned if the city code has not been set for the current location.

#### - lpszCountryCodeW

Pointer to a memory location where a **null**-terminated string specifying the country or region code for the current location is to be returned. The application should allocate at least 8 bytes of storage at this location to hold the string (TAPI does not return more than 8 bytes, including the terminating **NULL**). An empty string (\0) is returned if the country or region code has not been set for the current location.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are TAPIERR_REQUESTFAILED.

## See also

[Assisted Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/assisted-telephony-services-reference)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

## Remarks

> [!NOTE]
> The tapi.h header defines tapiGetLocationInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).