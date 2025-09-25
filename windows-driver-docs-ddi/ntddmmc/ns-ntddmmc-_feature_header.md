# FEATURE_HEADER structure

## Description

The **FEATURE_HEADER** structure is used in conjunction with the [**IOCTL_CDROM_GET_CONFIGURATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_configuration) request to report header information for both feature and profile descriptors.

## Members

### `FeatureCode`

Contains a value between zero and 0xffff that indicates a feature. The [**FEATURE_NUMBER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number) enumeration provides a list of currently supported feature numbers. **FeatureCode**[0] contains the most significant byte of the feature number. **FeatureCode**[1] contains the least significant byte.

### `Current`

When set to 1, indicates that this feature is currently active and the data reported for the feature is valid. When set to zero, this bit indicates that the feature is not currently active and that the data reported for the feature might not be valid.

### `Persistent`

Indicates, when set to 1, that the feature is always active. When set to zero, this bit indicates that the feature is not always active.

### `Version`

Must be set to zero unless otherwise specified within the description for a particular feature.

### `Reserved0`

Reserved.

### `AdditionalLength`

Indicates the number of bytes of feature information that follow this header. This member must be an integral multiple of 4. The total size of the data related to this feature will be **AdditionalLength** + ```sizeof(FEATURE_HEADER)```.

## See also

[**FEATURE_NUMBER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)

[**GET_CONFIGURATION_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_get_configuration_header)

[**IOCTL_CDROM_GET_CONFIGURATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_configuration)