# PFN_REPORT_STATISTIC callback function

## Description

Called by the user-mode display driver to report the statistics of the Miracast link to the operating system.The data type of this function is **PFN_REPORT_STATISTIC**.

## Parameters

### `hMiracastDeviceHandle` [in]

A handle that represents a Miracast device. The Miracast user-mode driver previously obtained this handle as the *hMiracastDeviceHandle* parameter in a call to the [CreateMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_create_miracast_context) function.

### `pStatistics` [in]

A pointer to a [MIRACAST_STATISTIC_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-miracast_statistic_data) structure that contains the statistics data.

## Remarks

When the operating system calls this function, it logs the data from the *pStatistics* parameter but takes no other action.

For more info on how to use this function, see these topics:

* [Miracast user-mode driver tasks to support Miracast wireless displays](https://learn.microsoft.com/windows-hardware/drivers/display/miracast-user-mode-driver-tasks-to-support-miracast-wireless-displays)
* [Reporting Miracast encode chunks and statistics](https://learn.microsoft.com/windows-hardware/drivers/display/reporting-miracast-encode-chunks-and-statistics)

## See also

[CreateMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_create_miracast_context)

[MIRACAST_STATISTIC_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-miracast_statistic_data)