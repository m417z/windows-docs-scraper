# IOCTL_POINT_OF_SERVICE_RETRIEVE_STATISTICS IOCTL

## Description

This I/O control function returns unified point of service (UPOS) standard information about a device such as its category, manufacturer, and firmware revision number.

## Parameters

### Major code

### Input buffer

[in] Not used with this operation; set to **NULL**.

### Input buffer length

Not used with this operation; set to **0** (zero).

### Output buffer

Pointer to the [PosStatisticsHeader](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ns-pointofservicedriverinterface-_posstatisticsheader) structure that contains the statistics.

### Output buffer length

Size of the output buffer in bytes. Set to sizeof(*PosStatisticsHeader*).

### Input/output buffer

### Input/output buffer length

### Status block

Returns **TRUE** if successful; otherwise, returns **FALSE**.

## Remarks

To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following list shows common error values:

- STATUS_BUFFER_OVERFLOW: The output buffer is not large enough to hold the statistics.

- STATUS_NOT_SUPPORTED: Statistic reporting is not supported.