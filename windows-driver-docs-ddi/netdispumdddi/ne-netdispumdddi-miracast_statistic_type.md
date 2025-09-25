# MIRACAST_STATISTIC_TYPE enumeration

## Description

Specifies types of Miracast statistics data that the user-mode display driver generates.

## Constants

### `MIRACAST_STATISTIC_TYPE_CHUNK_PROCESSING_COMPLETE`

The user-mode display driver has completed its processing of the encode chunk.

### `MIRACAST_STATISTIC_TYPE_CHUNK_SENT`

The driver has successfully sent the encode chunk to the network.

### `MIRACAST_STATISTIC_TYPE_EVENT`

Used by the user-mode display driver to report certain Miracast protocol events to the operating system for diagnostic purposes.

### `MIRACAST_STATISTIC_TYPE_FORCE_UINT32`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. You should not use this value.

## Remarks

For more info on how the driver uses these enumeration values with reporting calls to the [ReportStatistic](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_report_statistic) callback function, see [Reporting Miracast encode chunks and statistics](https://learn.microsoft.com/windows-hardware/drivers/display/reporting-miracast-encode-chunks-and-statistics).

## See also

[ReportStatistic](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_report_statistic)