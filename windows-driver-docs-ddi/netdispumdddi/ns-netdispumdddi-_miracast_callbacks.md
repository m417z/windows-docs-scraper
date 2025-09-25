# _MIRACAST_CALLBACKS structure

## Description

Contains pointers to wireless display (Miracast) runtime callback functions that the Miracast user-mode driver can call.

## Members

### `ReportSessionStatus`

A pointer to the [ReportSessionStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_report_session_status) function.

### `MiracastIoControl`

A pointer to the [MiracastIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_miracast_io_control) function.

### `ReportStatistic`

A pointer to the [ReportStatistic](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_report_statistic) function.

### `GetNextChunkData`

A pointer to the [GetNextChunkData](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_get_next_chunk_data) function.

### `RegisterForDataRateNotifications`

A pointer to the [RegisterForDataRateNotifications](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_register_datarate_notifications) function.