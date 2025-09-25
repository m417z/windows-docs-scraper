# LINEPROVIDERLIST structure

## Description

The
**LINEPROVIDERLIST** structure describes a list of service providers. A structure of this type is returned by the
[lineGetProviderList](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetproviderlist) function. The
**LINEPROVIDERLIST** structure can contain an array of
[LINEPROVIDERENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineproviderentry) structures.

## Members

### `dwTotalSize`

Total size allocated to this data structure, in bytes.

### `dwNeededSize`

Size for this data structure that is needed to hold all the returned information, in bytes.

### `dwUsedSize`

Size of the portion of this data structure that contains useful information, in bytes.

### `dwNumProviders`

Number of
[LINEPROVIDERENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineproviderentry) structures present in the array denominated by **dwProviderListSize** and **dwProviderListOffset**.

### `dwProviderListSize`

Size of the provider list array, in bytes.

### `dwProviderListOffset`

Offset from the beginning of this structure to an array of
[LINEPROVIDERENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineproviderentry) elements, which provide the information on each service provider. The size of the array is specified by **dwProviderListSize**.

## Remarks

This structure may not be extended.

## See also

[LINEPROVIDERENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineproviderentry)

[lineGetProviderList](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetproviderlist)