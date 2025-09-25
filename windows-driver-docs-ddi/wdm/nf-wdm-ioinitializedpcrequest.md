# IoInitializeDpcRequest function

## Description

The **IoInitializeDpcRequest** routine registers a driver-supplied [DpcForIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_dpc_routine) routine.

## Parameters

### `DeviceObject` [in]

Supplies a pointer to the [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure representing the physical device that generates interrupts.

### `DpcRoutine` [in]

Supplies a pointer to the driver-supplied *DpcForIsr* routine.

## Remarks

**IoInitializeDpcRequest** associates a driver-supplied [DpcForIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_dpc_routine) routine with a given device object. The driver's [InterruptService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kservice_routine) routine (ISR) can call [IoRequestDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iorequestdpc) to queue the *DpcForIsr* routine. The *DpcForIsr* routine completes interrupt-driven I/O operations at a lower IRQL than that of the ISR.

PnP drivers call **IoInitializeDpcRequest** from the [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routine.

For more information, see [DPC Objects and DPCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/dpc-objects-and-dpcs).

## See also

[AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device)

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[DpcForIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_dpc_routine)

[InterruptService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kservice_routine)

[IoRequestDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iorequestdpc)

[KeInitializeDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedpc)