# _PEP_WORK_COMPLETE_IDLE_STATE structure (pep_x.h)

## Description

The **PEP_WORK_COMPLETE_IDLE_STATE** structure identifies a component that the platform extension plug-in (PEP) has prepared for a transition to a new F*x* power state.

## Members

### `DeviceHandle`

A handle that represents the registration of the device with the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/kernel/overview-of-the-power-management-framework) (PoFx). A POHANDLE value that represents the registration of the device with PoFx. The PEP previously received this handle from PoFx during the [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification that informed the PEP that the device's driver stack registered the device with PoFx.

### `Component` [in]

The index that identifies the component. This member is an index into the **Components** array in the [PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2) structure that the PEP previously supplied in response to the **PEP_DPM_REGISTER_DEVICE** notification for this device. If the **Components** array contains N elements, component indexes range from 0 to N–1.

## Remarks

The **CompleteIdleState** member of the [PEP_WORK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_information) structure is a **PEP_WORK_COMPLETE_IDLE_STATE** structure.

## See also

[PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2)

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)

[PEP_WORK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_information)