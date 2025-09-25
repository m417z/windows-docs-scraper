# BCLASS_QUERY_INFORMATION_CALLBACK callback function

## Description

*BatteryMiniQueryInformation* returns information about the given battery device.

## Parameters

### `Context` [in]

A pointer to the context area allocated by the miniclass driver for the battery device.

### `BatteryTag` [in]

A pointer to a battery tag previously returned by *BatteryMiniQueryTag*.

### `Level` [in]

The type of battery information to be returned. Possible values are:

**BatteryInformation**
**BatteryGranularityInformation**
**BatteryTemperature**
**BatteryEstimatedTime**
**BatteryDeviceName**
**BatteryManufactureDate**
**BatteryManufactureName**
**BatteryUniqueID**
**BatterySerialNumber**

### `AtRate` [in]

The rate of drain, in negative milliwatts, used to calculate the time to discharge the battery. This parameter is meaningful only when *Level* is **BatteryEstimatedTime**; this parameter is ignored for all other values of *Level*.

### `Buffer` [out]

A pointer to a buffer that is allocated by the battery class driver. The buffer is used to return the requested information. The buffer is used to return the requested information. Miniclass drivers format the contents of the buffer depending upon the value of *Level*, as follows:

#### BatteryInformation

Return information formatted as a BATTERY_INFORMATION structure.

#### BatteryGranularityInformation

Return a variable-length array of type BATTERY_REPORTING_SCALE that contains the reporting granularity of the remaining capacity. The number of entries returned depends upon the size of the returned buffer, to a maximum of four entries per battery.

#### BatteryTemperature

Return a ULONG value giving the current temperature of the battery, in tenths of a degree Kelvin.

#### BatteryEstimatedTime

Return a ULONG value estimating the number of seconds of run time remaining on the battery, based on the rate of drain specified in *AtRate*. If *AtRate* is negative or zero, the miniclass driver should calculate the run time based on the current rate of drain. However, if the driver cannot make an estimate (for example, *AtRate* is zero and the battery is not discharging), it should return BATTERY_UNKNOWN_TIME.

#### BatteryDeviceName

Return a Unicode string specifying the name of the battery. For example, DR202 identifies a Duracell smart battery.

#### BatteryManufactureDate

Return a BATTERY_MANUFACTURE_DATE structure specifying the date the battery was manufactured.

#### BatteryManufactureName

Return a Unicode string specifying the model name given to the battery by its manufacturer.

#### BatteryUniqueID

Return a Unicode string that uniquely identifies the battery, typically a concatenation of the battery's manufacturer, date, and serial number.

#### BatterySerialNumber

Return a Unicode string that contains the battery's serial number.

### `BufferLength` [in]

The length, in bytes, of the buffer pointed to by *Buffer*.

### `ReturnedLength` [out]

The number of bytes returned in the buffer pointed to by *Buffer*.

## Return value

*BatteryMiniQueryInformation* returns one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The battery designated by *BatteryTag* is currently installed and the requested information has been returned. |
| **STATUS_NO_SUCH_DEVICE** | The battery designated by *BatteryTag* is not present. |
| **STATUS_INVALID_DEVICE_REQUEST** | The *Level* parameter specifies information that this battery does not support. |
| **STATUS_INVALID_PARAMETER** | The *Level*  parameter is not one of the enumerators listed. |

## Remarks

The battery class driver calls a miniclass driver's *BatteryMiniQueryInformation* routine to get various types of information about the battery. The information returned depends upon the *Level*  parameter. Not all batteries support all the possible types of information that the class driver might request. Miniclass drivers should return STATUS_INVALID_DEVICE_REQUEST for any such requests.

If *Level*  specifies **BatteryInformation**, the miniclass driver must return a BATTERY_INFORMATION structure in the buffer pointed to by *Buffer*. This structure contains status information about the battery, including its capabilities, technology (whether the battery is rechargeable), and chemistry; theoretical and actual full-charged capacity; critical bias; number of charge/discharge cycles; and the capacity levels at which warning alerts occur.

If *Level*  specifies **BatteryGranularityInformation**, the miniclass driver can return an array of one to four elements, formatted as BATTERY_REPORTING_SCALE structures. Each element of the array consists of a granularity value and a remaining capacity value, in milliwatt-hours. The granularity indicates the precision of measurement and thus is an indicator of the accuracy of the capacity.

Most types of batteries report capacity on a single scale. Miniclass drivers for these batteries return only one entry, giving the remaining capacity and the precision of the scale. Some batteries, however, have two scales: a gross scale that measures whether capacity is greater or less than fifty percent, and a finer scale that applies as capacity approaches zero. Miniclass drivers for such batteries should return two entries describing the two scales.

If *Level* specifies **BatteryEstimatedTime**, the miniclass driver must use the optional *AtRate*  parameter to estimate the amount of time remaining to use the battery. The *AtRate* parameter specifies a drain rate, in negative milliwatts.

If *Level* specifies **BatteryUniqueId**, the miniclass driver must return a string that uniquely identifies this particular battery. For control method and smart batteries, the unique ID is the concatenation of the manufacture name, the device name, the manufacture date, and the ASCII representation of the battery's serial number. This value is not meant to be displayed.

## See also

[BATTERY_INFORMATION](https://learn.microsoft.com/previous-versions/ff536283(v=vs.85))

[BATTERY_MANUFACTURE_DATE](https://learn.microsoft.com/previous-versions/ff536284(v=vs.85))

[BATTERY_REPORTING_SCALE](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/ns-wdm-battery_reporting_scale)