# PSDBUS_ACKNOWLEDGE_INT_ROUTINE callback function

## Description

The PSDBUS_ACKNOWLEDGE_INT_ROUTINE prototype declares the routine that a Secure Digital (SD) device driver must call to acknowledge to the bus driver that it has finished processing the interrupt.

## Parameters

### `Context` [in]

Contains the interface context that the [SdBusOpenInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbusopeninterface) routine returns in the **Context** member of the [SDBUS_INTERFACE_STANDARD](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537923(v=vs.85)) structure.

## Return value

Returns STATUS_UNSUCCESSFUL if the operation succeeds, or the appropriate error message if the operation fails.

## Remarks

When an SD device asserts an interrupt, the bus driver disables the interrupt that the device asserted to allow the device driver to perform I/O at IRQL <=DISPATCH_LEVEL. When the device driver's callback routine, which is equivalent to an interrupt service routine, finishes clearing the interrupt, it should acknowledge that it has finished interrupt processing so that the bus driver can re-enable the disabled interrupt.

Traditionally, drivers acknowledge interrupts by simply returning the appropriate value from the interrupt service routine (ISR). When drivers rely on this method, they are constrained to acknowledge interrupts in the order that they receive them. An SD card driver, on the other hand, is *not* constrained to acknowledge interrupts in the order that they are received. Typically, a driver for an SD card might report several interrupts to the bus driver (see [PSDBUS_CALLBACK_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nc-ntddsd-sdbus_callback_routine)) before acknowledging any of them. Under normal operating conditions, an SD card driver defers acknowledging an interrupt until the interrupt state on the device has cleared.

The caller must be running at IRQL <= DISPATCH_LEVEL when it acknowledges that it has finished processing an interrupt.

## See also

[SDBUS_INTERFACE_STANDARD](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537923(v=vs.85))

[SdBusOpenInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbusopeninterface)