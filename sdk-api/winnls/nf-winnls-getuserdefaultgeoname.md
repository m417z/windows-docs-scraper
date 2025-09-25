# GetUserDefaultGeoName function

## Description

Retrieves the default geographical location of the user as an International Organization for Standardization (ISO) 3166-1 two-letter code, if available. Otherwise, a United Nations (UN) Series M, Number 49 (M.49) numeric code.

## Parameters

### `geoName` [out]

Pointer to a buffer in which this function should write the null-terminated International Organization for Standardization (ISO) 3166-1 two-letter code or a United Nations (UN) Series M, Number 49 (M.49) numeric code.

### `geoNameCount` [in]

The size of the buffer that the *geoName* parameter specifies. If this value is zero, the function only returns the number of characters that function would copy to the output buffer, but does not write the name of the default geographic location of the user to the buffer.

## Return value

The number of characters the function would copy to the output buffer if the value of the *geoNameCount* parameter is zero. Otherwise, the number of characters that the function copied to the buffer that the *geoName* parameter specifies.

Zero indicates that the function failed. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

| Return code | Description |
|----------------------------|-------------------------------------------------------|
| **ERROR_INVALID_PARAMETER**| A parameter value was not valid. |
| **ERROR_BADDB** | The function could not read information from the registry. |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer that the *geoName* parameter specifies is too small for the string. |

## Remarks

If the ISO 3166-1 code for the user's default geographical location is 'XX' (which indicates that no code has been assigned), but the location does have a UN M.49 code assigned, then the M.49 code is returned as a decimal string.

For information about two-letter ISO 3166-1 codes, see [ISO 3166 Country Codes](https://www.iso.org/iso-3166-country-codes.html).

For information about numeric UN M.49 codes, see [Standard country or area codes for statistical use (M49)](https://unstats.un.org/unsd/methodology/m49/).

## See also

- [GetUserGeoID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getusergeoid)
- [National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)
- [National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)
- [SetUserGeoName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setusergeoname)