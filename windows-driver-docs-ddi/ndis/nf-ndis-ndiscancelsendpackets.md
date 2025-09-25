# NdisCancelSendPackets function

## Description

**Note** NDIS 5. *x* has been deprecated and is superseded by NDIS 6. *x*. For new NDIS driver development, see [Network Drivers Starting with Windows Vista](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/). For information about porting NDIS 5. *x* drivers to NDIS 6. *x*, see [Porting NDIS 5.x Drivers to NDIS 6.0](https://msdn.microsoft.com/library/Ff570059).

**NdisCancelSendPackets** cancels transmission of all packets marked with the specified cancellation identifier on the miniport driver identified by the binding handle.

## Parameters

### `NdisBindingHandle` [in]

Specifies the handle returned by [**NdisOpenAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapter) that identifies the NIC or virtual adapter to which the cancellation applies.

### `CancelId` [in]

Pointer to the cancellation identifier. This identifier specifies the packet or group of packets for which transmission is being canceled.

## Remarks

Transport protocols map IRPs received from higher-level software to NDIS packets, which the protocols then send to lower-level drivers for transmission. If an IRP is canceled, a transport protocol can call the **NdisCancelSendPackets** function to cancel the pending transmission of the corresponding NDIS packet.

The **NdisCancelSendPackets** function cancels packet transmissions on a single binding. To cancel packet transmissions on more than one binding, a protocol or intermediate driver must call the **NdisCancelSendPackets** function once for each binding.

The protocol or intermediate driver must ensure that *NdisBindingHandle*, which represents the driver's binding to the adapter, remains valid for the duration of the call to **NdisCancelSendPackets**. That is, the protocol or intermediate driver must not call the [**NdisCloseAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscloseadapter)
function to close the binding before **NdisCancelSendPackets** returns.

There is no guarantee that calling **NdisCancelSendPackets** will cancel the pending transmission of all packets with the specified cancellation ID. For example, if the next-lower driver to which the protocol or intermediate driver is bound does not provide a [**MiniportCancelSendPackets**](https://msdn.microsoft.com/library/ff549359/(v=vs.85/)) function, a call to **NdisCancelSendPackets** does nothing.

In all cases, packets submitted for transmission are returned to the originating protocol or intermediate driver through a call to the driver's [**ProtocolSendComplete**](https://msdn.microsoft.com/library/ff563256/(v=vs.85/)) or [**ProtocolCoSendComplete**](https://msdn.microsoft.com/library/ff563230/(v=vs.85/)) function. Canceled send packets are returned with a completion status of NDIS\_STATUS\_ABORTED. The delay between calling **NdisCancelSendPackets** and the return of the canceled packets can vary and therefore cannot be exactly specified.

- Target platform: [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356)
- Version: Not supported for NDIS 6.0 drivers in Windows Vista. Use NdisCancelSendNetBufferLists instead. Supported for NDIS 5.1 drivers in Windows Vista and Windows XP.

## See also

- [**MiniportCancelSendPackets**](https://msdn.microsoft.com/library/ff549359/(v=vs.85/))
- [**NdisGeneratePartialCancelId**](https://msdn.microsoft.com/library/Ff562623)
- [**NDIS\_GET\_PACKET\_CANCEL\_ID**](https://msdn.microsoft.com/library/ff556988/(v=vs.85/))
- [**NDIS\_SET\_PACKET\_CANCEL\_ID**](https://msdn.microsoft.com/library/ff557195/(v=vs.85/))