# IOCTL_POINT_OF_SERVICE_UPDATE_STATISTICS IOCTL

## Description

This I/O control function sets the specified statistic to the value in the input buffer.

## Parameters

### Major code

### Input buffer

[PosStatisticsHeader](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ns-pointofservicedriverinterface-_posstatisticsheader) where *PosStatisticsHeader.EntryCount* is set to the number of statistics to update.

This structure is then followed by a corresponding number of [PosValueStatisticsEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ns-pointofservicedriverinterface-_posvaluestatisticsentry) structures that contain the name of a statistic and the corresponding value to which it will be updated.

### Input buffer length

The sizeof(*PosStatisticsHeader*) + *PosStatisticsHeader.EntryCount* * sizeof(*PosValueStatisticsEntry*).

### Output buffer

Not used with this operation; set to **NULL**.

### Output buffer length

Not used with this operation; set to **0** (zero).

### Input/output buffer

### Input/output buffer length

### Status block

Returns **TRUE** if successful; otherwise, returns **FALSE**.

## Remarks

To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following is a common error value:

- STATUS_NOT_SUPPORTED: Statistic updating or reporting is not supported.