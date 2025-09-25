# _FEATURE_DATA_PROFILE_LIST structure

## Description

The FEATURE_DATA_PROFILE_LIST structure contains the data for a profile list descriptor.

## Members

### `Header`

Contains a header that indicates how many profiles are reported in the profile list descriptor. The [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure is used to describe both feature and profile list descriptors. When FEATURE_HEADER is used with a profile list descriptor the **FeatureCode** member of FEATURE_HEADER must be set to zero, the **Current** member must be set to 1, the **Version** member must be set to zero, and the **Persistent** member must be set to 1. The **Persistent** member is set to 1, because all devices that are compliant with the *SCSI Multimedia - 4 (MMC-4)* standard must support reporting of the profile list. The **AdditionalLength** member must be set to ((number of profile descriptors) * 4). See the *MMC-3* specification For more information about the values assigned to these members.

### `Profiles`

Contains a variable length array of [FEATURE_DATA_PROFILE_LIST_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_data_profile_list_ex) structures that describe all the profiles supported by the device.

## Remarks

This structure holds data for the feature named "Profile List" by the *MMC-3* specification. This feature provides a list of all profiles supported by the device.

## See also

[FEATURE_DATA_PROFILE_LIST_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_data_profile_list_ex)

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_PROFILE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_profile_type)