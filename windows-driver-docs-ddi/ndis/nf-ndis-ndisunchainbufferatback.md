# NdisUnchainBufferAtBack function

## Description

**Note** NDIS 5. *x* has been deprecated and is superseded by NDIS 6. *x*. For new NDIS driver development, see [Network Drivers Starting with Windows Vista](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/). For information about porting NDIS 5. *x* drivers to NDIS 6. *x*, see [Porting NDIS 5.x Drivers to NDIS 6.0](https://msdn.microsoft.com/library/Ff570059).

**NdisUnchainBufferAtBack** removes the buffer descriptor at the end of the chain of buffer descriptors for a given packet.

## Parameters

### `Packet` [in, out]

Pointer to the packet descriptor.

### `Buffer` [out]

Pointer to a caller-supplied variable in which this function returns a pointer to the removed buffer descriptor. If no buffer is chained to the given packet, this variable is set to **NULL**.

## Remarks

- Target platform: [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356)
- Version: Not supported for NDIS 6.0 drivers in Windows Vista. Supported for NDIS 5.1 drivers in Windows Vista and Windows XP.

## See also

- [**NdisChainBufferAtBack**](https://msdn.microsoft.com/library/ff550830/(v=vs.85/))
- [**NdisQueryPacket**](https://msdn.microsoft.com/library/ff554428/(v=vs.85/))
- [**NdisUnchainBufferAtFront**](https://msdn.microsoft.com/library/ff554826/(v=vs.85/))