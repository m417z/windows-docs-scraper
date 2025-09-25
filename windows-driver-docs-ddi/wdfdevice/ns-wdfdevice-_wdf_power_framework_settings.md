# _WDF_POWER_FRAMEWORK_SETTINGS structure

## Description

[Applies to KMDF and UMDF]

The
**WDF_POWER_FRAMEWORK_SETTINGS** structure describes power management framework (PoFx) settings for single-component devices.

## Members

### `Size`

The size, in bytes, of this structure.

### `EvtDeviceWdmPostPoFxRegisterDevice`

A pointer to the driver's [EvtDeviceWdmPostPoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_post_po_fx_register_device) event callback function, or NULL.

### `EvtDeviceWdmPrePoFxUnregisterDevice`

A pointer to the driver's [EvtDeviceWdmPrePoFxUnregisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_pre_po_fx_unregister_device) event callback function, or NULL.

### `Component`

A pointer to a [PO_FX_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_v1) structure that describes the only component
in the single-component device, or NULL. If NULL, KMDF defaults to F0 support only for this component. This structure specifies the number and attributes of the F-states that the component supports, as well as the deepest Fx state from which the component can awaken.

### `ComponentActiveConditionCallback`

A pointer to the driver's [ComponentActiveConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_active_condition_callback) callback routine, or NULL. The power management framework (PoFx) calls this callback function when a component becomes active. While in the Active condition, the component is guaranteed to be in F0.

### `ComponentIdleConditionCallback`

A pointer to the driver's [ComponentIdleConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_condition_callback) callback function, or NULL. PoFx calls this callback function when a component becomes idle. While in the Idle condition, the component may be in any F-state, including F0.

### `ComponentIdleStateCallback`

A pointer to the driver's [ComponentIdleStateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_state_callback) callback function, or NULL. PoFx calls this callback function when the F-state of the component changes.

### `PowerControlCallback`

A pointer to the client driver's [PowerControlCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_power_control_callback) callback function, or NULL. PoFx calls this routine to pass a request for a power control operation directly to the driver. If your driver does not support any power control codes, set this parameter to NULL.

### `PoFxDeviceContext`

A context pointer that the framework supplies to [ComponentActiveConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_active_condition_callback),
[ComponentIdleConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_condition_callback), [ComponentIdleStateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_state_callback), and [PowerControlCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_power_control_callback).

### `PoFxDeviceFlags`

A value of type ULONGLONG containing the bitwise **OR** of the following values related to the [Directed Power Management Framework](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-the-directed-power-management-framework). This field is available starting in KMDF version 1.33 and UMDF 2.33.

**PO_FX_DEVICE_FLAG_DFX_CHILDREN_OPTIONAL**

When the Directed Power Framework ("DFx") is enabled on a device, typically child devices also enable DFx. However, in some cases (for example a pure software device), a child device does not implement power management. Set this flag to allow such a child device to skip DFx.

To set this flag on behalf of child devices, the parent WDF driver must:

* [Opt into DFx](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-the-directed-power-management-framework#requirements-for-wdf-non-miniport-drivers)
* Not be a bus driver
* Have at least one virtual child device created through a side-band channel (for example an upper filter or device created by calling [**SwDeviceCreate**](https://learn.microsoft.com/windows/win32/api/swdevice/nf-swdevice-swdevicecreate)

For drivers targeting pre-v33 WDF, instead specify the INF directive: **WdfDirectedPowerTransitionChildrenOptional**, which is available starting in Windows 10, version 1903. If the driver specifies the INF directive and sets this flag, the INF directive takes precedence.

**PO_FX_DEVICE_FLAG_DISABLE_FAST_RESUME**

This is required to implement **IRP_MN_QUERY_DEVICE_RELATIONS**/PowerRelations between two devices.

By default, WDF implements fast resume, which means that during system wakeup, the power policy owner in a device stack completes an S0-IRP without waiting to request and complete a D0-IRP. This does not work well with PowerRelations.

To make PowerRelations works properly, if a device depends on another device to enter D0 first, the second device should set this flag to opt out of fast resume.

In some cases, global policy may disable fast resume globally even if this flag is not set.

### `DirectedPoFxEnabled`

A WDF_TRI_STATE-typed enumerator that indicates whether the device enables Directed Power Management Framework (DFx). Available starting in KMDF version 1.33 and UMDF 2.33.

**WdfTrue** - DFx is enabled.
**WdfFalse** – DFx is disabled.
**WdfUseDefault** - The default value if the driver does not set one. This value has the same meaning as **WdfTrue**.

Directed PoFx (DFx) is available starting in Windows 10, version 1903 as an option for drivers that use **SystemManagedIdleTimeout** or **SystemManagedIdleTimeoutWithHint**.

 - For a driver targeting pre-v31 WDF, set the INF directive **WdfDirectedPowerTransitionEnable** to 1 to opt in to DFx.
- For a driver targeting v31+ WDF, DFx is enabled by default. The driver can set **WdfDirectedPowerTransitionEnable** to zero to opt out of DFx.
- For a driver targeting v33+ WDF, DFx is also enabled by default. The driver can either set **WdfDirectedPowerTransitionEnable** to zero or set this field to **WdfFalse** (recommended) to opt out of DFx. If both are set, the INF directive takes precedence.

## Remarks

The **WDF_POWER_FRAMEWORK_SETTINGS** structure is used an input to [WdfDeviceWdmAssignPowerFrameworkSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmassignpowerframeworksettings).

To initialize its **WDF_POWER_FRAMEWORK_SETTINGS** structure, your driver should call [WDF_POWER_FRAMEWORK_SETTINGS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_power_framework_settings_init).

For UMDF, only **Size**, **PoFxDeviceFlags**, and **DirectedPoFxEnabled** are used. Other fields are ignored and must be set to zero. The framework does this automatically when a UMDF driver calls [WDF_POWER_FRAMEWORK_SETTINGS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_power_framework_settings_init).

For more information, see [Supporting Functional Power States](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-functional-power-states) and [Overview of the Power Management Framework](https://learn.microsoft.com/windows-hardware/drivers/kernel/overview-of-the-power-management-framework).

This structure is not applicable to KMDF client drivers for multiple-component devices.

## See also

[EvtDeviceWdmPostPoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_post_po_fx_register_device)

[EvtDeviceWdmPrePoFxUnregisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_pre_po_fx_unregister_device)

[WDF_POWER_FRAMEWORK_SETTINGS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_power_framework_settings_init)

[WdfDeviceWdmAssignPowerFrameworkSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmassignpowerframeworksettings)