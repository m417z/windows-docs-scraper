# _MIRACAST_DRIVER_INTERFACE structure

## Description

Contains pointers to wireless display (Miracast) functions that are implemented by the Miracast user-mode driver.

## Members

### `Size`

The size, in bytes, of the **MIRACAST_DRIVER_INTERFACE** structure that the driver returns when the operating system calls the [QueryMiracastDriverInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-query_miracast_driver_interface) function.

### `CreateMiracastContext`

A pointer to the driver's [CreateMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_create_miracast_context) function.

### `DestroyMiracastContext`

A pointer to the driver's [DestroyMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_destroy_miracast_context) function.

### `StartMiracastSession`

A pointer to the driver's [StartMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_start_miracast_session) function.

### `StopMiracastSession`

A pointer to the driver's [StopMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_stop_miracast_session) function.

### `HandleKernelModeMessage`

A pointer to the driver's [HandleKernelModeMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_handle_kmd_message) function.

## See also

[CreateMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_create_miracast_context)

[DestroyMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_destroy_miracast_context)

[HandleKernelModeMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_handle_kmd_message)

[QueryMiracastDriverInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-query_miracast_driver_interface)

[StartMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_start_miracast_session)

[StopMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_stop_miracast_session)