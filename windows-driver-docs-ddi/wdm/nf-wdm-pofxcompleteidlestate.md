# PoFxCompleteIdleState function

## Description

The **PoFxCompleteIdleState** routine informs the power management framework (PoFx) that the specified component has completed a pending change to an Fx state.

## Parameters

### `Handle` [in]

A handle that represents the registration of the device with PoFx. The device driver previously received this handle from the [PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice) routine.

### `Component` [in]

The index that identifies the component. This parameter is an index into the **Components** array in the [PO_FX_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_device_v1) structure that the device driver used to register the device with PoFx. If the **Components** array contains N elements, component indexes range from 0 to N–1.

## Remarks

After PoFx calls the driver's [ComponentIdleStateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_state_callback) callback routine, the driver must respond by calling **PoFxCompleteIdleState**.

PoFx calls the driver's *ComponentIdleStateCallback* routine to tell the driver to switch the specified component to a new Fx power state. After the driver completes the transition to the new Fx state, the driver calls **PoFxCompleteIdleState** to inform PoFx. The **PoFxCompleteIdleState** call can occur either during or after the *ComponentIdleStateCallback* call.

## See also

[ComponentIdleStateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_state_callback)

[PO_FX_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_device_v1)

[PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice)