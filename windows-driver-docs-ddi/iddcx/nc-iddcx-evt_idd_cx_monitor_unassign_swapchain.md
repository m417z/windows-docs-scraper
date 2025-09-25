# EVT_IDD_CX_MONITOR_UNASSIGN_SWAPCHAIN callback function

## Description

**EVT_IDD_CX_MONITOR_UNASSIGN_SWAPCHAIN** is called by the OS to inform the driver that a swapchain associated with a monitor is not valid anymore.

## Parameters

### `MonitorObject` [in]

A handle by the OS to identify the monitor that has an invalid associated swapchain.

## Return value

(NTSTATUS) If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise, an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.