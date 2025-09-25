# _NOTIFICATION_INFO_W2K structure

## Description

The bus driver passes NOTIFICATION_INFO to pass information to the driver-provided notification routine for a driver-allocated address range in the computer's IEEE 1394 address space. The bus driver calls the notification routine when it receives an asynchronous I/O request packet for that address.

## Members

### `Mdl`

If non-**NULL**, **Mdl** specifies the [memory descriptor list (MDL)](https://learn.microsoft.com/windows-hardware/drivers/) for the allocated address range.

### `ulOffset`

Specifies the byte offset with the MDL that corresponds to the address that received a request packet. Only used when **Mdl** is non-**NULL**.

### `nLength`

Specifies the number of bytes affected by the request packet. Only used when **Mdl** is non-**NULL**.

### `fulNotificationOptions`

Specifies which type of event triggered the bus driver to call the notification routine. The possible events the bus driver can return are the following:

- NOTIFY_FLAGS_AFTER_READ
- NOTIFY_FLAGS_AFTER_WRITE
- NOTIFY_FLAGS_AFTER_LOCK

This member is only used when **Mdl** is non-**NULL**.

### `Context`

Pointer to specific context data for this allocated address range. The driver supplies this data through the **u.AllocateAddressRange.Context** member of the IRB for the original REQUEST_ALLOCATE_ADDRESS_RANGE request.

### `Fifo`

Pointer to the [ADDRESS_FIFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_address_fifo) structure that contains the FIFO element just completed. Only used if the driver submitted an ADDRESS_FIFO list in the original REQUEST_ALLOCATE_ADDRESS_RANGE request.

### `RequestPacket`

If non-**NULL**, **RequestPacket** points to the original request packet. The bus driver only supplies this if the device driver did not supply an MDL or an ADDRESS_FIFO list in the original REQUEST_ALLOCATE_ADDRESS_RANGE request.

### `ResponseMdl`

If non-**NULL**, **ResponseMdl** points to an uninitialized MDL. The driver must initialize this MDL for a nonpageable buffer, and fill the buffer with the response packet. The bus driver only supplies this if the device driver did not supply an MDL or an ADDRESS_FIFO list in the original REQUEST_ALLOCATE_ADDRESS_RANGE request.

### `ResponsePacket`

If non-**NULL**, **ResponsePacket** points to a memory location that the driver fills in with a pointer to the data (quadlet or block) to be returned in the response packet. The bus driver only supplies this if the device driver did not supply an MDL or an ADDRESS_FIFO list in the original REQUEST_ALLOCATE_ADDRESS_RANGE request.

### `ResponseLength`

If non-**NULL**, **ResponseLength** points to a memory location that the driver fills in with the length of its response packet. The bus driver only supplies this if the device driver did not supply an MDL or an ADDRESS_FIFO list in the original REQUEST_ALLOCATE_ADDRESS_RANGE request.

### `ResponseEvent`

If non-**NULL**, **ResponseEvent** points to a memory location that the driver fills in with the kernel event the bus driver should use to signal that it has completed sending the response packet. The bus driver only supplies this if the device driver did not supply an MDL or an ADDRESS_FIFO list in the original REQUEST_ALLOCATE_ADDRESS_RANGE request.

## Remarks

When a driver allocates an address range on the computer's IEEE 1394 address space, it may require that the bus driver notify it for some or all request packets sent to the allocated addresses. As part of the original allocate request, the driver may either require that the bus driver forward each packet for handling, or it may require that the bus driver handle the packet and notify the device driver when it has finished. For more information, see [REQUEST_ALLOCATE_ADDRESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class).

If the device driver provides no backing store, the bus driver forwards each packet to the device driver for handling. The bus driver passes **NULL** for **Mdl**, and passes the packet in **RequestPacket**. The bus driver also passes pointers to memory locations that the device driver must fill in with the buffer for the response packet (in **ResponsePacket**), the buffer length (in **ResponseLength**), and an MDL for the buffer (in **ResponseMdl**). The bus driver also supplies a memory location that the driver can use to pass a kernel event object in **ResponseEvent**. If the device driver provides an event object, the bus driver uses it to signal the driver when it has finished sending the response packet.

If the driver provides the backing store in the original allocate address range request, the bus driver uses the driver's notification routine to signal that it has completed reading or writing data from the backing store. It passes the MDL of the backing store in the **Mdl** member, and the starting location and size within the associated buffer in **ulOffset** and **nLength**. The bus driver also passes the type of event that led to notification in **fulNotificationOptions**.

If the device driver is using a linked list of ADDRESS_FIFO's as the backing store, the bus driver returns the list element it popped off in **Fifo**.

## See also

[REQUEST_ALLOCATE_ADDRESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)