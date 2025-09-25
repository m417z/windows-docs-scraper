# PO_FX_COMPONENT_PERF_STATE_CALLBACK callback function

## Description

The *ComponentPerfStateCallback* callback routine notifies the driver that its request to change the performance state of a component is complete.

## Parameters

### `Context` [in]

A pointer to the device context. The device driver uses this context to store information about the current power state of the device. The device driver specified this pointer in the **DeviceContext** member of the [PO_FX_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_device_v1) structure that the driver used to register the device with the power management framework (PoFx). This context is opaque to PoFx.

### `Component` [in]

Specifies the index that identifies the component. This parameter is an index into the **Components** array in the **PO_FX_DEVICE** structure that the device driver used to register the device with PoFx. If the **Components** array contains N elements, component indexes range from 0 to N–1.

### `Succeeded` [in]

If TRUE, the platform extension plug-in (PEP) succeeded the performance state change. If FALSE, the PEP failed the performance state change. For more information, see the Remarks section.

### `RequestContext` [in]

Pointer to the optional driver or device context that was specified by the *Context* parameter of the [PoFxIssueComponentPerfStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxissuecomponentperfstatechange) or [PoFxIssueComponentPerfStateChangeMultiple](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxissuecomponentperfstatechangemultiple) routine.

## Remarks

When a device driver requests a performance state change by calling the [PoFxIssueComponentPerfStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxissuecomponentperfstatechange) or [PoFxIssueComponentPerfStateChangeMultiple](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxissuecomponentperfstatechangemultiple) routine, PoFx calls the *ComponentPerfStateCallback* routine to notify the driver when the request is complete.

To specify a *ComponentPerfStateCallback* routine, use the *ComponentPerfStateCallback* parameter of the [PoFxRegisterComponentPerfStates](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregistercomponentperfstates) routine when the driver registers for performance state management by PoFx. The *ComponentPerfStateCallback* routine may be the same for all components and all devices.

If *Succeeded* is TRUE, the driver should perform whatever work is necessary to change the performance state in the hardware. If *Succeeded* is FALSE, the driver may choose to do nothing or retry the request with the same performance state or an alternate performance state.

## See also

[PoFxIssueComponentPerfStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxissuecomponentperfstatechange)

[PoFxIssueComponentPerfStateChangeMultiple](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxissuecomponentperfstatechangemultiple)

[PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice)