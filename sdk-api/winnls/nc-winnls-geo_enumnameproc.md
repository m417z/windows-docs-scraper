# GEO_ENUMNAMEPROC callback function

## Description

An application-defined callback function that processes enumerated geographical location information provided by the [EnumSystemGeoNames](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemgeonames) function. The **GEO_ENUMNAMEPROC** type defines a pointer to this callback function. *Geo_EnumNameProc* is a placeholder for the application-defined function name.

## Parameters

### `unnamedParam1`

### `unnamedParam2`

#### - GeoName [in]

A two-letter International Organization for Standardization (ISO) 3166-1 code or numeric United Nations (UN) Series M, Number 49 (M.49) code for a geographical location that is available on the operating system.

#### - data

Application-specific information that was specified by the data parameter when the application called the [EnumSystemGeoNames](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemgeonames) function.

## Return value

Returns **TRUE** to continue enumeration or **FALSE** otherwise.

## Remarks

An *Geo_EnumNameProc* function can carry out any desired task, and can use the information passed to it in the *data* parameter for any desired purpose. The application registers this function by passing its address to the [EnumSystemGeoNames](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemgeonames) function.

For information about two-letter ISO 3166-1 codes, see [Country Codes - ISO 3166](https://www.iso.org/iso-3166-country-codes.html). For information about numeric UN M.49 codes, see [Standard country or area codes for statistical use (M49)](https://unstats.un.org/unsd/methodology/m49/).

## See also

[EnumSystemGeoNames](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemgeonames)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)