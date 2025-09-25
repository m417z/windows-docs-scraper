# NdisMRegisterIoPortRange function

## Description

**NdisMRegisterIoPortRange** sets up driver access to device I/O ports with the
**NdisRawReadPort*Xxx*** and
**NdisRawWritePort*Xxx*** functions and claims the range of I/O port addresses in the registry for that driver's
NIC.

## Parameters

### `PortOffset` [out]

Specifies a caller-supplied variable in which this function returns the mapped base virtual
address for the given bus-relative I/O port range specified by
*InitialPort* and
*NumberOfPorts* .

### `MiniportAdapterHandle` [in]

Specifies the handle input to
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize).

### `InitialPort` [in]

Specifies the bus-relative base port address for a range of ports to be mapped.

### `NumberOfPorts` [in]

Specifies the number of ports in the range to be mapped.

## Return value

**NdisMRegisterIoPortRange** can return one of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The given range of I/O ports was mapped successfully so the value at *PortOffset* is valid and the mapped range has been claimed in the registry for the NIC. |
| **NDIS_STATUS_RESOURCE_CONFLICT** | An attempt to claim the I/O port range in the registry has failed, possibly because another driver already claimed the range for its device. **NdisMRegisterIoPortRange** logs an error if this occurs. |
| **NDIS_STATUS_RESOURCES** | The port range could not be mapped or NDIS could not allocate resources to check the registry for hardware-resource conflicts. |
| **NDIS_STATUS_FAILURE** | Either the bus type or bus number is out of range or the given *InitialPort* and *NumberOfPorts* were invalid (possibly not within the I/O port space of the current platform). |

## Remarks

A miniport driver calls
**NdisMRegisterIoPortRange** from its
*MiniportInitializeEx* function.
*MiniportInitializeEx* must call
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) before calling
**NdisMRegisterIoPortRange**.

**NdisMRegisterIoPortRange** maps a bus-relative device address range that the miniport driver can use
subsequently to access an I/O port range on a NIC by calling the
**NdisRaw*Xxx*** functions. A successful call claims the specified range of I/O ports in the registry for the
caller's NIC.

Because the parameters passed to the
**NdisRaw*Xxx*** have been mapped, these functions run significantly faster than the corresponding
**NdisImmediate..Port*Xxx***. After a successful call to
**NdisMRegisterIoPortRange**, a miniport driver cannot call any of the
**NdisImmediate..Port*Xxx*** functions with either bus-relative addresses or mapped virtual addresses within such an I/O
port range.

If its call to
**NdisMRegisterIoPortRange** fails,
*MiniportInitializeEx* should release all resources it already allocated for a NIC and, then, fail
initialization for that NIC.

Drivers of NICs with device registers in the host memory space call
**NdisMMapIoSpace** and, subsequently, the
**NdisRead/WriteRegister*Xxx*** functions to access the NIC registers.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisMDeregisterIoPortRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismderegisterioportrange)

[NdisMMapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismmapiospace)

[NdisRawReadPortBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawreadportbufferuchar)

[NdisRawReadPortBufferUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawreadportbufferulong)

[NdisRawReadPortBufferUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawreadportbufferushort)

[NdisRawReadPortUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawreadportuchar)

[NdisRawReadPortUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawreadportulong)

[NdisRawReadPortUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawreadportushort)

[NdisRawWritePortBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawwriteportbufferuchar)

[NdisRawWritePortBufferUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawwriteportbufferulong)

[NdisRawWritePortBufferUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawwriteportbufferushort)

[NdisRawWritePortUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawwriteportuchar)

[NdisRawWritePortUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawwriteportulong)

[NdisRawWritePortUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawwriteportushort)

[NdisReadRegisterUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadregisteruchar)

[NdisReadRegisterUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadregisterulong)

[NdisReadRegisterUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadregisterushort)

[NdisWriteRegisterUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteregisteruchar)

[NdisWriteRegisterUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteregisterulong)

[NdisWriteRegisterUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteregisterushort)