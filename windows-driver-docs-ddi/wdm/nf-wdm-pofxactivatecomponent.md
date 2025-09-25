# PoFxActivateComponent function

## Description

The **PoFxActivateComponent** routine increments the activation reference count on the specified component.

## Parameters

### `Handle` [in]

A handle that represents the registration of the device with the power management framework (PoFx). The device driver previously received this handle from the [PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice) routine.

### `Component` [in]

The index that identifies the component. This parameter is an index into the **Components** array in the [PO_FX_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_device_v1) structure that the device driver used to register the device with PoFx. If the **Components** array contains N elements, component indexes range from 0 to N–1.

### `Flags` [in]

The flags for the activation operation. Set this member to zero or to one of the following flag **PO_FX_FLAG_*XXX*** bits:

These two flag bits are mutually exclusive. For more information, see Remarks.

| Value | Meaning |
| --- | --- |
| **PO_FX_FLAG_BLOCKING**<br><br>0x1 | Make the condition change synchronous. If this flag is set, the routine that requests the condition change does not return control to the calling driver until the component hardware completes the transition to the new condition. This flag can be used only if the caller is running at IRQL < DISPATCH_LEVEL. |
| **PO_FX_FLAG_ASYNC_ONLY**<br><br>0x2 | Make the condition change fully asynchronous. If this flag is set, the calling driver's callback routine is called from a thread other than the thread in which the routine that requests the condition change is called. Thus, the routine that requests the condition change always returns asynchronously without waiting for the callback to complete. |

## Remarks

Before a device driver can access a component in a device, the driver must first call **PoFxActivateComponent** to obtain an activation reference to the component. If the component is not already in the active condition, this call initiates a transition from the idle condition to the active condition. When this transition completes, PoFx calls the driver's [ComponentActiveConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_active_condition_callback) routine to notify the driver. The driver can access the hardware registers in a component only when the component is in the active condition.

If the component is already in the active condition when **PoFxActivateComponent** is called, no transition is required, and the *ComponentActiveConditionCallback* routine is not called.

After a component enters the active condition, it remains in the active condition for as long as the driver holds one or more activation references on the component. To release an activation reference, the driver calls the [PoFxIdleComponent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxidlecomponent) routine. When the driver releases the last activation reference on a component, **PoFxIdleComponent** initiates a transition from the active condition to the idle condition. A component that is in the idle condition can potentially enter a low-power Fx state.

If *Flags* = **PO_FX_FLAG_BLOCKING**, the **PoFxActivateComponent** call is synchronous. If the component is already in the active condition, the call increments the activation reference count and returns without waiting. Otherwise, **PoFxActivateComponent** waits to return until the component completes the transition to the active condition. In this case, if the component is not already in the F0 state when the call occurs, **PoFxActivateComponent** calls the driver's *ComponentIdleStateCallback* routine to initiate the transition to F0. After the component enters the F0 state, **PoFxActivateComponent** calls the driver's *ComponentActiveConditionCallback* routine to inform the driver that the component is in the active condition. These callbacks occur in the same thread as the call to **PoFxActivateComponent**, and **PoFxActivateComponent** returns only after the *ComponentActiveConditionCallback* callback returns.

If *Flags* = **PO_FX_FLAG_ASYNC_ONLY**, the **PoFxActivateComponent** call is asynchronous. If the component is already in the active condition, the call increments the activation reference count and returns. Otherwise, **PoFxActivateComponent** schedules the *ComponentIdleStateCallback* (if necessary) and *ComponentActiveConditionCallback* callbacks to occur in another thread, and then returns without waiting for either callback to occur. The callbacks can occur before or after **PoFxActivateComponent** returns. The driver relies on the *ComponentActiveConditionCallback* callback to determine when the component completes the transition to the active condition.

The driver can set *Flags* = 0 to indicate that it does not care whether the **PoFxActivateComponent** call is synchronous or asynchronous. In this case, PoFx decides whether to make the call synchronous or asynchronous.

Two or more code paths in the same driver might need to concurrently access a particular component. The **PoFxActivateComponent** and **PoFxIdleComponent** routines use activation reference counts to enable the various parts of the driver to independently maintain access to the component without requiring the driver to centrally manage access to the component.

PoFx maintains an activation reference count for each component in a device. A **PoFxActivateComponent** call increments this count by one, and a **PoFxIdleComponent** call decrements the count by one. When the count is nonzero, the component either is in the active condition or is in the process of switching to the active condition. A component that has a count of zero either is in the idle condition or is in the process of switching to the idle condition.

When a **PoFxActivateComponent** call causes the activation reference count to increment from 0 to 1, **PoFxActivateComponent** initiates a transition from the idle condition to the active condition. When a **PoFxIdleComponent** call causes the count to decrement from 1 to 0, **PoFxIdleComponent** initiates a transition from the active condition to the idle condition.

PoFx notifies the driver when a transition between the active condition and idle condition occurs. A *ComponentActiveConditionCallback* callback notifies the driver of a transition to the active condition, and a [ComponentIdleConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_condition_callback) callback notifies the driver of a transition to the idle condition. When a **PoFxActivateComponent** or **PoFxIdleComponent** call simply increments or decrements the activation reference count without causing such a transition, the driver receives no notification.

## See also

[ComponentActiveConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_active_condition_callback)

[ComponentIdleStateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_state_callback)

[PO_FX_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_device_v1)

[PoFxIdleComponent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxidlecomponent)

[PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice)