# NdisMMapIoSpace function

## Description

**NdisMMapIoSpace** maps a given bus-relative "physical" range of device RAM or registers onto a
system-space virtual range.

## Parameters

### `VirtualAddress` [out]

Pointer to a caller-supplied variable that is set to the converted virtual address if the call is
successful.

### `MiniportAdapterHandle` [in]

Specifies the handle input to
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize).

### `PhysicalAddress` [in]

Specifies the bus-relative base physical address of the device memory range to be mapped.

### `Length` [in]

Specifies the number of bytes to be mapped.

## Return value

**NdisMMapIoSpace** can return any of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The device memory range was mapped successfully so the value at *VirtualAddress* is valid and the mapped range has been claimed in the registry for the NIC. |
| **NDIS_STATUS_RESOURCE_CONFLICT** | An attempt to claim the device memory range in the registry has failed, possibly because another driver has already claimed the range for its device. **NdisMMapIoSpace** logs an error if this occurs. |
| **NDIS_STATUS_RESOURCES** | The memory could not be mapped or sufficient virtual memory could not be allocated. |
| **NDIS_STATUS_FAILURE** | Either the bus type or bus number is out of range or the given *PhysicalAddress* and *Length* were invalid (possibly not within the I/O space of the current platform). |

## Remarks

This function is called by drivers of NICs that have on-board memory or a bank of device registers
appearing in the I/O space of the host. For example, the driver of a NIC that uses PIO calls
**NdisMMapIoSpace**.

A successful call to
**NdisMMapIoSpace** claims hardware resources in the registry for the driver's NIC. Consequently, only
*MiniportInitializeEx* functions call
**NdisMMapIoSpace**.

**NdisMMapIoSpace** sets the variable at
*VirtualAddress* to **NULL** if it does not return NDIS_STATUS_SUCCESS.

MiniportInitializeEx either gets the
*PhysicalAddress* value from the driver's
**Parameters** registry key or by calling a bus-type-specific
**Ndis*Xxx*** configuration function. The given physical address range must fall within the I/O space of the
current platform. It is a programming error to call
**NdisMMapIoSpace** with a host physical memory address.

A miniport driver must call the reciprocal
**NdisMUnmapIoSpace** to release its claim on system resources if
*MiniportInitializeEx* subsequently fails to initialize a NIC, if a NIC is removed from the machine,
and/or when the driver is unloading.

## See also

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisMGetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismgetbusdata)

[NdisMUnmapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismunmapiospace)

[NdisOpenConfigurationEx](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndisopenconfigurationex)

[NdisReadRegisterUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadregisteruchar)

[NdisReadRegisterUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadregisterulong)

[NdisReadRegisterUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadregisterushort)

[NdisWriteRegisterUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteregisteruchar)

[NdisWriteRegisterUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteregisterulong)

[NdisWriteRegisterUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteregisterushort)