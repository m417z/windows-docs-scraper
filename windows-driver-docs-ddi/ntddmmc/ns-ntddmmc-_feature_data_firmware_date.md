# _FEATURE_DATA_FIRMWARE_DATE structure

## Description

The FEATURE_DATA_FIRMWARE_DATE structure holds the date information associated with the Firmware Information feature.

## Members

### `Header`

Contains a [FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header) structure with header information for this feature descriptor.

### `Year`

Contains the two low order decimal digits represented as ASCII characters that indicate the year. For example, if the year is 2013, the **Year** member will contain characters "33" (a hexadecimal value of 0x3133).

### `Month`

Contains two decimal digits represented as ASCII characters that indicate the month. For example, if the month is August, the **Month** member will contain characters "08" (a hexadecimal value of 0x3038).

### `Day`

Contains two decimal digits represented as ASCII characters that indicate the day. For example, if the day is August 12, the **Day** member will contain characters "12" (a hexadecimal value of 0x3132).

### `Hour`

Contains two decimal digits represented as ASCII characters that indicate the hour. For example, if the time 1:20:43 PM, the **Hour** member will contain the characters "13" (hexadecimal value of 0x3133).

### `Minute`

Contains two decimal digits represented as ASCII characters that indicates the minute of the hour. For example, if the time 1:20:43 PM, the **Minute** member will contain the characters "20" (hexadecimal value of 0x3230).

### `Seconds`

Contains two decimal digits represented as ASCII characters that indicates the minute of the hour. For example, if the time 1:20:43 PM, the **Seconds** member will contain the characters "43" (hexadecimal value of 0x3433).

### `Reserved`

Reserved.

## Remarks

The structure holds the date information associated with the feature named "Firmware Information" by the *SCSI Multimedia - 4* (*MMC-4*) specification. Devices that support this feature can be queried for the date and Greenwich Mean Time (GMT) of the creation of the firmware revision currently loaded on the device.

## See also

[FEATURE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)