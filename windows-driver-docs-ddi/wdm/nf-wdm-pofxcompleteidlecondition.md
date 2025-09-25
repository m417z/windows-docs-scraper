# PoFxCompleteIdleCondition function

## Description

The **PoFxCompleteIdleCondition** routine informs the power management framework (PoFx) that the specified component has completed a pending change to the idle condition.

## Parameters

### `Handle` [in]

A handle that represents the registration of the device with PoFx. The device driver previously received this handle from the [PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice) routine.

### `Component` [in]

The index that identifies the component. This parameter is an index into the **Components** array in the [PO_FX_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_device_v1) structure that the device driver used to register the device with PoFx. If the **Components** array contains N elements, component indexes range from 0 to N–1.

## Remarks

After PoFx calls the driver's [ComponentIdleConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_condition_callback) callback routine, the driver must respond by calling **PoFxCompleteIdleCondition**.

When PoFx calls the driver's *ComponentIdleConditionCallback* routine, the driver initiates a transition to the idle condition in the specified component. After this transition is complete, the driver calls **PoFxCompleteIdleCondition** to notify PoFx. The **PoFxCompleteIdleCondition** call can occur either during or after the *ComponentIdleConditionCallback* call.

## See also

[ComponentIdleConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_condition_callback)

[PO_FX_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_device_v1)

[PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice)