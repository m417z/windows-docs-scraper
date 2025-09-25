# PoFxIdleComponent function

## Description

The **PoFxIdleComponent** routine decrements the activation reference count on the specified component.

## Parameters

### `Handle` [in]

A handle that represents the registration of the device with the power management framework (PoFx). The device driver previously received this handle from the [PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice) routine.

### `Component` [in]

The index that identifies the component. This parameter is an index into the **Components** array in the [PO_FX_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_device_v1) structure that the device driver used to register the device with PoFx. If the **Components** array contains N elements, component indexes range from 0 to N–1.

### `Flags` [in]

The flags for the idle operation. Set this member to zero or to one of the following flag [PO_FX_FLAG_XXX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxissuecomponentperfstatechange) bits:

* **PO_FX_FLAG_BLOCKING**
* **PO_FX_FLAG_ASYNC_ONLY**

These two flag bits are mutually exclusive. For more information, see Remarks.

## Remarks

A device driver calls **PoFxIdleComponent** to release an activation reference to a component in a device. The driver obtained the activation reference in a previous call to the [PoFxActivateComponent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxactivatecomponent) routine. The driver should hold an activation reference on a component only while the driver needs to access the component. To hold an activation reference on a component that is not being used prevents the component from entering a low-power Fx state.

If the driver holds no other activation references to the component, **PoFxIdleComponent** initiates a transition from the active condition to the idle condition. When this transition completes, PoFx calls the driver's [ComponentIdleConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_condition_callback) routine to notify the driver. If the driver retains one or more additional activation references on the component, the component stays in the active condition, and the *ComponentIdleConditionCallback* routine is not called.

PoFx maintains an activation reference count for each component in the device. The **PoFxActivateComponent** routine increments this count, and **PoFxIdleComponent** decrements it. The component remains in the active condition while this count is nonzero. When the driver releases its last activation reference to a component, the count decrements to zero and the component enters the idle condition. After the component enters the idle condition, PoFx can potentially switch the component to a low-power Fx state. For more information, see [PoFxActivateComponent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxactivatecomponent).

If *Flags* = **PO_FX_FLAG_BLOCKING**, the **PoFxIdleComponent** call is synchronous. In this case, **PoFxIdleComponent** waits to return until the component completes the transition to the idle condition. **PoFxIdleComponent** calls the driver's *ComponentIdleConditionCallback* callback routine to inform the driver that the component is in the idle condition. This callback occurs in the same thread as the call to **PoFxIdleComponent**, and **PoFxIdleComponent** returns only after the *ComponentIdleConditionCallback* callback returns.

If *Flags* = **PO_FX_FLAG_ASYNC_ONLY**, the **PoFxIdleComponent** call is asynchronous. In this case, **PoFxIdleComponent** schedules the *ComponentIdleConditionCallback* callback to occur in another thread, and then returns without waiting for the callback to occur. The callback can occur before or after **PoFxIdleComponent** returns. The driver should rely on the *ComponentIdleConditionCallback* callback to determine when the component completes the transition to the idle condition. Until this callback occurs, the driver should assume that the component might still be in the active condition.

The driver can set *Flags* = 0 to indicate that it does not care whether the **PoFxIdleComponent** call is synchronous or asynchronous. In this case, PoFx decides whether to make the call synchronous or asynchronous.

## See also

[ComponentIdleConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_condition_callback)

[PO_FX_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_device_v1)

[PO_FX_FLAG_XXX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxissuecomponentperfstatechange)

[PoFxActivateComponent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxactivatecomponent)

[PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice)