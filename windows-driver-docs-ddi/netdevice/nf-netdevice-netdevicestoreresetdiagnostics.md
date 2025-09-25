## Description

The **NetDeviceStoreResetDiagnostics** function stores client driver collected reset diagnostics into the NetAdapterCx framework.

## Parameters

### `Device` [_In_]

The WDFDEVICE object the client driver previously created with a call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `ResetDiagnosticsSize` [_In_]

The size in bytes of the **ResetDiagnosticsBuffer**. The maximum size of reset diagnostics the framework accepts is 1 MB.

### `ResetDiagnosticsBuffer` [_In_reads_bytes_(ResetDiagnosticsSize)]

A pointer to the data buffer that holds the reset diagnostics data. The data buffer can come from either paged or non-paged pool.

## Remarks

The only valid scenario to invoke the **NetDeviceStoreResetDiagnostics** function is in a client driver's [*EVT_NET_DEVICE_COLLECT_RESET_DIAGNOSTICS*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_collect_reset_diagnostics) callback. The client driver must call **NetDeviceStoreResetDiagnostics** at PASSIVE_LEVEL

To learn how to correctly use the **NetDeviceStoreResetDiagnostics** function, see [Implement *EVT_NET_DEVICE_COLLECT_RESET_DIAGNOSTICS*](https://learn.microsoft.com/windows-hardware/drivers/netcx/platform-level-device-reset/#implement-EVT_NET_DEVICE_COLLECT_RESET_DIAGNOSTICS).

## See also

[Recovering an unresponsive NIC with NetAdapterCx PLDR](https://learn.microsoft.com/windows-hardware/drivers/netcx/platform-level-device-reset/)

[**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)

[*EVT_NET_DEVICE_COLLECT_RESET_DIAGNOSTICS*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_collect_reset_diagnostics)