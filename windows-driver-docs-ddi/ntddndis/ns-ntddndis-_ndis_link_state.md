# _NDIS_LINK_STATE structure

## Description

The **NDIS_LINK_STATE** structure specifies the current link state of a miniport adapter.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
**NDIS_LINK_STATE** structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT, the
**Revision** member to NDIS_LINK_STATE_REVISION_1, and the
**Size** member to NDIS_SIZEOF_LINK_STATE_REVISION_1.

### `MediaConnectState`

The media connect state for the miniport adapter. For more information, see
[OID_GEN_MEDIA_CONNECT_STATUS_EX](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-media-connect-status-ex) OID.

### `MediaDuplexState`

The media duplex state for the miniport adapter. For more information, see [OID_GEN_MEDIA_DUPLEX_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-media-duplex-state) OID.

### `XmitLinkSpeed`

The current transmit link speed of the miniport adapter in bits per second. For more information, see [OID_GEN_LINK_SPEED_EX](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-link-speed-ex).

**Note** A value of NDIS_LINK_SPEED_UNKNOWN indicates that the
transmit link speed is unknown.

### `RcvLinkSpeed`

The current receive link speed of the miniport adapter in bits per second. For more information, see [OID_GEN_LINK_SPEED_EX](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-link-speed-ex).

**Note** A value of NDIS_LINK_SPEED_UNKNOWN indicates that the
receive link speed is unknown.

### `PauseFunctions`

The type of support for the IEEE 802.3 pause frames. This member must be one of the following
pause functions:

#### NdisPauseFunctionsUnsupported

the miniport adapter or link partner does not support pause frames.

#### NdisPauseFunctionsSendOnly

the miniport adapter and link partner support only sending pause frames from the miniport adapter to the link
partner.

#### NdisPauseFunctionsReceiveOnly

the miniport adapter and link partner support only sending pause frames from the link partner to the miniport adapter

#### NdisPauseFunctionsSendAndReceive

the miniport adapter and link partner support sending and receiving pause frames in both transmit and
receive directions.

#### NdisPauseFunctionsUnknown

Pause frame negotiation is in progress. The pause frame support that the link partner provides
is unknown.

### `AutoNegotiationFlags`

The auto-negotiation settings for the miniport adapter. This member is created from a bitwise OR
of the following flags:

#### NDIS_LINK_STATE_XMIT_LINK_SPEED_AUTO_NEGOTIATED

the miniport adapter has auto-negotiated the transmit link speed with the link partner.

#### NDIS_LINK_STATE_RCV_LINK_SPEED_AUTO_NEGOTIATED

the miniport adapter has auto-negotiated the receive link speed with the link partner.

#### NDIS_LINK_STATE_DUPLEX_AUTO_NEGOTIATED

the miniport adapter has auto-negotiated the duplex state with the link partner.

#### NDIS_LINK_STATE_PAUSE_FUNCTIONS_AUTO_NEGOTIATED

the miniport adapter has auto-negotiated the pause functions with the link partner.

## Remarks

Miniport drivers use the [NDIS_STATUS_LINK_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-link-state) status indication to notify NDIS and overlying drivers that there has been a change in the physical characteristics of a medium.

When it generates this status indication, the driver sets the
**StatusBuffer** member of the
[NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication) structure to a pointer to an **NDIS_LINK_STATE** structure.

The miniport driver also returns an **NDIS_LINK_STATE** structure when it handles an OID query request of [OID_GEN_LINK_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-link-state).

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication)

[NDIS_STATUS_LINK_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-link-state)

[OID_GEN_LINK_SPEED_EX](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-link-speed-ex)

[OID_GEN_LINK_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-link-state)

[OID_GEN_MEDIA_CONNECT_STATUS_EX](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-media-connect-status-ex)

[OID_GEN_MEDIA_DUPLEX_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-media-duplex-state)