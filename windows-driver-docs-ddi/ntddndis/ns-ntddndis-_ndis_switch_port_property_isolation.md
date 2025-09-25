# _NDIS_SWITCH_PORT_PROPERTY_ISOLATION structure

## Description

The **NDIS_SWITCH_PORT_PROPERTY_ISOLATION** structure is used to specify the isolation properties for a VM network adapter's port.

## Members

### `Header`

The type, revision, and size of the **NDIS_SWITCH_PORT_PROPERTY_ISOLATION** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The **Type** member of **Header** must be set to **NDIS_OBJECT_TYPE_DEFAULT**. To specify the version of the **NDIS_SWITCH_PORT_PROPERTY_ISOLATION** structure, the **Revision** member of **Header** must be set to the following value:

#### NDIS_SWITCH_PORT_PROPERTY_ISOLATION_REVISION_1

Original version for NDIS 6.40 and later.

Set the **Size** member to **NDIS_SIZEOF_NDIS_SWITCH_PORT_PROPERTY_ISOLATION_REVISION_1**.

### `Flags`

A **ULONG** value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `IsolationMode`

An [NDIS_ISOLATION_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_isolation_mode) enumeration value that specifies the isolation mode.

### `AllowUntaggedTraffic`

Specifies whether the VM network adapter port is allowed to send or receive untagged packets. If untagged packets are allowed, the VM network adapter miniport driver tags untagged packets with the default isolation ID specified by the **DefaultIsolationId** member. Otherwise, the miniport driver drops them.

### `DefaultIsolationId`

The default isolation ID that is applied to tagged packets if the **AllowUntaggedTraffic** member is **TRUE**.

## See also

[NDIS_ISOLATION_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_isolation_mode)

[NDIS_ISOLATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_isolation_parameters)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)