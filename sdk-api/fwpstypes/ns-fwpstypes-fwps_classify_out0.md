# FWPS_CLASSIFY_OUT0 structure

## Description

The **FWPS_CLASSIFY_OUT0** structure defines the data that is returned to the caller of a callout's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/_netvista/) callout function.

**Note** **FWPS_CLASSIFY_OUT0** is a specific version of **FWPS_CLASSIFY_OUT**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Members

### `actionType`

An **FWP_ACTION_TYPE** value that specifies the suggested action to be taken as determined by the
callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nc-fwpsk-fwps_callout_classify_fn0) callout function. A callout driver
sets this variable to one of the following values:

#### FWP_ACTION_BLOCK

Block the data from being transmitted or received.

#### FWP_ACTION_CONTINUE

Pass the decision to block or permit the data to be transmitted or received to the next filter
in the filter engine.

#### FWP_ACTION_NONE

Perform no action on the data.

#### FWP_ACTION_NONE_NO_MATCH

Perform no action on the data because it does not match the enumerated filter data types.

#### FWP_ACTION_PERMIT

Permit the data to be transmitted or received.

Write access to this member is controlled by the **FWPS_RIGHT_ACTION_WRITE** flag in the
**rights** member. If the **FWPS_RIGHT_ACTION_WRITE** flag is set, a callout driver can write any of the
above values to this member. If the **FWPS_RIGHT_ACTION_WRITE** flag is not set, a callout driver should not
write to this member unless it is vetoing an **FWP_ACTION_PERMIT** action that was previously returned by a
higher weight filter in the filter engine. In such a situation, a callout driver sets this member to
**FWP_ACTION_BLOCK**.

### `outContext`

Reserved for system use. Callout drivers must not use this member.

### `filterId`

Reserved for system use. Callout drivers must not use this member.

### `rights`

Flags that control the write access to the other members within this structure. Possible flags
are:

#### FWPS_RIGHT_ACTION_WRITE

If this flag is set, a callout driver can write to the
**actionType** member of this structure. If this flag is not set, a callout driver can write only to
the
**actionType** member of this structure if it is vetoing an **FWP_ACTION_PERMIT** action that was
previously returned by a higher weight filter in the filter engine.

### `flags`

Flags that affect the action taken on the data. Possible flags are:

#### FWPS_CLASSIFY_OUT_FLAG_ABSORB

The blocked data is to be silently dropped without any event logging or auditing. This is
typically used for packet modification where the original packet is to be absorbed and the modified
packet is to be further processed.

This flag is applicable at the following layers when the
**actionType** member is set to **FWP_ACTION_BLOCK**:

FWPS_LAYER_INBOUND_MAC_FRAME_NATIVE

FWPS_LAYER_OUTBOUND_MAC_FRAME_NATIVE

FWPS_LAYER_INBOUND_MAC_FRAME_ETHERNET

FWPS_LAYER_OUTBOUND_MAC_FRAME_ETHERNET

FWPS_LAYER_INGRESS_VSWITCH_ETHERNET

FWPS_LAYER_EGRESS_VSWITCH_ETHERNET

FWPS_LAYER_INBOUND_IPPACKET_V4

FWPS_LAYER_INBOUND_IPPACKET_V6

FWPS_LAYER_OUTBOUND_IPPACKET_V4

FWPS_LAYER_OUTBOUND_IPPACKET_V6

FWPS_LAYER_INBOUND_TRANSPORT_V4

FWPS_LAYER_INBOUND_TRANSPORT_V6

FWPS_LAYER_OUTBOUND_TRANSPORT_V4

FWPS_LAYER_OUTBOUND_TRANSPORT_V6

FWPS_LAYER_INBOUND_ICMP_ERROR_V4

FWPS_LAYER_INBOUND_ICMP_ERROR_V6

FWPS_LAYER_OUTBOUND_ICMP_ERROR_V4

FWPS_LAYER_OUTBOUND_ICMP_ERROR_V6

FWPS_LAYER_DATAGRAM_DATA_V4

FWPS_LAYER_DATAGRAM_DATA_V6

FWPS_LAYER_STREAM_PACKET_V4

FWPS_LAYER_STREAM_PACKET_V6

FWPS_LAYER_ALE_AUTH_RECV_ACCEPT_V4

FWPS_LAYER_ALE_AUTH_RECV_ACCEPT_V6

FWPS_LAYER_ALE_AUTH_CONNECT_V4

FWPS_LAYER_ALE_AUTH_CONNECT_V6

It is also possible to set this flag at the FWPS_LAYER_ALE_FLOW_ESTABLISHED_V4 and FWPS_LAYER_ALE_FLOW_ESTABLISHED_V6 layers. But doing so is not advised, because these layers are intended for associating context with flows.

If this flag is not set, a blocking action will be subject to normal event logging and
auditing.

#### FWPS_CLASSIFY_OUT_FLAG_BUFFER_LIMIT_REACHED

The filter engine sets this flag when the filter engine's data buffer for stream data is full.
This can occur if a callout's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nc-fwpsk-fwps_callout_classify_fn0) callout function repeatedly
requests more data by setting the
**streamAction** member of the
[FWPS_STREAM_CALLOUT_IO_PACKET0](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/ns-fwpsk-fwps_stream_callout_io_packet0_) structure to **FWPS_STREAM_ACTION_NEED_MORE_DATA** until the buffer
limit is reached. If this flag is set, the callout driver's
*classifyFn* callout function must either
permit or block all of the stream data.

This flag is only applicable at the stream layers.

#### FWPS_CLASSIFY_OUT_FLAG_NO_MORE_DATA

Stream data was requested after the stream had been disconnected.

### `reserved`

Reserved for system use. Callout drivers must not use this member.

## Remarks

The filter engine passes a pointer to an **FWPS_CLASSIFY_OUT0** structure to a callout's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nc-fwpsk-fwps_callout_classify_fn0) callout function. A callout driver
uses this structure to return data to the caller.

## See also

[FWPS_STREAM_CALLOUT_IO_PACKET0](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/ns-fwpsk-fwps_stream_callout_io_packet0_)

[Run-time Filtering Layer Identifiers](https://learn.microsoft.com/windows/desktop/FWP/management-filtering-layer-identifiers-)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nc-fwpsk-fwps_callout_classify_fn0)