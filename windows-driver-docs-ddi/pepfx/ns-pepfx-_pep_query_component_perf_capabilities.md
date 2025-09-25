# _PEP_QUERY_COMPONENT_PERF_CAPABILITIES structure (pepfx.h)

## Description

The **PEP_QUERY_COMPONENT_PERF_CAPABILITIES** structure specifies the number of performance state (P-state) sets that are defined for a component.

## Members

### `DeviceHandle` [in]

A PEPHANDLE value that identifies the device. The PEP supplied this handle in response to a previous [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification.

### `Component` [in]

The index that identifies the component. This member is an index into the **Components** array in the [PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2) structure that the PEP previously supplied in response to the **PEP_DPM_REGISTER_DEVICE** notification for this device. If the **Components** array contains N elements, component indexes range from 0 to N–1.

### `SetCount` [out]

The number of P-state sets that are defined for this component.

## Remarks

This structure is used by the [PEP_DPM_QUERY_COMPONENT_PERF_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_query_component_perf_capabilities) notification. The **DeviceHandle** and **Component** members contain input values that are supplied by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) when this notification is sent. The **SetCount** member contains an output value that the PEP writes to the structure in response to the notification.

## See also

[PEP_DEVICE_REGISTER_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_device_register_v2)

[PEP_DPM_QUERY_COMPONENT_PERF_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_query_component_perf_capabilities)

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)