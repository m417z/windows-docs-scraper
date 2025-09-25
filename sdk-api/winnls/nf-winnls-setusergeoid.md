# SetUserGeoID function

## Description

[**SetUserGeoID** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [SetUserGeoName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setusergeoname).

]

Sets the geographical location identifier for the user. This identifier should have one of the values described in [Table of Geographical Locations](https://learn.microsoft.com/windows/desktop/Intl/table-of-geographical-locations).

## Parameters

### `GeoId` [in]

Identifier for the geographical location of the user.

## Return value

Returns **TRUE** if successful or **FALSE** otherwise.

**Windows XP, Windows Server 2003**: This function does not supply extended error information. Thus it is not appropriate for an application to call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) after this function. If the application does call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), it can return a value set by some previously called function.

If this function does not succeed, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_ACCESS_DISABLED_BY_POLICY. The group policy of the computer or the user has forbidden this operation.
* ERROR_INTERNAL_ERROR. An unexpected error occurred in the function.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

This function writes to the registry the geographical location for a particular user instead of a particular application. This action affects the behavior of other applications run by the user. As a rule, the application should call this function only when the user has explicitly requested changes, but not for purely application-specific reasons.

**SetUserGeoID** is intended for use by applications that are designed to change user settings, such as the Windows Settings app. Other applications should not call this function.

## See also

[GetUserGeoID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getusergeoid)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)

[SetUserGeoName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setusergeoname)

[Table of Geographical Locations](https://learn.microsoft.com/windows/desktop/Intl/table-of-geographical-locations)