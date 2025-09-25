# PoFxSetComponentResidency function

## Description

The **PoFxSetComponentResidency** routine sets the estimated time for how long a component is likely to remain idle after the component enters the idle condition.

## Parameters

### `Handle` [in]

A handle that represents the registration of the device with the power management framework (PoFx). The device driver previously received this handle from the [PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice) routine.

### `Component` [in]

The index that identifies the component. This parameter is an index into the **Components** array in the [PO_FX_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_device_v1) structure that the device driver used to register the device with PoFx. If the **Components** array contains N elements, component indexes range from 0 to N–1.

### `Residency` [in]

The estimated residency time, in 100-nanosecond units. This parameter is a hint to PoFx about how long the component is likely to remain idle after a transition from the active condition to the idle condition. For more information, see Remarks.

## Remarks

The calling driver supplies an estimated residency time that PoFx can use as a hint to improve performance. PoFx uses this hint to select an appropriate low-power Fx state for a component that is in the idle condition.

The device driver can call **PoFxSetComponentResidency** each time a change in circumstances requires a change in the estimated residency time. After each call, the new estimated residency time remains in effect until the driver calls **PoFxSetComponentResidency** again to update it.

If a component is in the idle condition when **PoFxSetComponentResidency** is called, PoFx might change the component’s Fx state to accommodate the new estimated residency time specified by the caller.