# _FEATURE_DATA_RESERVED structure

## Description

The FEATURE_DATA_RESERVED structure holds information about an unspecified feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `Data`

Contains an array describing unspecified feature structure members.

## Remarks

You can use this structure to access the data of any feature structure as though it were a simple character array.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)