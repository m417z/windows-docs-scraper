# _WINBIO_SET_INDICATOR structure

## Description

The WINBIO_SET_INDICATOR structure is the IN payload for [IOCTL_BIOMETRIC_SET_INDICATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ni-winbio_ioctl-ioctl_biometric_set_indicator).

## Members

### `PayloadSize`

Specifies the total size of the payload, which includes the fixed length structure and any variable data at the end.

### `IndicatorStatus`

Specifies a WINBIO_INDICATOR_STATUS that indicates whether the indicator light should be set on or off.

Possible values are shown in the following table.

|Indicator status code|Description|
|--- |--- |
|WINBIO_INDICATOR_ON|The indicator light is on, and changes according to the sensor status. To be able to set WINBIO_INDICATOR_ON, you must set WINBIO_CAPABILITY_INDICATOR in the Capabilities member of the WINBIO_SENSOR_ATTRIBUTES structure.|
|WINBIO_INDICATOR_OFF|The sensor indicator light is off. Sensors that do not have an indicator light will always return this value in IOCTL_GET_SENSOR_STATUS.|

## See also

[IOCTL_BIOMETRIC_SET_INDICATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ni-winbio_ioctl-ioctl_biometric_set_indicator)

[WINBIO_GET_INDICATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_get_indicator)