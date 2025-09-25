# WdfInterruptGetInfo function

## Description

[Applies to KMDF and UMDF]

The **WdfInterruptGetInfo** method retrieves information about a specified interrupt.

## Parameters

### `Interrupt` [in]

A handle to the interrupt object.

### `Info` [in, out]

A pointer to a caller-allocated [WDF_INTERRUPT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_info) structure that has been initialized by calling [WDF_INTERRUPT_INFO_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdf_interrupt_info_init).

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

The **WdfInterruptGetInfo** method can obtain interrupt information only if your driver calls it after the framework has called the driver's [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback function and before the framework has called the driver's [EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware) callback function.

After **WdfInterruptGetInfo** has returned, the driver can identify passive level interrupt objects by examining the **Irql** member of the [WDF_INTERRUPT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_info) structure. For passive level interrupt objects, this value is PASSIVE_LEVEL.

For information about the order in which a driver's callback functions are called, see [PnP and Power Management Scenarios](https://learn.microsoft.com/windows-hardware/drivers/wdf/pnp-and-power-management-scenarios).

For more information about handling interrupts in framework-based drivers, see [Handling Hardware Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-hardware-interrupts).

#### Examples

The following code example initializes a [WDF_INTERRUPT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_info) structure and calls **WdfInterruptGetInfo**.

```cpp
WDF_INTERRUPT_INFO  Info;

WDF_INTERRUPT_INFO_INIT(&Info);
WdfInterruptGetInfo(
                    Interrupt,
                    &Info
                    );
```

## See also

[EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware)

[EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware)

[WDF_INTERRUPT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_info)

[WDF_INTERRUPT_INFO_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdf_interrupt_info_init)