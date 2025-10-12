# PoFxRegisterDevice function

## Description

The **PoFxRegisterDevice** routine registers a device with the power management framework (PoFx).

## Parameters

### `Pdo` [in]

A pointer to a [physical device object](https://learn.microsoft.com/windows-hardware/drivers/) (PDO). This parameter points to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that represents the physical device that is being registered. The caller is the power policy owner for the device, which is typically the device's function driver.

### `Device` [in]

A pointer to a caller-allocated [PO_FX_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_device_v1) structure that contains the registration information for the device. This structure contains pointers to a set of callback routines that are implemented by the device driver. PoFx calls these routines to communicate with the driver.

### `Handle` [out]

A pointer to a location into which the routine writes a handle that represents the registration of the device with PoFx. The device driver passes this handle as an input parameter to the other **PoFx*Xxx*** routines that it calls. The driver must first call **PoFxRegisterDevice** to register the device before the driver calls any other **PoFx*Xxx*** routines to power-manage the device.

## Return value

**PoFxRegisterDevice** returns **STATUS_SUCCESS** if the routine successfully registers the device. Possible error return values include the following status codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | *Pdo* is NULL; or the **PPO_FX_DEVICE** structure has an invalid version number or a component count of zero; or the number of idle states specified for a component is zero; or the description of an idle state is invalid. |
| **STATUS_DEVICE_NOT_READY** | The device is not ready. |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient resources are available to complete the registration. |

## Remarks

A device driver typically calls this routine from the driver's [IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device) request handler. The driver must not call this routine before the device receives an **IRP_MN_START_DEVICE** request. The device receives the first **IRP_MN_START_DEVICE** request when the device is being started for the first time. The device receives an additional **IRP_MN_START_DEVICE** request each time the device is restarted after being stopped for resource balancing. A **PoFxRegisterDevice** call to register a device that is already registered is a fatal error and causes a bug check. Note that PoFx performs a deep-copy of the device structures into its memory.

Before the driver calls **PoFxRegisterDevice**, the device must meet the following conditions:

* The device (that is, the PDO) is not already registered with PoFx.
* The device is in the D0 (fully on) power state.
* The device is in the running condition.
* Every component in the device is in the F0 (fully on) power state.
* Every component is in the active condition.

By registering the device with PoFx, the driver assumes the responsibility for informing PoFx when a component is actively being used and when the component is idle. While the device is registered, the driver must call the [PoFxActivateComponent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxactivatecomponent) routine to gain access to a component's hardware registers, and the driver must call the [PoFxIdleComponent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxidlecomponent) routine to notify PoFx when the driver no longer requires access to the component.

After a driver calls **PoFxRegisterDevice** to register a device with PoFx, all components in the device are fully on and in the active condition so that the driver can finish initializing the hardware. To start active power management, the driver must call the [PoFxStartDevicePowerManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxstartdevicepowermanagement) routine.

By default, **PoFxStartDevicePowerManagement** switches all components to the idle condition. If the driver requires a component to be in the active condition immediately after power management starts, the driver must explicitly activate the component by calling the **PoFxActivateComponent** routine, and this call must occur after the **PoFxRegisterDevice** call but before the **PoFxStartDevicePowerManagement** call.

Typically, the Kernel-Mode Driver Framework (KMDF) driver for a single-component device does not call **PoFxRegisterDevice** to register the device with PoFx. Instead, this driver receives a PoFx registration handle when KMDF calls the driver's [EvtDeviceWdmPostPoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_post_po_fx_register_device) callback function. For more information, see [Supporting Multiple Functional Power States for Single-Component Devices](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-multiple-functional-power-states-for-single-component-devices).

For information about how the KMDF driver for a multiple-component device registers with PoFx, see [Supporting Multiple Functional Power States for Multiple-Component Devices](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-multiple-functional-power-states-for-multiple-component-devices).

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[EvtDeviceWdmPostPoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_post_po_fx_register_device)

[IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device)

[PO_FX_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_device_v1)

[PoFxActivateComponent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxactivatecomponent)

[PoFxIdleComponent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxidlecomponent)

[PoFxStartDevicePowerManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxstartdevicepowermanagement)