# _GET_CONFIGURATION_IOCTL_INPUT structure

## Description

The GET_CONFIGURATION_IOCTL_INPUT structure is used in conjunction with the [IOCTL_CDROM_GET_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_configuration) request to specify the sort of feature data that the request retrieves.

## Members

### `Feature`

Contains an enumerator value of type FEATURE_NUMBER that indicates the type of feature.

### `RequestType`

SCSI_GET_CONFIGURATION_REQUEST_TYPE_ALL - Instructs the device to report all of the profiles.

SCSI_GET_CONFIGURATION_REQUEST_TYPE_CURRENT - Instructs the device to report the current profile.

SCSI_GET_CONFIGURATION_REQUEST_TYPE_ONE - Instructs the device to report one and only one of the profiles.

### `Reserved`

Reserved.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)

[FEATURE_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ne-ntddmmc-_feature_number)

[IOCTL_CDROM_GET_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_configuration)