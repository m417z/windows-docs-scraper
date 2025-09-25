# POFXCALLBACKCRITICALRESOURCE callback function (pepfx.h)

## Description

The **TransitionCriticalResource** routine changes the active/inactive state of a core system component.

## Parameters

### `DeviceHandle` [in]

A POHANDLE value that represents the registration of the device with PoFx. The PEP previously received this handle from PoFx during the [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification that informed the PEP that the device's driver stack registered the device with PoFx.

### `Component` [in]

[in] The index that identifies the component. This member is an index into the **Components** array in the [PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2) structure that the PEP previously supplied in response to the **PEP_DPM_REGISTER_DEVICE** notification for this device. If the **Components** array contains N elements, component indexes range from 0 to N–1.

### `Active` [in]

Whether to transition the device from inactive to active, or vice versa. Set to TRUE to transition the device from inactive to active, or to FALSE to transition the device from active to inactive.

## Remarks

This routine is implemented by the power management framework (PoFx) and is called by the platform extension plug-in (PEP). The **TransitionCriticalResource** member of the [PEP_KERNEL_INFORMATION_STRUCT_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_kernel_information_struct_v3) structure is a pointer to an **TransitionCriticalResource** routine.

A PEP can call this routine at IRQL <= HIGH_LEVEL.

## See also

[PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2)

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)

[PEP_KERNEL_INFORMATION_STRUCT_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_kernel_information_struct_v3)