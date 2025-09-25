# NVME_CDW11_FEATURE_TEMPERATURE_THRESHOLD structure

## Description

Contains parameters for the Temperature Threshold feature that is used to set an over temperature threshold and an under temperature threshold for up to nine temperature values.

The values from this structure are used in the **TemperatureThreshold** field of the [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features) structure.

A controller may report up to nine temperature values in the [SMART / Health Information Log (NVME_HEALTH_INFO_LOG)](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_health_info_log). For example, the Composite Temperature and Temperature Sensor 1 through Temperature Sensor 8. Associated with each implemented temperature sensor is an over temperature threshold and an under temperature threshold. When a temperature is greater than or equal to its corresponding over temperature threshold or less than or equal to its corresponding under temperature threshold, then bit one of the **CriticalWarning** field in the **NVME_HEALTH_INFO_LOG** structure is set to one. This may trigger an asynchronous event.

The over temperature threshold feature is implemented for Composite Temperature. The under temperature threshold Feature is implemented for Composite Temperature if a non-zero Warning Composite Temperature Threshold **WCTEMP** field value is reported in the Identify Controller [NVME_IDENTIFY_CONTROLLER_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data) data structure. The over temperature threshold and under temperature threshold features are implemented for all implemented temperature sensors (all Temperature Sensor fields that report a non-zero value).

The default value of the over temperature threshold feature for Composite Temperature is the value in the **WCTEMP** field in the **NVME_IDENTIFY_CONTROLLER_DATA** data structure if **WCTEMP** is non-zero; otherwise, it is implementation specific. The default value of the over temperature threshold for all implemented temperature sensors is `FFFFh`. The default value for all implemented under temperature thresholds is `0h`.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.TMPTH`

Indicates the threshold for the temperature of the overall device (controller and NVM included) in units of Kelvin. This value is applied in a Set Features command and returned in a Get Features command, for the temperature sensor and threshold type specified.

### `DUMMYSTRUCTNAME.TMPSEL`

Specifies the temperature whose threshold is modified by a Set Features command and whose threshold value is returned by a Get Features command.

The following values are allowed for this field:

| Value | Description |
|--------------------|-----------------------------------------------------------------------------------------------------|
| `0000b` | Composite Temperature |
| `0001b` | Temperature Sensor 1 |
| `0010b` | Temperature Sensor 2 |
| `0011b` | Temperature Sensor 3 |
| `0100b` | Temperature Sensor 4 |
| `0101b` | Temperature Sensor 5 |
| `0110b` | Temperature Sensor 6 |
| `0111b` | Temperature Sensor 7 |
| `1000b` | Temperature Sensor 8 |
| `1001b` - `1110b` | Reserved |
| `1111b` | All implemented temperature sensors in a Set Features command. Reserved in a Get Features command. |

### `DUMMYSTRUCTNAME.THSEL`

Specifies an [NVME_TEMPERATURE_THRESHOLD_TYPES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_temperature_threshold_types) value that indicates the threshold type that is modified by a Set Features command and whose threshold value is returned by a Get Features command.

### `DUMMYSTRUCTNAME.Reserved0`

### `AsUlong`

## Remarks

## See also

- [NVME_IDENTIFY_CONTROLLER_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data)
- [NVME_TEMPERATURE_THRESHOLD_TYPES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_temperature_threshold_types)
- [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features)