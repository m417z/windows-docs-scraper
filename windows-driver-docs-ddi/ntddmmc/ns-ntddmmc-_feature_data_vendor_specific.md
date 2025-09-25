# _FEATURE_DATA_VENDOR_SPECIFIC structure

## Description

The FEATURE_DATA_VENDOR_SPECIFIC structure holds information about a vendor-specific feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `VendorSpecificData`

Contains an array that describes a vendor-specific feature.

## Remarks

You can use this structure to access the data of any feature structure as though it were a simple character array.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)