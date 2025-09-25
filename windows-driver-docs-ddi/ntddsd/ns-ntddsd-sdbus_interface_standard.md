## Description

The SDBUS\_INTERFACE\_STANDARD structure contains pointers to the method routines of a Secure Digital (SD) card bus interface.

## Members

### `Size`

Indicates the size, in bytes, of this structure. The caller of [**SdBusOpenInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbusopeninterface) should set this member to **sizeof**(SDBUS\_INTERFACE\_STANDARD).

### `Version`

Indicates the version number of the interface. The caller of **SdBusOpenInterface** should set this member to SDBUS\_INTERFACE\_VERSION.

### `Context`

Pointer to context information that the bus driver provides whenever a device driver opens an interface with **SdBusOpenInterface**. This information is available to the caller on output after the call to **SdBusOpenInterface**. The caller must pass this information as a parameter to other interface routines.

### `InterfaceReference`

Pointer to a bus driver-supplied routine of type PINTERFACE\_REFERENCE that increments the interface's reference count that is available to the caller of the **SdBusOpenInterface** routine when this routine returns. **SdBusOpenInterface** automatically increments the interface count to one, so in most cases, it is necessary for the caller to use this routine.

This routine follows the standard format of bus interface reference routines. For a description of the general case, see [**INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface).

### `InterfaceDereference`

Pointer to a bus driver-supplied routine of type PINTERFACE\_DEREFERENCE that decrements the interface reference count. If the caller decrements the reference count to zero, the bus driver closes the interface.

This routine follows the standard format of bus interface dereference routines. For a description of the general case, see [**INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface).

Device drivers must use this routine to dereference the interface under the following conditions:

- The device driver receives a query remove IRP.
- The device driver receives a surprise remove IRP.
- The device driver receives a remove IRP, without first receiving a query remove or a surprise remove IRP.

In all of these cases, the device driver should dereference the interface before passing the IRP to the bus driver.

### `InitializeInterface`

Pointer to a bus driver-supplied routine of type [**PSDBUS\_INITIALIZE\_INTERFACE\_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nc-ntddsd-psdbus_initialize_interface_routine) that sets initialization parameters on the interface.

### `AcknowledgeInterrupt`

Pointer to a bus driver-supplied routine of type [**PSDBUS\_ACKNOWLEDGE\_INT\_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nc-ntddsd-psdbus_acknowledge_int_routine) that the SD device driver uses to notify the bus driver that it has finished processing an interrupt.

## Remarks

SD device drivers must obtain this set of method routines to communicate with the SD bus driver. Drivers call the [**SdBusOpenInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbusopeninterface) library routine to open an interface.

## See also

[**INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface)

[**PSDBUS\_ACKNOWLEDGE\_INT\_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nc-ntddsd-psdbus_acknowledge_int_routine)

[**SDBUS\_INTERFACE\_STANDARD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/ns-ntddsd-sdbus_interface_standard)

[**SdBusOpenInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbusopeninterface)