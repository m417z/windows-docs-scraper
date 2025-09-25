# _NDIS_PORT_AUTHENTICATION_PARAMETERS structure

## Description

The NDIS_PORT_AUTHENTICATION_PARAMETERS structure specifies the state parameters for an NDIS
port.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_PORT_AUTHENTICATION_PARAMETERS structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT, the
**Revision** member to NDIS_PORT_AUTHENTICATION_PARAMETERS_REVISION_1, and the
**Size** member to NDIS_SIZEOF_PORT_AUTHENTICATION_PARAMETERS_REVISION_1.

### `SendControlState`

The control state of the port that the miniport adapter should use for send operations. This
member must contain one of the following values:

#### NdisPortControlStateUnknown

The port's control state for send operations is unknown.

#### NdisPortControlStateControlled

The port is in a controlled state for send operations. That is, the port requires
authorization.

#### NdisPortControlStateUncontrolled

The port is in an uncontrolled state for send operations. That is, the port does not require
authorization.

### `RcvControlState`

The control state of the port that the miniport adapter should use for receive operations. This
member must contain one of the following values:

#### NdisPortControlStateUnknown

The port's control state for receive operations is unknown.

#### NdisPortControlStateControlled

The port is in a controlled state for receive operations. That is, the port requires
authorization.

#### NdisPortControlStateUncontrolled

The port is in an uncontrolled state for receive operations. That is, the port does not require
authorization.

### `SendAuthorizationState`

The authorization state of the port that the miniport adapter should use for send operations.
Ignore this member if the
**SendControlState** member is set to
**NdisPortControlStateUncontrolled**.

This member must contain one of the following values:

#### NdisPortAuthorizationUnknown

The port's authorization state for send operations is unknown.

#### NdisPortAuthorized

The port is authorized for send operations.

#### NdisPortUnauthorized

The port is not authorized for send operations.

#### NdisPortReauthorizing

The port is re-authorizing for send operations.

### `RcvAuthorizationState`

The authorization state of the port that the miniport adapter should use for receive operations.
Ignore this member if the
**RcvControlState** member is set to
**NdisPortControlStateUncontrolled**.

This member must contain one of the following values:

#### NdisPortAuthorizationUnknown

The port's authorization state for receive operations is unknown.

#### NdisPortAuthorized

The port is authorized for receive operations.

#### NdisPortUnauthorized

The port is not authorized for receive operations.

#### NdisPortReauthorizing

The port is re-authorizing for receive operations.

## Remarks

The NDIS_PORT_AUTHENTICATION_PARAMETERS structure is used in
[OID_GEN_PORT_AUTHENTICATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-port-authentication-parameters) OID requests to specify the current authentication state of
an NDIS port.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_GEN_PORT_AUTHENTICATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-port-authentication-parameters)