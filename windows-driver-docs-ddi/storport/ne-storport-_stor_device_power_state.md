# STOR_DEVICE_POWER_STATE enumeration (storport.h)

## Description

The **STOR_DEVICE_POWER_STATE** enumerator specifies a storage device power state.

## Constants

### `StorPowerDeviceUnspecified`

The device power state is unspecified.

### `StorPowerDeviceD0`

Maximum device power state, which corresponds to [device working state D0](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-working-state-d0).

### `StorPowerDeviceD1`

The [device sleeping state](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-sleeping-states) that is less than **StorPowerDeviceD0** and greater than **StorPowerDeviceD2**, which corresponds to device power state D1.

### `StorPowerDeviceD2`

The device sleeping state that is less than **StorPowerDeviceD1** and greater than **StorPowerDeviceD3**, which corresponds to device power state D2.

### `StorPowerDeviceD3`

The lowest-powered device sleeping state, which corresponds to device power state D3.

### `StorPowerDeviceMaximum`

The upper delimiting value on device power states.

## See also

[**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control)

[**SCSI_POWER_REQUEST_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_scsi_power_request_block)

[**STOR_UNIT_CONTROL_POWER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_unit_control_power)