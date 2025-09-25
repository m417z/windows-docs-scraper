# NVME_ENDURANCE_GROUP_LOG structure

## Description

Contains fields that specify the information in an Endurance Group Information log page that indicates the amount of data being read from and written to an Endurance Group.

This structure is returned by the Get Log Page command. For more information, see [NVME_CDW10_GET_LOG_PAGE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_log_page).

## Members

### `Reserved0`

### `AvailableSpareThreshold`

The amount of spare capacity before the threshold is reached, expressed as a normalized percentage (0 to 100).

### `PercentageUsed`

A vendor-specific estimate of the percentage of life used for the NVM set(s) in the Endurance Group, expressed in units of one billion.

### `Reserved1`

A reserved field.

### `EnduranceEstimate`

An estimate of the total number of data bytes written to NVM set(s) in the Endurance Group, expressed in units of one billion.

### `DataUnitsRead`

The total number of data bytes read from NVM set(s) in the Endurance Group, expressed in units of one billion.

### `DataUnitsWritten`

The total number of data bytes written to the NVM sets(s) in the Endurance Group, expressed in units of one billion.

This value only includes data written by the host.

### `MediaUnitsWritten`

The total number of data bytes written to the NVM sets(s) in the Endurance Group, expressed in units of one billion.

This value includes data written by the host and the controller.

### `Reserved2`

A reserved field.

## Remarks

## See also