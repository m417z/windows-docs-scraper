# _GET_CONFIGURATION_HEADER structure

## Description

The GET_CONFIGURATION_HEADER structure is used to format the output data retrieved by the [IOCTL_CDROM_GET_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_configuration) request.

## Members

### `DataLength`

Indicates the amount of data, in bytes, that is being returned in the buffer area pointed to by the **Data** member. If the data length is greater than 65,530 bytes, multiple GET CONFIGURATION commands will be required for the Initiator to read all configuration data. The bytes in this array are arranged in big-endian order. **DataLength**[0] has the most significant byte, and **DataLength**[3] has the least significant byte.

### `Reserved`

Reserved.

### `CurrentProfile`

Contains an enumerator value of type [FEATURE_PROFILE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_profile_type) that indicates the device's current profile. The bytes in this array are arranged in big-endian order. **CurrentProfile**[0] has the most significant byte, and **CurrentProfile**[3] has the least significant byte.

### `Data`

Contains the feature data, beginning with the [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header).

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)

[FEATURE_PROFILE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_profile_type)

[IOCTL_CDROM_GET_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_configuration)