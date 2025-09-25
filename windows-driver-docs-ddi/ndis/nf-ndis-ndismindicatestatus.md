# NdisMIndicateStatus function

## Description

**Note** NDIS 5. *x* has been deprecated and is superseded by NDIS 6. *x*. For new NDIS driver development, see [Network Drivers Starting with Windows Vista](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/). For information about porting NDIS 5. *x* drivers to NDIS 6. *x*, see [Porting NDIS 5.x Drivers to NDIS 6.0](https://msdn.microsoft.com/library/Ff570059).

**NdisMIndicateStatus** indicates changes in the status of a NIC to higher-level NDIS drivers.

## Parameters

### `MiniportHandle` [in]

Specifies the handle originally input to [**MiniportInitialize**](https://msdn.microsoft.com/library/ff550472/(v=vs.85/)).

### `GeneralStatus` [in]

Specifies the NDIS\_STATUS\_ *XXX* value that indicates the general change in status for the NIC.

### `StatusBuffer` [in]

Pointer to a caller-allocated buffer containing data that is medium-specific and dependent on the value of *GeneralStatus*. It indicates detailed information about the change in status.

### `StatusBufferSize` [in]

Specifies the size in bytes of the buffer at *StatusBuffer*.

## Remarks

When a miniport driver calls **NdisMIndicateStatus**, NDIS calls each bound protocol's [**ProtocolStatus**](https://msdn.microsoft.com/library/ff563257/(v=vs.85/)) function. This allows a bound protocol driver or, possibly, the configuration manager to log the change in status of an underlying NIC or to take corrective action. For example, a protocol might call [**NdisReset**](https://msdn.microsoft.com/library/ff554691/(v=vs.85/)), depending on the NDIS\_STATUS\_ *XXX* indicated.

When a miniport driver calls **NdisMIndicateStatus** to report a change in NIC status, NDIS can call the [*MiniportReset*](https://msdn.microsoft.com/library/ff550502/(v=vs.85/)) function to try restoring the NIC to a working condition. In these circumstances, NDIS can call bound protocols only with NDIS\_STATUS\_RESET\_START and later with NDIS\_STATUS\_RESET\_END, rather than with the *GeneralStatus* indicated by the miniport driver.

**NdisMIndicateStatus** provides two pieces of information:

- An overall status value indicating the general change in status.
- A specific reason for the general change, which can be network-specific. For example, ring-insertion failures are particular to Token Ring (802.5) networks, but are irrelevant to Ethernet (802.3) NICs and their drivers.

A miniport driver also can call **NdisMIndicateStatus** to indicate problems such as cables that have been accidentally removed and then reinserted or a ring that has temporarily failed. For example, suppose both the following conditions occur:

- The miniport driver calls **NdisMIndicateStatus** with NDIS\_STATUS\_RING\_STATUS.
- The *StatusBuffer* contains one of the following status values:

  - NDIS\_RING\_LOBE\_WIRE\_FAULT
  - NDIS\_RING\_HARD\_ERROR
NDIS\_RING\_SIGNAL\_LOSS

After such a change in status has been signaled with an indication, any associated thresholds or statistics counters remain unchanged.

A miniport driver cannot call **NdisMIndicateStatus** in the context of its [**MiniportISR**](https://msdn.microsoft.com/library/ff550478/(v=vs.85/)), [**MiniportHalt**](https://msdn.microsoft.com/library/ff549451/(v=vs.85/)), or [**MiniportShutdown**](https://msdn.microsoft.com/library/ff550533/(v=vs.85/)) function. Only a deserialized miniport driver can call **NdisMIndicateStatus** in the context of its [**MiniportInitialize**](https://msdn.microsoft.com/library/ff550472/(v=vs.85/)) function.

A miniport driver must release any spin lock that it is holding before calling **NdisMIndicateStatus**.

Serialized callers of **NdisMIndicateStatus** must run at IRQL = DISPATCH\_LEVEL. Deserialized callers of **NdisMIndicateStatus** must run at IRQL \<= DISPATCH\_LEVEL.

**Indicating the Loss and Restoration of a Network Connection**

When a miniport driver senses that the network connection has been lost, it should call **NdisMIndicateStatus** with NDIS\_STATUS\_MEDIA\_DISCONNECT. When the connection is restored, the miniport driver should call **NdisMIndicateStatus** with NDIS\_STATUS\_MEDIA\_CONNECT.

**Note** 802.11 miniport drivers must follow the media status guidelines for wireless LANs when generating network connection indications. For more information about these guidelines, see [Media Status Indications for 802.11 Networks](https://msdn.microsoft.com/library/ff549301/(v=vs.85/)).

**802.11 Wireless LAN Miniport Driver Calls to NdisMIndicateStatus**

802.11 wireless LAN (WLAN) miniport drivers can make various indications specific to the WLAN media. For example, the miniport driver can make a WLAN-specific indication when the following occur:

- The driver detects that the received signal strength of its current BSS association has changed.
- The driver detects a TKIP MIC failure on a received packet.

The following types of WLAN-specific indications can be made by 802.11 miniport drivers with **NdisMIndicateStatus**:

- [RSSI Indications](https://msdn.microsoft.com/library/ff564096/(v=vs.85/))
- [Authentication Indications](https://msdn.microsoft.com/library/ff544134/(v=vs.85/))
- [PMKID Candidate List Indications](https://msdn.microsoft.com/library/ff562383/(v=vs.85/))
- [Media Streaming Indications](https://msdn.microsoft.com/library/ff549317/(v=vs.85/))
- [Radio State Indications](https://msdn.microsoft.com/library/ff563284/(v=vs.85/))

For more information about these media specific indications, see [802.11 Media-Specific Status Indications](https://msdn.microsoft.com/library/ff543911/(v=vs.85/)).

**WAN Miniport Driver Calls to NdisMIndicateStatus**

Most WAN NIC drivers indicate status with some special status codes and buffer contents. These status indications are generated by WAN NIC drivers, and NDIS protocol drivers bound to such a miniport driver can ignore these indications. However, processing these indications correctly usually results in improved performance for protocols and for WAN NIC drivers.

The following four types of WAN-specific indications can be sent to bound protocol drivers with **NdisMIndicateStatus**:

- Line up
- Line down
- Fragment
- TAPI line event

**NDIS\_STATUS\_WAN\_LINE\_UP**

A WAN miniport driver makes a line-up indication whenever a new link becomes active. Until this occurs, the NIC will accept frames and let them succeed or fail, but it is unlikely that they will actually be received by any remote node. Until this occurs, protocols should reduce their timers and retry counts to quickly fail any outgoing connection attempts.

The WAN miniport driver makes this indication with **NdisMIndicateStatus** before it returns from the [OID\_TAPI\_GET\_ID](https://msdn.microsoft.com/library/ff561166/(v=vs.85/)) request.

The status code for the line-up indication is NDIS\_STATUS\_WAN\_LINE\_UP. The buffer at *StatusBuffer* is formatted as an [**NDIS\_MAC\_LINE\_UP**](https://msdn.microsoft.com/library/ff557058/(v=vs.85/)) structure.

**NDIS\_STATUS\_WAN\_LINE\_DOWN**

A WAN miniport driver makes a line-down indication whenever a link goes down. When this occurs, bound protocols should reduce their timers and retry counts until the next line-up indication.

The status code for the line-down indication is NDIS\_STATUS\_WAN\_LINE\_DOWN. The buffer at *StatusBuffer* is formatted as an [**NDIS\_MAC\_LINE\_DOWN**](https://msdn.microsoft.com/library/ff557057/(v=vs.85/)) structure.

**NDIS\_STATUS\_WAN\_FRAGMENT**

A WAN miniport driver makes a fragment indication whenever it receives a partial packet from the remote node. When this occurs, a bound protocol should send frames to the remote node that will notify it of this situation, rather than waiting for a time-out to occur.

The status code for the fragment indication is NDIS\_STATUS\_WAN\_FRAGMENT. The buffer at *StatusBuffer* is formatted as an [**NDIS\_MAC\_FRAGMENT**](https://msdn.microsoft.com/library/ff557055/(v=vs.85/)) structure.

NDISWAN monitors dropped packets by counting the number of fragment indications on each link.

**NDIS\_TAPI\_EVENT**

A WAN miniport driver must use a *GeneralStatus* value of NDIS\_STATUS\_TAPI\_INDICATION for TAPI status indications *.* The buffer at *StatusBuffer* is formatted as an NDIS\_TAPI\_EVENT structure.

- Target platform: [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356)
- Version: Not supported for NDIS 6.0 drivers in Windows Vista. Use [**NdisMIndicateStatusEx**](https://msdn.microsoft.com/library/Ff563600)instead. Supported for NDIS 5.1 drivers in Windows Vista and Windows XP.

## See also

- [**MiniportInitialize**](https://msdn.microsoft.com/library/ff550472/(v=vs.85/))
- [*MiniportReset*](https://msdn.microsoft.com/library/ff550502/(v=vs.85/))
- [**NDIS\_MAC\_FRAGMENT**](https://msdn.microsoft.com/library/ff557055/(v=vs.85/))
- [**NDIS\_MAC\_LINE\_DOWN**](https://msdn.microsoft.com/library/ff557057/(v=vs.85/))
- [**NDIS\_MAC\_LINE\_UP**](https://msdn.microsoft.com/library/ff557058/(v=vs.85/))
- [**NdisMIndicateStatusComplete**](https://msdn.microsoft.com/library/ff553540/(v=vs.85/))
- [**NDIS\_TAPI\_EVENT**](https://msdn.microsoft.com/library/ff558986/(v=vs.85/))
- [**ProtocolStatus**](https://msdn.microsoft.com/library/ff563257/(v=vs.85/))
- [Media Status Indications for 802.11 Networks](https://msdn.microsoft.com/library/ff549301/(v=vs.85/))
- [802.11 Media-Specific Status Indications](https://msdn.microsoft.com/library/ff543911/(v=vs.85/))