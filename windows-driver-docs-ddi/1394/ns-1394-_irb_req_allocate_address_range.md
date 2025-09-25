# _IRB_REQ_ALLOCATE_ADDRESS_RANGE structure

## Description

This structure contains the fields necessary for the 1394 stack to carry out a request to allocate an address range.

If the allocation is specified with no notification options and no **RequiredOffset**, the returned address will always be a physical address on the OHCI bus. As a result, during allocation, if **Callback** and **Context** are specified, because no notification is used, the callback will be used to notify the caller that the allocation is complete. This way, the issuer of the alloc does not have to block, but instead, the issuer's callback routine is called asynchronously when this is complete.

The caller must create this IRB as usual, but instead use the physical mapping routine provided by the port driver in order to use this request. If it uses **IoCallDriver**, the caller cannot specify **Context** and **Callback** for a physical address, and it has to block.

## Members

### `Mdl`

If non-**NULL**, points to the MDL that describes the application's buffer where asynchronous operations are to be read, written, or locked. The memory for the MDL must be allocated from nonpaged pool or locked down by means of a call to [MmProbeAndLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages). If the driver specifies **u.AllocateAddressRange.Mdl**, then **u.AllocateAddressRange.FifoSListHead** and **u.AllocateAddressRange.FifoSpinLock** must be **NULL**.

### `fulFlags`

Specifies whether the array entries in p1394AddressRange use big-endian byte order. If the caller specifies BIG_ENDIAN_ADDRESS_RANGE, the array entries are in big-endian byte order (the native byte order of the IEEE 1394 protocol), even if the local host is a little-endian machine. In order to specify a little-endian address range, the caller must explicitly guarantee that the BIG_ENDIAN_ADDRESS_RANGE flag is not set using a statement similar to the following:

fulFlags = fulFlags & ~(0x0ffffffff & BIG_ENDIAN_ADDRESS_RANGE)

### `nLength`

Specifies the number of the IEEE 1394 addresses to allocate.

### `MaxSegmentSize`

Specifies the maximum size for each range of addresses that the bus driver allocates. Use zero to indicate that the driver does not have a required maximum segment size. If a nonzero value is specified for **MaxSegmentSize**, the value must be less than 64 KB (65,536 bytes). In other words, it must be less than or equal to 65,535 (0xFFFF) due to the fact that the address range size is stored in a 16-bit word. This member is ignored if **u.AllocateAddressRange.Required1394Offset** is non-**NULL**.

### `fulAccessType`

Specifies access type using one or more of the following flags.

