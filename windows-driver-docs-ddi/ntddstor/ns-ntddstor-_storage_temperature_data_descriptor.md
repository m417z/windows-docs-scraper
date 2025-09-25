# STORAGE_TEMPERATURE_DATA_DESCRIPTOR structure

## Description

This structure is used in conjunction with [**IOCTL_STORAGE_QUERY_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) to return temperature data from a storage device or adapter.

## Members

### `Version`

Contains the size of this structure, in bytes. The value of this member will change as members are added to the structure.

### `Size`

Specifies the total size of the data returned, in bytes. This may include data that follows this structure.

### `CriticalTemperature`

Indicates the minimum temperature in degrees Celsius that may prevent normal operation. Exceeding this temperature may result in possible data loss, automatic device shutdown, extreme performance throttling, or permanent damage.

### `WarningTemperature`

Indicates the maximum temperature in degrees Celsius at which the device is capable of operating continuously without degrading operation or reliability.

### `InfoCount`

Specifies the number of [**STORAGE_TEMPERATURE_INFO*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_temperature_info) structures reported in **TemperatureInfo**. More than one set of temperature data may be returned when there are multiple sensors in the drive.

### `Reserved0[2]`

Reserved for future use.

### `Reserved1[2]`

Reserved for future use.

### `TemperatureInfo[ANYSIZE_ARRAY]`

Device temperature data, of type [**STORAGE_TEMPERATURE_INFO*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_temperature_info).

## See also

[**IOCTL_STORAGE_QUERY_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)

[**STORAGE_PROPERTY_ID*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_property_id)

[**STORAGE_PROPERTY_QUERY*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_property_query)

[**STORAGE_TEMPERATURE_INFO*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_temperature_info)