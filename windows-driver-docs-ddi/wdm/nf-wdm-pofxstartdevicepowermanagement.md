# PoFxStartDevicePowerManagement function

## Description

The **PoFxStartDevicePowerManagement** routine completes the registration of a device with the power management framework (PoFx) and starts device power management.

## Parameters

### `Handle` [in]

A handle that represents the registration of the device with the power management framework (PoFx). The device driver previously received this handle from the [PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice) routine.

## Remarks

After a driver calls the [PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice) routine to register a device with PoFx, all components in the device are fully on and in the active condition so that the driver can finish initializing the hardware. To start active power management, the driver must call **PoFxStartDevicePowerManagement**. By default, this call switches all components to the idle condition.

After **PoFxStartDevicePowerManagement** switches a component to the idle condition, PoFx might immediately start calling the driver's callback routines, even before **PoFxStartDevicePowerManagement** returns. PoFx calls the driver's [ComponentIdleConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_condition_callback) callback routine to indicate that a component has switched to the idle condition. The driver must not access a component that is in the idle condition. Before the driver can access the component, the driver must call the [PoFxActivateComponent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxactivatecomponent) and wait for PoFx to call the driver's [ComponentActiveConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_active_condition_callback) callback routine. This callback informs the driver that the component is in the active condition and can safely be accessed.

If the driver requires a component to be in the active condition immediately after power management starts, the driver must explicitly activate the component by calling the **PoFxActivateComponent** routine, and this call must occur after the **PoFxRegisterDevice** call but before the **PoFxStartDevicePowerManagement** call.

## See also

[ComponentActiveConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_active_condition_callback)

[ComponentIdleConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_condition_callback)

[PoFxActivateComponent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxactivatecomponent)

[PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice)