# _NDIS_PORT_STATE structure

## Description

The NDIS_PORT_STATE structure specifies the port state information for an NDIS port.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_PORT_STATE structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_ DEFAULT, the
**Revision** member to NDIS_PORT_STATE_REVISION_1, and the
**Size** member to NDIS_SIZEOF_PORT_STATE_REVISION_1.

### `MediaConnectState`

The media connection state of the port. This state is the same information that the
[OID_GEN_MEDIA_CONNECT_STATUS_EX](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-media-connect-status-ex) OID returns.

### `XmitLinkSpeed`

The transmit link speed of the port, in bits per second. A value of -1 in this member indicates
that the transmit link speed is unknown.

### `RcvLinkSpeed`

The receive link speed of the port, in bits per second. A value of -1 in this member indicates
that the receive link speed is unknown.

### `Direction`

A
[NET_IF_DIRECTION_TYPE](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_direction_type) NDIS network
interface direction type.

### `SendControlState`

The current control state of the port for send operations. This member must contain one of the
following values:

#### NdisPortControlStateUnknown

The port's control state for send operations is unknown.

#### NdisPortControlStateControlled

The port is in a controlled state for send operations. That is, the port requires
authorization.

#### NdisPortControlStateUncontrolled

The port is in an uncontrolled state for send operations. That is, the port does not require
authorization.

### `RcvControlState`

The current control state of the port for receive operations. This member must contain one of the
following values:

#### NdisPortControlStateUnknown

The port's control state for receive operations is unknown.

#### NdisPortControlStateControlled

The port is in a controlled state for receive operations. That is, the port requires
authorization.

#### NdisPortControlStateUncontrolled

The port is in an uncontrolled state for receive operations. That is, the port does not require
authorization.

### `SendAuthorizationState`

The current authorization state of the port for send operations. Ignore this member if the
**SendControlState** member is set to
**NdisPortControlStateUncontrolled**.

**SendAuthorizationState** must contain one of the following values:

#### NdisPortAuthorizationUnknown

The port's authorization state for send operations is unknown.

#### NdisPortAuthorized

The port is authorized for send operations.

#### NdisPortUnauthorized

The port is not authorized for send operations.

#### NdisPortReauthorizing

The port is re-authorizing for send operations.

### `RcvAuthorizationState`

The current authorization state of the port for receive operations. Ignore this member if the
**RcvControlState** member is set to
**NdisPortControlStateUncontrolled**.

**RcvAuthorizationState** must contain one of the following values:

#### NdisPortAuthorizationUnknown

The port's authorization state for receive operations is unknown.

#### NdisPortAuthorized

The port is authorized for receive operations.

#### NdisPortUnauthorized

The port is not authorized for receive operations.

#### NdisPortReauthorizing

The port is re-authorizing for receive operations.

### `Flags`

Reserved for NDIS.

## Remarks

The NDIS_PORT_STATE structure is used in the
[NDIS_STATUS_PORT_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-port-state) status
indication to indicate a change in the state of a port and is used in response to an
[OID_GEN_PORT_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-port-state) OID query.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_STATUS_PORT_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-port-state)

[NET_IF_DIRECTION_TYPE](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_direction_type)

[OID_GEN_MEDIA_CONNECT_STATUS_EX](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-media-connect-status-ex)

[OID_GEN_PORT_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-port-state)