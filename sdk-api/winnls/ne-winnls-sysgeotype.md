# SYSGEOTYPE enumeration

## Description

Defines the type of geographical location information requested in the [GetGeoInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getgeoinfoa) or [GetGeoInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getgeoinfoex) function.

## Constants

### `GEO_NATION:0x0001`

The geographical location identifier (GEOID) of a nation. This value is stored in a long integer.

**Starting with Windows 10, version 1709:** This value is not supported for the [GetGeoInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getgeoinfoex) function, and should not be used.

### `GEO_LATITUDE:0x0002`

The latitude of the location. This value is stored in a floating-point number.

### `GEO_LONGITUDE:0x0003`

The longitude of the location. This value is stored in a floating-point number.

### `GEO_ISO2:0x0004`

The ISO 2-letter country/region code. This value is stored in a string.

### `GEO_ISO3:0x0005`

The ISO 3-letter country/region code. This value is stored in a string.

### `GEO_RFC1766:0x0006`

The name for a string, compliant with RFC 4646 (starting with Windows Vista), that is derived from the [GetGeoInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getgeoinfoa) parameters *language* and *GeoId*.

**Starting with Windows 10, version 1709:** This value is not supported for the [GetGeoInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getgeoinfoex) function, and should not be used.

### `GEO_LCID:0x0007`

A locale identifier derived using [GetGeoInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getgeoinfoa).

**Starting with Windows 10, version 1709:** This value is not supported for the [GetGeoInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getgeoinfoex) function, and should not be used.

### `GEO_FRIENDLYNAME:0x0008`

The friendly name of the nation, for example, Germany. This value is stored in a string.

### `GEO_OFFICIALNAME:0x0009`

The official name of the nation, for example, Federal Republic of Germany. This value is stored in a string.

### `GEO_TIMEZONES:0x000A`

Not implemented.

### `GEO_OFFICIALLANGUAGES:0x000B`

Not implemented.

### `GEO_ISO_UN_NUMBER:0x000C`

**Starting with Windows 8:** The ISO 3-digit country/region code. This value is stored in a string.

### `GEO_PARENT:0x000D`

**Starting with Windows 8:** The geographical location identifier of the parent region of a country/region. This value is stored in a string.

### `GEO_DIALINGCODE:0x000E`

**Starting with Windows 10, version 1709:** The dialing code to use with telephone numbers in the geographic location. For example, 1 for the United States.

### `GEO_CURRENCYCODE:0x000F`

**Starting with Windows 10, version 1709:** The three-letter code for the currency that the geographic location uses. For example, USD for United States dollars.

### `GEO_CURRENCYSYMBOL:0x0010`

**Starting with Windows 10, version 1709:** The symbol for the currency that the geographic location uses. For example, the dollar sign ($).

### `GEO_NAME:0x0011`

**Starting with Windows 10, version 1709:** The two-letter International Organization for Standardization (ISO) 3166-1 code or numeric United Nations (UN) Series M, Number 49 (M.49) code for the geographic region.

For information about two-letter ISO 3166-1 codes, see [Country Codes - ISO 3166](https://www.iso.org/iso-3166-country-codes.html). For information about numeric UN M.49 codes, see [Standard country or area codes for statistical use (M49)](https://unstats.un.org/unsd/methodology/m49/).

### `GEO_ID:0x0012`

**Starting with Windows 10, version 1709:** The Windows geographical location identifiers (GEOID) for the region. This value is provided for backward compatibility. Do not use this value in new applications, but use **GEO_NAME** instead.

## See also

[GetGeoInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getgeoinfoa)

[GetGeoInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getgeoinfoex)

[National Language Support Enumeration Types](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-enumeration-types)