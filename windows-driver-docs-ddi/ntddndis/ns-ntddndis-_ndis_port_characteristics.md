# _NDIS_PORT_CHARACTERISTICS structure

## Description

The **NDIS_PORT_CHARACTERISTICS** structure specifies the characteristics of an NDIS port. For more information about NDIS ports, see [NDIS Ports](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-ndis-ports).

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
**NDIS_PORT_CHARACTERISTICS** structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT, the
**Revision** member to NDIS_PORT_CHARACTERISTICS_REVISION_1, and the
**Size** member to NDIS_SIZEOF_PORT_CHARACTERISTICS_REVISION_1.

### `PortNumber`

The number of the NDIS port that is associated with this **NDIS_PORT_CHARACTERISTICS** structure. The
**PortNumber** value is an NDIS_PORT_NUMBER value, which has a ULONG data type and is valid from zero
through 0xffffff, where zero is reserved for the default port.

### `Flags`

A bitwise OR combination of the port characteristics flags, or zero if no flags are set. There is
currently one flag.

If the NDIS_PORT_CHAR_USE_DEFAULT_AUTH_SETTINGS flag is set, NDIS ignores authentication state
settings and uses the default authentication state instead. A miniport driver can use this flag to
request that NDIS use the default authentication state settings for the ports that it allocates and
activates. If the miniport driver controls the default port, when the miniport driver activates the
default port, the driver can set NDIS_PORT_CHAR_USE_DEFAULT_AUTH_SETTINGS to activate the default port
with the default authentication state settings.

### `Type`

The type of NDIS port. For more information, see [Types of NDIS Ports](https://learn.microsoft.com/windows-hardware/drivers/network/types-of-ndis-ports). This type can be one of the following values:

#### NdisPortTypeUndefined

The default port type.

#### NdisPortTypeBridge

Reserved for system use.

#### NdisPortTypeRasConnection

A Remote Access Service (RAS) connection.

#### NdisPortType8021xSupplicant

A remote wireless station that is associated with an access point on this host computer.

#### NdisPortTypeNdisImPlatform

Reserved for system use.

**Note** This value is supported only in NDIS 6.30 and later.

### `MediaConnectState`

The media connection state of the port. This state is the same information that the
[OID_GEN_MEDIA_CONNECT_STATUS_EX](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-media-connect-status-ex) OID returns.

### `XmitLinkSpeed`

The transmit link speed of the port in bits per second. A value of -1 in this member indicates
that the transmit link speed is unknown.

### `RcvLinkSpeed`

The receive link speed of the port, in bits per second. A value of -1 in this member indicates
that the receive link speed is unknown.

### `Direction`

A
[NET_IF_DIRECTION_TYPE](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_direction_type) NDIS network
interface direction type.

### `SendControlState`

The control state of the port for send operations. This member must contain one of the following
values:

#### NdisPortControlStateUnknown

The port's control state for send operations is unknown.

#### NdisPortControlStateControlled

The port is in a controlled state for send operations. That is, the port requires
authorization.

#### NdisPortControlStateUncontrolled

The port is in an uncontrolled state for send operations. That is, the port does not require
authorization.

### `RcvControlState`

The control state of the port for receive operations. This member must contain one of the
following values:

#### NdisPortControlStateUnknown

The port's control state for receive operations is unknown.

#### NdisPortControlStateControlled

The port is in a controlled state for receive operations (that is, the port requires
authorization), and the value in the
**SendAuthorizationState** member determines the authentication state.

#### NdisPortControlStateUncontrolled

The port is in an uncontrolled state for receive operations. Therefore, authentication does not
apply to this port.

### `SendAuthorizationState`

The authorization state of the port for send operations. Ignore this member if the
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

The authorization state of the port for receive operations. Ignore this member if the
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

## Remarks

The **NDIS_PORT_CHARACTERISTICS** structure specifies the characteristics of an NDIS port. This structure
appears in a list of port characteristics that are provided in the
[NDIS_PORT_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_port_array) structure that is used with
the
[OID_GEN_ENUMERATE_PORTS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-enumerate-ports) OID.

To allocate an NDIS port, a driver initializes an **NDIS_PORT_CHARACTERISTICS** structure and passes it to
the
[NdisMAllocatePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocateport) function. When
**NdisMAllocatePort** successfully returns, NDIS sets the
**PortNumber** member of **NDIS_PORT_CHARACTERISTICS** to the port number that NDIS assigned to the
port.

NDIS uses a linked list of ports in port activation Plug and Play (PnP) events. NDIS uses the
[NDIS_PORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_port) structure to create a linked list of
ports, and each **NDIS_PORT** structure contains an **NDIS_PORT_CHARACTERISTICS** structure.

## See also

[NDIS Ports](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-ndis-ports)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_PORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_port)

[NDIS_PORT_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_port_array)

[NET_IF_DIRECTION_TYPE](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_direction_type)

[NdisMAllocatePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocateport)

[OID_GEN_ENUMERATE_PORTS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-enumerate-ports)

[OID_GEN_MEDIA_CONNECT_STATUS_EX](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-media-connect-status-ex)

[Types of NDIS Ports](https://learn.microsoft.com/windows-hardware/drivers/network/types-of-ndis-ports)