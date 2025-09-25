# IAdapterPowerManagement2::PowerChangeState2

## Description

Portcls calls the `IAdapterPowerManagement2::PowerChangeState2` method to request a change to the new power state. This request is passed on to the adapter driver.

## Parameters

### `NewDeviceState` [in]

Specifies the new power state that Portcls has requested for the device. This parameter is an enumeration of type [DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state).

### `NewSystemState` [in]

Specifies the new power state that Portcls has requested for the system. This parameter is an enumeration of type [SYSTEM_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_system_power_state).

## Remarks

A power state indicates the level of power consumption of a device or system. As a result, the level of computing activity is directly affected by the power state of a device or system.

For more information about system power states, see [Handling System Power State Requests](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-system-power-state-requests). For more information about device power states, see [Managing Power for Individual Devices](https://learn.microsoft.com/windows-hardware/drivers/kernel/managing-power-for-individual-devices).

## See also

[DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state)

[Handling System Power State Requests](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-system-power-state-requests)

[IAdapterPowerManagement2](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iadapterpowermanagement2)

[Managing Power for Individual Devices](https://learn.microsoft.com/windows-hardware/drivers/kernel/managing-power-for-individual-devices)

[SYSTEM_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_system_power_state)