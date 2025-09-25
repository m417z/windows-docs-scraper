# IAdapterPowerManagement3::PowerChangeState3

## Description

PortCls calls the PowerChangeState3 method to request a change to the new power state. This request is passed on to the adapter driver.

## Parameters

### `NewDeviceState`

The new power state that Portcls has requested for the device. This parameter is an enumeration of type [DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state).

### `NewSystemState`

The new power state that Portcls has requested for the system. This parameter is an enumeration of type [SYSTEM_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_system_power_state).

### `D3ExitLatency`

The acceptable exit latency for the state into which the device is put when the device comes out of PowerDeviceD3. This parameter is an enumeration of type [PC_EXIT_LATENCY](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ne-portcls-_pc_exit_latency).

## Remarks

If the device is not going into its new state from PowerDeviceD3, then D3ExitLatency is set to PcExitLatencyInstant. For more information about the possible values for D3ExitLatency, see [D3ExitLatencyChanged](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iadapterpowermanagement3-d3exitlatencychanged).

## See also

[IAdapterPowerManagement3](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iadapterpowermanagement3)