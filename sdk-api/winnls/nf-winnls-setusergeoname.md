# SetUserGeoName function

## Description

Sets the geographic location for the current user to the specified two-letter International Organization for Standardization (ISO) 3166-1 code or numeric United Nations (UN) Series M, Number 49 (M.49) code.

## Parameters

### `geoName` [in]

The two-letter ISO 3166-1 or numeric UN M.49 code for the geographic location to set for the current user. To get the codes that are available on the operating system, call [EnumSystemGeoNames](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemgeonames).

## Return value

Returns **TRUE** if successful or **FALSE** otherwise.

If this function does not succeed, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DISABLED_BY_POLICY** | The group policy of the computer or the user has forbidden this operation. |
| **ERROR_INTERNAL_ERROR** | An unexpected error occurred in the function. |
| **ERROR_INVALID_PARAMETER** | A parameter value was invalid. |

## Remarks

This function writes to the registry the geographical location for a particular user instead of a particular application. This action affects the behavior of other applications that the user runs. As a rule, call this function only when the user has explicitly requested changes, but not for purely application-specific reasons.

For information about two-letter ISO 3166-1 codes, see [Country Codes - ISO 3166](https://www.iso.org/iso-3166-country-codes.html). For information about numeric UN M.49 codes, see [Standard country or area codes for statistical use (M49)](https://unstats.un.org/unsd/methodology/m49/).

**SetUserGeoName** is intended for use by applications that are designed to change user settings, such as the Windows Settings app. Other applications should not call this function.

## See also

[EnumSystemGeoNames](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemgeonames)

[GetUserDefaultGeoName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultgeoname)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)

[SetUserGeoID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setusergeoid)