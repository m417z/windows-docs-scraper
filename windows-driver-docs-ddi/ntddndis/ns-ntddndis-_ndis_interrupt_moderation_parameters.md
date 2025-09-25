# _NDIS_INTERRUPT_MODERATION_PARAMETERS structure

## Description

The NDIS_INTERRUPT_MODERATION_PARAMETERS structure defines interrupt parameters for the
[OID_GEN_INTERRUPT_MODERATION](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-interrupt-moderation) OID.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_INTERRUPT_MODERATION_PARAMETERS structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT, the
**Revision** member to NDIS_INTERRUPT_MODERATION_PARAMETERS_REVISION_1, and the
**Size** member to NDIS_SIZEOF_INTERRUPT_MODERATION_PARAMETERS_REVISION_1.

### `Flags`

A bitwise OR of the following flags:

#### NDIS_INTERRUPT_MODERATION_CHANGE_NEEDS_RESET

A network interface card (NIC) must have a hardware reset to enable or disable interrupt
moderation.

#### NDIS_INTERRUPT_MODERATION_CHANGE_NEEDS_REINITIALIZE

A miniport driver must complete a halt and reinitialize cycle to enable or disable interrupt
moderation. If this flag is enabled, there is also a hardware reset.

### `InterruptModeration`

An NDIS_INTERRUPT_MODERATION-typed value that indicates or specifies the current interrupt
moderation status.

The following values are supported:

#### NdisInterruptModerationUnknown

In an OID query, this value indicates that the miniport driver cannot determine whether
interrupt moderation is enabled or disabled on a NIC. This value is invalid for a set request.

#### NdisInterruptModerationNotSupported

In an OID query, this value indicates that the NIC or its miniport driver does not support
interrupt moderation. This value is invalid for a set request.

#### NdisInterruptModerationEnabled

In an OID query, this value indicates that interrupt moderation is enabled on the NIC. In an OID
set,
**NdisInterruptModerationEnabled** indicates that interrupt moderation should be enabled on the
NIC.

#### NdisInterruptModerationDisabled

In an OID query, this value indicates that interrupt moderation is disabled on the NIC. In an
OID set,
**NdisInterruptModerationDisabled** indicates that interrupt moderation should be disabled on the
NIC.

## Remarks

The NDIS_INTERRUPT_MODERATION_PARAMETERS structure defines interrupt parameters for the
[OID_GEN_INTERRUPT_MODERATION](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-interrupt-moderation) OID
query and set operations. Only the
**NdisInterruptModerationEnabled** and
**NdisInterruptModerationDisabled** values for the
**InterruptModeration** member apply to set operations.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_GEN_INTERRUPT_MODERATION](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-interrupt-moderation)