| Access | Description |
| --- | --- |
| ACCESS_FLAGS_TYPE_READ | Allocated addresses can be read. |
| ACCESS_FLAGS_TYPE_WRITE | Allocated addresses can be written to. |
| ACCESS_FLAGS_TYPE_LOCK | Allocated addresses can be the target of a lock operation. |
| ACCESS_FLAGS_TYPE_BROADCAST | Allocated addresses can receive asynchronous I/O requests from any node on the bus. (By default, only the device driver's device can send requests to the allocated addresses). |

Special considerations apply to drivers of virtual devices. Virtual devices do not have node IDs, and so when a driver sends a request to a virtual device, the bus driver has no means of identifying which device is the target. Thus in order for a virtual device to receive requests, its driver must allocate a range of addresses with the ACCESS_FLAGS_TYPE_BROADCAST flag set in **fulAccessType**. This permits the virtual device to receive all request packets, no matter what node ID is indicated in the request packet.

### `fulNotificationOptions`

If the device driver requests that the bus driver handle each request, and notifies the device driver upon completion, this specifies which asynchronous I/O request types will trigger the bus driver to the notify the device driver upon completion. See the **Operation** section for more details. The driver may specify one or more of the NOTIFY_FLAGS_AFTER_XXX flags.

| Flag | Description |
| --- | --- |
| NOTIFY_FLAGS_NEVER | No notification. |
| NOTIFY_FLAGS_AFTER_READ | Notify the device driver after carrying out an asynchronous read operation. |
| NOTIFY_FLAGS_AFTER_WRITE | Notify the device driver after carrying out an asynchronous write operation. |
| NOTIFY_FLAGS_AFTER_LOCK | Notify the device driver after carrying out an asynchronous lock operation. |

### `Callback`

Points to a device driver callback routine. If the device driver specifies that the bus driver notify the device driver for each asynchronous I/O request, **u.AllocateAddressRange.Callback** points to the device driver's notification routine, which must have the following prototype:

```
VOID DriverNotificationRoutine(IN PNOTIFICATION_INFO );
```

If the device driver specifies that it receives no notification, and submits this request at raised IRQL through the port driver's physical mapping routine, then **u.AllocateAddressRange.Callback** points to the device driver's allocation completion routine, which must have the following prototype:

```
VOID AllocationCompletionRoutine( IN PVOID );
```

Drivers that do not request notification, and submit this request in the normal way at PASSIVE_LEVEL, must set this member to **NULL**.

### `Context`

Points to any context data that the device driver wants to pass for this set of addresses. If the provided callback (see previous) is a notification routine, the bus driver passes **u.AllocateAddressRange.Context** within the NOTIFICATION_INFO the parameter. If the callback is an allocation completion routine, the bus driver passes **u.AllocateAddressRange.Context** as the sole parameter to the routine

### `Required1394Offset`

Specifies a hard-coded address in the computer's IEEE 1394 address space. The bus driver allocates the addresses beginning at **u.AllocateAddressRange.Required1394Offset**. If no specific address is required, the driver should fill in each member of the ADDRESS_OFFSET with zero. The bus driver then chooses the addresses to allocate.

### `FifoSListHead`

If non-**NULL**, specifies a properly initialized (for example, by **ExInitializeSListHead**) interlocked, singly-linked list of ADDRESS_FIFO elements. Each ADDRESS_FIFO contains an MDL. As the bus driver handles each incoming write request to the allocated addresses, it pops off the first element on the list and writes incoming data to the MDL. It then calls the driver's notification routine.

Each MDL provided must only span one page in memory. The driver can add or remove elements from the ADDRESS_FIFO list by using **ExInterlockedPushEntrySList** and **ExInterlockedPopEntrySList**.

If this member is non-**NULL**, the **Mdl** member of **u.AllocateAddress** range must be **NULL**, the **fulNotificationOptions** member must be NOTIFY_FLAGS_AFTER_WRITE (no other flags must be specified), and the driver must provide a spin lock in **FifoSpinLock**. This implies that the order in which packets are filled and returned is guaranteed to be based on a FIFO algorithm. In fact, this SLIST-based mechanism acts more like a stack, or Last-In-First-Out (LIFO).

### `FifoSpinLock`

If non-**NULL**, specifies a properly initialized spin lock (for example, by **KeInitializeSpinLock**). The spin lock is used to serialize access to the SList provided in **u.AllocateAddressRange.FifoSListHead**.

The **u.AllocateAddressRange.FifoSpinLock** member is non-**NULL** if and only if **u.AllocateAddressRange.FifoSListHead** is non-**NULL** as well.

### `AddressesReturned`

Number of addresses returned.

### `p1394AddressRange`

Points to an array of ADDRESS_RANGE structures. The array must be large enough to hold the maximum number of structures the bus driver can return.

If the driver specifies a required address offset, or if the driver does not provide any backing store, the bus driver only returns one address range. If the driver provides backing store in **u.AllocateAddressRange.Mdl** the bus driver segments the allocated addresses along physical memory boundaries. If the **MaxSegmentSize** of **u.AllocateAddressRange** is 0, or if **MaxSegmentSize** is bigger than the page size, the driver can use the [ADDRESS_AND_SIZE_TO_SPAN_PAGES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-address_and_size_to_span_pages) macro to determine the worst case. Otherwise, the maximum number of addresses ranges returned by the bus driver is **u.AllocateAddressRange.nLength** / **u.MaxSegmentSize**. If a nonzero value is specified for **MaxSegmentSize**, the value must be less than 64 KB (65,536 bytes). In other words, it must be less than or equal to 65,535 (0xFFFF) due to the fact that the address range size is stored in a 16-bit word.

### `hAddressRange`

Handle to the address range.

### `DeviceExtension`

Points to the device extension associated with the device object. Not setting this member can lead to unexpected behavior when the driver tries to access the allocated address space.