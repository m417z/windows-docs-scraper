# NdisMDeregisterIoPortRange function

## Description

**NdisMDeregisterIoPortRange** releases a mapping that was set up with
[NdisMRegisterIoPortRange](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndismregisterioportrange) during
driver initialization.

## Parameters

### `MiniportAdapterHandle` [in]

Specifies the handle input to
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize).

### `InitialPort` [in]

Specifies the bus-relative address of the first port in the range of ports.

### `NumberOfPorts` [in]

Specifies the number of ports in the range.

### `PortOffset` [in]

Specifies the mapped base port address returned by
**NdisMRegisterIoPortRange**.

## Remarks

The miniport driver must pass the same
*InitialPort* and
*NumberOfPorts* to
**NdisMDeregisterIoPortRange** that were passed when
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) called
[NdisMRegisterIoPortRange](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndismregisterioportrange) to get
the mapped
*PortOffset* value. That is, a miniport driver cannot call
**NdisMDeregisterIoPortRange** to release a subrange of a mapped port range.

**NdisMDeregisterIoPortRange** can be called from the
*MiniportInitializeEx* or
[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) functions only if
*MiniportInitializeEx* previously made a successful call to
**NdisMRegisterIoPortRange**.

**NdisMDeregisterIoPortRange** also releases the driver's claim on the I/O port range in the
registry.

After it calls
**NdisMRegisterIoPortRange**, the miniport driver can no longer access the NIC's port range with calls
to the
**NdisRaw..Port*Xxx*** functions.

## See also

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisMRegisterIoPortRange](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndismregisterioportrange)