# EnumSystemGeoID function

## Description

[**EnumSystemGeoID** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [EnumSystemGeoNames](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemgeonames).

]

Enumerates the geographical location identifiers (type GEOID) that are available on the operating system.

## Parameters

### `GeoClass` [in]

Geographical location class for which to enumerate the identifiers. At present, only GEOCLASS_NATION is supported. This type causes the function to enumerate all geographical identifiers for nations on the operating system.

### `ParentGeoId` [in]

Reserved. This parameter must be 0.

### `lpGeoEnumProc` [in]

Pointer to the application-defined callback function [EnumGeoInfoProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd317817(v=vs.85)). The **EnumSystemGeoID** function makes repeated calls to this callback function until it returns **FALSE**.

## Return value

Returns a nonzero value if successful, or 0 otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## See also

[EnumGeoInfoProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd317817(v=vs.85))

[EnumSystemGeoNames](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemgeonames)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)