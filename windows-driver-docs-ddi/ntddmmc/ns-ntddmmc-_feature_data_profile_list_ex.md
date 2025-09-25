# _FEATURE_DATA_PROFILE_LIST_EX structure

## Description

The FEATURE_DATA_PROFILE_LIST_EX structure contains information corresponding to a profile list element in a profile list descriptor.

## Members

### `ProfileNumber`

Contains the profile number. This number must be one of the values defined by the [FEATURE_PROFILE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_profile_type) enumeration. **ProfileNumber**[0] must contain the most significant byte of the profile number. **ProfileNumber**[1] must contain the least significant byte.

### `Current`

Indicates, when set to 1, that this feature is currently active and the feature data is valid. When set to zero, this bit indicates that the feature is not currently active and that the feature data might not be valid.

### `Reserved1`

Reserved.

### `Reserved2`

Reserved.

## See also

[FEATURE_DATA_PROFILE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_data_profile_list)

[FEATURE_PROFILE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_profile_type)