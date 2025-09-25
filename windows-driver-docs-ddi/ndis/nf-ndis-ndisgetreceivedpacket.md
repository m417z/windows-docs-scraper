# NdisGetReceivedPacket function

## Description

**Note** NDIS 5. *x* has been deprecated and is superseded by NDIS 6. *x*. For new NDIS driver development, see [Network Drivers Starting with Windows Vista](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/). For information about porting NDIS 5. *x* drivers to NDIS 6. *x*, see [Porting NDIS 5.x Drivers to NDIS 6.0](https://msdn.microsoft.com/library/Ff570059).

**NdisGetReceivedPacket** retrieves a packet that was received from the underlying driver.

## Parameters

### `NdisBindingHandle` [in]

Specifies the handle that was returned by [**NdisOpenAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapter) that identifies the target NIC or the virtual adapter of the underlying driver to which the calling driver is bound.

### `MacContext` [in]

Specifies a context handle that the underlying driver associates with the packet received from the network. This handle was passed as an input parameter to the calling driver's [**ProtocolReceive**](https://msdn.microsoft.com/library/ff563246/(v=vs.85/)) function. This handle is opaque to the calling driver and reserved for use by the underlying driver that made the indication.

## Return value

Returns a pointer to a packet descriptor that contains data that was received on the underlying driver.

## Remarks

Several protocol or intermediate drivers can be bound to a single underlying NIC, and each such driver can receive an indication for the same packet. Such a packet is read-only to these drivers. Each such driver's *ProtocolReceive* function determines whether to call **NdisGetReceivedPacket** to retrieve the indicated packet.

- Target platform: [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356)
- Version: Not supported for NDIS 6.0 drivers in Windows Vista. Supported for NDIS 5.1 drivers in Windows Vista and Windows XP.

## See also

- [**NdisOpenAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapter)