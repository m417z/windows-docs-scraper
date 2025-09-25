## Description

The KS_DVDCOPY_REGION structure is used to describe the copy control region according to language restrictions.

## Members

### `Reserved`

Reserved. Do not use.

### `RegionData`

Specifies the region code for the nationality or language, as described in the following table:

| Numeric Code | Description |
|---|---|
| 1 | North America |
| 2 | Japan, European Union, Middle East, Egypt, South Africa and Greenland |
| 3 | Southeast Asia (including Hong Kong SAR) |
| 4 | Central/South America, Australia, New Zealand and the Caribbean |
| 5 | Africa, Northwest Asia (including Korea) |
| 6 | China |

### `Reserved2`

Reserved. Do not use.

## Remarks

The **KS_DVDCOPY_REGION** structure is used by the KSPROPERTY_DVDCOPY_REGION property.

For more information, see [DVD Copyright Protection](https://learn.microsoft.com/windows-hardware/drivers/stream/dvd-copyright-protection) and [DVD Regionalization](https://learn.microsoft.com/windows-hardware/drivers/stream/dvd-regionalization).

## See also

[KSPROPERTY_DVDCOPY_REGION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-dvdcopy-region)