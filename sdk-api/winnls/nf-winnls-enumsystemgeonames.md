# EnumSystemGeoNames function

## Description

Enumerates the two-letter International Organization for Standardization (ISO) 3166-1 codes or numeric United Nations (UN) Series M, Number 49 (M.49) codes for geographical locations that are available on the operating system.

## Parameters

### `geoClass` [in]

The geographical location class for which to enumerate the available two-letter ISO 3166-1 or numeric UN M.49 codes.

### `geoEnumProc` [in]

Pointer to the application-defined callback function [Geo_EnumNameProc](https://learn.microsoft.com/windows/desktop/api/winnls/nc-winnls-geo_enumnameproc). The **EnumSystemGeoNames** function calls this callback function for each of the two-letter ISO 3166-1 or numeric UN M.49 codes for geographical locations that are available on the operating system until callback function returns **FALSE**.

### `data` [in, optional]

Application-specific information to pass to the callback function that the *genEnumProc* parameter specifies.

## Return value

Returns a nonzero value if successful, or 0 otherwise. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_FLAGS** | The values supplied for flags were not valid. |
| **ERROR_INVALID_PARAMETER** | A parameter value was not valid. |

## Remarks

For information about two-letter ISO 3166-1 codes, see [Country Codes - ISO 3166](https://www.iso.org/iso-3166-country-codes.html). For information about numeric UN M.49 codes, see [Standard country or area codes for statistical use (M49)](https://unstats.un.org/unsd/methodology/m49/).

## See also

[EnumSystemGeoID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemgeoid)

[Geo_EnumNameProc](https://learn.microsoft.com/windows/desktop/api/winnls/nc-winnls-geo_enumnameproc)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)