# _PEP_COMPONENT_ACTIVE structure

## Description

The **PEP_COMPONENT_ACTIVE** structure identifies a component that is making a transition between the idle condition and the active condition.

## Members

### `DeviceHandle` [in]

A PEPHANDLE value that identifies the device. The PEP supplied this handle in response to a previous [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification.

### `Component` [in]

The index that identifies the component. This member is an index into the **Components** array in the [PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2) structure that the PEP previously supplied in response to the **PEP_DPM_REGISTER_DEVICE** notification for this device. If the **Components** array contains N elements, component indexes range from 0 to N–1.

### `Active` [in]

Whether the component is making a transition to the active condition. If TRUE, the component is making a transition from the idle condition to the active condition. If FALSE, the component is making a transition from the active condition to the idle condition.

### `WorkInformation` [out]

A pointer to a [PEP_WORK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_information) structure that describes the work that the PEP requests in response to this notification. If **NeedWork** is TRUE, **WorkInformation** must point to a valid **PEP_WORK_INFORMATION** structure. If **NeedWork** is FALSE, **WorkInformation** must be NULL.

### `NeedWork` [out]

Whether the PEP has a work request to submit in response to this notification. Set to TRUE if the PEP has work to request, or to FALSE if the PEP has no work to request.

## Remarks

This structure is used by the [PEP_DPM_COMPONENT_ACTIVE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_component_active) notification. The first three members of the structure contain input values that are supplied by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx). The last two members contain output values that the PEP writes to the structure in response to this notification.

## See also

[PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2)

[PEP_DPM_COMPONENT_ACTIVE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_component_active)

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)

[PEP_WORK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_information)