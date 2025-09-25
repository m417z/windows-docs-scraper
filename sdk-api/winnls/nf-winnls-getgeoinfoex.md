# GetGeoInfoEx function

## Description

Retrieves information about a geographic location that you specify by using a two-letter International Organization for Standardization (ISO) 3166-1 code or numeric United Nations (UN) Series M, Number 49 (M.49) code.

## Parameters

### `location` [in]

The two-letter ISO 3166-1 or numeric UN M.49 code for the geographic location for which to get information. To get the codes that are available on the operating system, call [EnumSystemGeoNames](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemgeonames).

### `geoType` [in]

The type of information you want to retrieve. Possible values are defined by the [SYSGEOTYPE](https://learn.microsoft.com/windows/desktop/api/winnls/ne-winnls-sysgeotype) enumeration. The following values of the **SYSGEOTYPE** enumeration should not be used with **GetGeoInfoEx**:

* **GEO_ID**

  This value is provided for backward compatibility. Do not use this value in new applications, but use **GEO_NAME** instead.
* **GEO_LCID**

  This value is not supported for the **GetGeoInfoEx** function.
* **GEO_NATION**

  This value is not supported for the **GetGeoInfoEx** function.
* **GEO_RFC1766**

  This value is not supported for the **GetGeoInfoEx** function.

### `geoData` [out, optional]

A pointer to the buffer in which **GetGeoInfoEx** should write the requested information.

### `geoDataCount` [in]

The size of the buffer to which the *GeoData* parameter points, in characters. Set this parameter to 0 to specify that the function should only return the size of the buffer required to store the requested information without writing the requested information to the buffer.

## Return value

The number of bytes of geographical location information that the function wrote the output buffer. If *geoDataCount* is 0, the function returns the size of the buffer required to hold the information without writing the information to the buffer.

0 indicates that the function did not succeed. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The supplied buffer size was not large enough, or it was incorrectly set to **NULL**. |
| **ERROR_INVALID_PARAMETER** | A parameter value was not valid. |
| **ERROR_INVALID_FLAGS** | The values supplied for flags were not valid. |

## Remarks

For information about two-letter ISO 3166-1 codes, see [Country Codes - ISO 3166](https://www.iso.org/iso-3166-country-codes.html). For information about numeric UN M.49 codes, see [Standard country or area codes for statistical use (M49)](https://unstats.un.org/unsd/methodology/m49/).

## See also

[EnumSystemGeoNames](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemgeonames)

[GetGeoInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getgeoinfoa)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)

[SYSGEOTYPE](https://learn.microsoft.com/windows/desktop/api/winnls/ne-winnls-sysgeotype)