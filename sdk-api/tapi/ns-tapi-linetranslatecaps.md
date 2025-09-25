# LINETRANSLATECAPS structure

## Description

The
**LINETRANSLATECAPS** structure describes the address translation capabilities. This structure can contain an array of
[LINELOCATIONENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linelocationentry) structures and an array of
[LINECARDENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecardentry) structures. The
**LINETRANSLATECAPS** structure is returned by the
[lineGetTranslateCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegettranslatecaps) function.

## Members

### `dwTotalSize`

Total size allocated to this data structure, in bytes.

### `dwNeededSize`

Size for this data structure that is needed to hold all the returned information, in bytes.

### `dwUsedSize`

Size of the portion of this data structure that contains useful information, in bytes.

### `dwNumLocations`

Number of entries in the **LocationList**. It includes all locations defined, including zero (default).

### `dwLocationListSize`

Size of the list of locations known to the address translation, in bytes.

### `dwLocationListOffset`

Offset from the beginning of this structure to the list of locations known to the address translation. The list consists of a sequence of
[LINELOCATIONENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linelocationentry) structures. The **dwLocationListOffset** member points to the first byte of the first structure, and the **dwLocationListSize** member indicates the total number of bytes in the list.

### `dwCurrentLocationID`

Permanent identifier for the **CurrentLocation** entry in the [Locations] section of the registry. See the **dwPermanentLocationID** member of the
[LINELOCATIONENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linelocationentry) structure.

### `dwNumCards`

Number of entries in the **CardList**.

### `dwCardListSize`

Size of the list of calling cards known to the address translation, in bytes.

### `dwCardListOffset`

Offset from the beginning of this structure to the list of calling cards known to the address translation. It includes only non-hidden card entries and always includes card 0 (direct dial). The list consists of a sequence of
[LINECARDENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecardentry) structures. The **dwCardListOffset** member points to the first byte of the first structure, and the **dwCardListSize** member indicates the total number of bytes in the list.

### `dwCurrentPreferredCardID`

Preferred calling card for the **CurrentLocation** entry in the [Locations] section of the registry. See the **dwPreferredCardID** member of the
[LINELOCATIONENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linelocationentry) structure.

## Remarks

This structure may not be extended.

## See also

[LINECARDENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecardentry)

[LINELOCATIONENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linelocationentry)

[lineGetTranslateCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegettranslatecaps)