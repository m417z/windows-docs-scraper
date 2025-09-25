# IoCreateController function

## Description

The **IoCreateController** routine allocates memory for and initializes a controller object with a controller extension of a driver-determined size.

## Parameters

### `Size` [in]

Specifies the number of bytes to be allocated for the controller extension.

## Return value

**IoCreateController** returns a pointer to the controller object or a **NULL** pointer if memory could not be allocated for the requested device extension.

## Remarks

A controller object usually represents a physical device controller with attached devices on which a single driver carries out I/O requests. The controller extension is allocated from nonpaged pool and is guaranteed to be accessible by any driver routine and in an arbitrary thread context.

The controller object is used to synchronize I/O operations to target devices for which I/O requests can come in concurrently to a single, monolithic driver. A driver also might use a controller object to synchronize operations through device channels.

If **IoCreateController** returns **NULL**, the driver should fail device start-up.

## See also

[CONTROLLER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_controller_object)

[IoAllocateController](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioallocatecontroller)

[IoDeleteController](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iodeletecontroller)

[IoFreeController](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iofreecontroller)