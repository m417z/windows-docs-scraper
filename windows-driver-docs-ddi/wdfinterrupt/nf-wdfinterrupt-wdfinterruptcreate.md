# WdfInterruptCreate function

## Description

[Applies to KMDF and UMDF]

The **WdfInterruptCreate** method creates a framework interrupt object.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Configuration` [in]

A pointer to a [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config) structure that was initialized by a call to [WDF_INTERRUPT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdf_interrupt_config_init).

### `Attributes` [in, optional]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that specifies object attributes for the framework interrupt object. (See Remarks for additional information.) This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `Interrupt` [out]

A pointer to a location that receives a handle to the new interrupt object.

## Return value

**WdfInterruptCreate** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values.

| Return code | Description |
| --- | --- |
| **STATUS_INFO_LENGTH_MISMATCH** | The size of the WDF_INTERRUPT_CONFIG structure is incorrect. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_INVALID_DEVICE_STATE** | [WdfInterruptCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptcreate) was called after the device was started.<br><br>[WdfInterruptCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptcreate) also returns this value if the driver's [EVT_WDF_DEVICE_PREPARE_HARDWARE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback routine calls **WdfInterruptCreate** with the **InterruptRaw** and **InterruptTranslated** members of the [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config) structure set to **NULL**. |
| **STATUS_INSUFFICIENT_RESOURCES** | There was insufficient memory. |
| **STATUS_WDF_PARENT_ASSIGNMENT_NOT_ALLOWED** | In KMDF version 1.9 or earlier, the driver specified a non-**NULL** value for the **ParentObject** member of the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure.<br><br>In KMDF version 1.11 or later, the driver specified a value other than a framework device or queue for the **ParentObject** member of the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure. |
| **STATUS_WDF_INCOMPATIBLE_EXECUTION_LEVEL** | The **AutomaticSerialization** member of the [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config) structure is set to **TRUE** and either:<br><br>* The execution level of the interrupt's parent object is **WdfExecutionLevelPassive** and the driver has supplied [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc).<br>* The execution level of the interrupt's parent object is **WdfExecutionLevelDispatch** and the driver has supplied [EvtInterruptWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_workitem).<br><br>For more information, see [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config). |
| **STATUS_NOT_SUPPORTED** | The driver requested passive-level interrupt handling on a platform earlier than Windows 8. |

For a list of other return values that the **WdfInterruptCreate** method might return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Drivers typically call the **WdfInterruptCreate** method from an [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function. Starting in KMDF version 1.11 and UMDF version 2.0, drivers can call **WdfInterruptCreate** from [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware). If the driver calls **WdfInterruptCreate** from *EvtDriverDeviceAdd*, the **InterruptRaw** and **InterruptTranslated** members of the [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config) structure
must be NULL. If the driver calls **WdfInterruptCreate** from *EvtDevicePrepareHardware*, these members must both be valid.

If you are creating a wake-capable interrupt object, as described in [Using an Interrupt to Wake a Device](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-an-interrupt-to-wake-a-device), you must call **WdfInterruptCreate** from [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware).

 Your driver must call **WdfInterruptCreate** once for each interrupt vector that its device requires. If the device supports message-signaled interrupts (MSI), the driver must create an interrupt object for each message that the device can support.

After the PnP manager assigns system resources to the device, the framework stores information about the device's assigned interrupt resources in the interrupt objects that the driver has created. (Drivers that [do not support Plug and Play](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-kernel-mode-driver-framework-with-non-pnp-drivers) cannot use interrupt objects.)

The system might not assign all of the interrupt resources that a device can support. For example, a driver would create eight interrupt objects for a device that is capable of supporting eight MSI messages. However, the system might assign only one message to the device. In that case, seven of the interrupt objects will be unused.

Typically, your driver should store interrupt-specific information, such as the copied contents of device interrupt registers, in the interrupt object's [context space](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-context-space). The [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that the driver passes to **WdfInterruptCreate** should describe the context space.

For drivers using framework version 1.9 and earlier, the parent of each interrupt object is the device object that the interrupt belongs to. The driver cannot change this parent, and the **ParentObject** member of the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure must be **NULL**. Beginning in version 1.11, **ParentObject** can be a framework device object or queue object. If the driver specifies a parent, the driver must set the **AutomaticSerialization** member of the configuration structure to TRUE. The driver can specify a parent for both interrupts at DIRQL and [passive-level interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-passive-level-interrupts).

If your driver provides [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) or [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) callback functions for the framework interrupt object, note that the framework calls these callback functions at IRQL = PASSIVE_LEVEL.

For more information about handling interrupts in framework-based drivers, see [Handling Hardware Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-hardware-interrupts).

#### Examples

The following code example initializes a [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config) structure and a WDF_OBJECT_ATTRIBUTES structure and then calls **WdfInterruptCreate**.

```cpp
NTSTATUS  status;
WDF_INTERRUPT_CONFIG  interruptConfig;
WDF_OBJECT_ATTRIBUTES  interruptAttributes;

WDF_INTERRUPT_CONFIG_INIT(
                          &interruptConfig,
                          MyEvtInterruptIsr,
                          MyEvtInterruptDpc
                          );
WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(
                                        &interruptAttributes,
                                        INTERRUPT_DATA
                                        );
status = WdfInterruptCreate(
                            device,
                            &interruptConfig,
                            &interruptAttributes,
                            &devExt->WdfInterrupt
                            );
```

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config)

[WDF_INTERRUPT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdf_interrupt_config_init)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-object-attributes-init-context-type)