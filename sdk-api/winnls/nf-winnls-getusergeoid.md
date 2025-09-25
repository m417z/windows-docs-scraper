# GetUserGeoID function

## Description

[**GetUserGeoID** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [GetUserDefaultGeoName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultgeoname).

]

Retrieves information about the geographical location of the user. For more information, see [Table of Geographical Locations](https://learn.microsoft.com/windows/desktop/Intl/table-of-geographical-locations).

## Parameters

### `GeoClass` [in]

Geographical location class to return. Possible values are defined by the [SYSGEOCLASS](https://learn.microsoft.com/windows/desktop/api/winnls/ne-winnls-sysgeoclass) enumeration.

## Return value

Returns the geographical location identifier of the user if [SetUserGeoID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setusergeoid) has been called before to set the identifier.

If no geographical location identifier has been set for the user, the function returns GEOID_NOT_AVAILABLE.

## See also

[GetUserDefaultGeoName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getuserdefaultgeoname)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)

[SYSGEOCLASS](https://learn.microsoft.com/windows/desktop/api/winnls/ne-winnls-sysgeoclass)

[SetUserGeoID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setusergeoid)