# LINECOUNTRYLIST structure

## Description

The
**LINECOUNTRYLIST** structure describes a list of countries/regions. This structure can contain an array of
[LINECOUNTRYENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecountryentry) structures.
**LINECOUNTRYLIST** is returned by the
[lineGetCountry](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcountry) function.

## Members

### `dwTotalSize`

Total size allocated to this data structure, in bytes.

### `dwNeededSize`

Size for this data structure that is needed to hold all the returned information, in bytes.

### `dwUsedSize`

Size of the portion of this data structure that contains useful information, in bytes.

### `dwNumCountries`

Number of
[LINECOUNTRYENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecountryentry) structures present in the array defined by **dwCountryListSize** and **dwCountryListOffset**.

### `dwCountryListSize`

Size of the array of country/region information, in bytes.

### `dwCountryListOffset`

Offset from the beginning of the structure to an array of
[LINECOUNTRYENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecountryentry) structures that provides the information for each country/region. The size of the field is specified by **dwCountryListSize**.

## Remarks

This structure may not be extended.

## See also

[LINECOUNTRYENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecountryentry)

[lineGetCountry](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcountry)