# _PEP_DEVICE_POWER_STATE structure (pepfx.h)

## Description

The **PEP_DEVICE_POWER_STATE** structure indicates the status of a transition to a new D*x* (device power) state.

## Members

### `DeviceHandle` [in]

The PEPHANDLE value that identifies this device. The PEP previously created this handle in response to a [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification from the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/kernel/overview-of-the-power-management-framework) (PoFx).

### `PowerState` [in]

A [DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state) enumeration value that specifies the new device power state.

### `Complete` [in]

Whether the transition to the new device power state has just been initiated or has just completed. If TRUE, the transition to the target device power state has completed. If FALSE, the power policy owner (PPO) has initiated the transition by calling the [PoRequestPowerIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-porequestpowerirp) routine, but the Windows power manager has not yet issued the D*x* IRP (an [IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power) request of type **DevicePowerState**) to the device's driver stack.

### `SystemTransition` [in]

Always set to FALSE.

## Remarks

This structure is used by the [PEP_DPM_DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-peps-for-acpi-services) notification. All four members of the structure contain input values that are supplied by PoFx. The PEP does not write to this structure.

## See also

[DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state)

[IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power)

[PEP_DPM_DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-peps-for-acpi-services)

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)

[PoRequestPowerIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-porequestpowerirp)