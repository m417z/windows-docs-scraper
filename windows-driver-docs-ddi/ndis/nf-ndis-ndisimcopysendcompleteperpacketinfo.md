# NdisIMCopySendCompletePerPacketInfo function

## Description

**Note** NDIS 5. *x* has been deprecated and is superseded by NDIS 6. *x*. For new NDIS driver development, see [Network Drivers Starting with Windows Vista](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/). For information about porting NDIS 5. *x* drivers to NDIS 6. *x*, see [Porting NDIS 5.x Drivers to NDIS 6.0](https://msdn.microsoft.com/library/Ff570059).

**NdisIMCopySendCompletePerPacketInfo** copies per-packet information from a packet returned up by a lower miniport driver into a new packet that is to be returned to an upper-level driver.

## Parameters

### `DstPacket` [out]

Pointer to the destination packet descriptor in which per-packet information is to be copied.

### `SrcPacket` [in]

Pointer to the source packet descriptor from which per-packet information is copied.

## Remarks

When an intermediate driver handles the completion of a send request from a lower miniport driver, that intermediate driver calls **NdisIMCopySendCompletePerPacketInfo** to copy per-packet information. The intermediate driver copies the per-packet information from a packet that was returned by the lower miniport driver into a new packet that the intermediate driver returns to an upper-level driver. The intermediate driver calls **NdisIMCopySendCompletePerPacketInfo** for each packet returned through the stack unless the intermediate driver must modify a packet's per-packet information.

Per-packet information is contained in an [**NDIS\_PACKET\_EXTENSION**](https://msdn.microsoft.com/library/ff557093/(v=vs.85/)) structure and includes, for example, checksum information, Internet Protocol security information, and 802.1p priority information.

If an intermediate driver must modify a packet's per-packet information, that intermediate driver should use the [**NDIS\_PER\_PACKET\_INFO\_FROM\_PACKET**](https://msdn.microsoft.com/library/ff557126/(v=vs.85/)) macro to accesses the information. The driver can call this macro once for each type of per-packet information that it needs to access.

Drivers can also use the [**NDIS\_PACKET\_EXTENSION\_FROM\_PACKET**](https://msdn.microsoft.com/library/ff557095/(v=vs.85/)) macro, which returns a pointer to the NDIS\_PACKET\_EXTENSION structure. A driver can call this macro if it needs to access more than one type of per-packet information associated with a packet descriptor. After obtaining the pointer to the NDIS\_PACKET\_EXTENSION structure, the driver can use the appropriate array index to obtain a pointer to a particular type of per-packet information.

To copy a range of data from one packet to another, use the [**NdisCopyFromPacketToPacket**](https://msdn.microsoft.com/library/ff551066/(v=vs.85/)) function.

- Target platform: [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356)
- Version: Not supported for NDIS 6.0 drivers in Windows Vista. Supported for NDIS 5.1 drivers in Windows Vista and Windows XP.

## See also

- [**NdisCopyFromPacketToPacket**](https://msdn.microsoft.com/library/ff551066/(v=vs.85/))
- [**NdisIMCopySendPerPacketInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisimcopysendperpacketinfo)
- [**NDIS\_PACKET**](https://msdn.microsoft.com/library/ff557086/(v=vs.85/))
- [**NDIS\_PACKET\_EXTENSION**](https://msdn.microsoft.com/library/ff557093/(v=vs.85/))
- [**NDIS\_PACKET\_EXTENSION\_FROM\_PACKET**](https://msdn.microsoft.com/library/ff557095/(v=vs.85/))
- [**NDIS\_PER\_PACKET\_INFO\_FROM\_PACKET**](https://msdn.microsoft.com/library/ff557126/(v=vs.85/))