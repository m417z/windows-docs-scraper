# _NDIS_SWITCH_PORT_PARAMETERS structure

## Description

The **NDIS_SWITCH_PORT_PARAMETERS** structure contains the configuration data for a Hyper-V extensible switch port.

## Members

### `Header`

The type, revision, and size of the **NDIS_SWITCH_PORT_PARAMETERS** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The **Type** member of **Header** must be set to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SWITCH_PORT_PARAMETERS** structure, the **Revision** member of **Header** must be set to the following value:

#### NDIS_SWITCH_PORT_PARAMETERS_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_NDIS_SWITCH_PORT_PARAMETERS_REVISION_1.

### `Flags`

A ULONG value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `PortId`

An NDIS_SWITCH_PORT_ID value that contains the unique identifier of the extensible switch port.

### `PortName`

 An NDIS_SWITCH_PORT_NAME value that specifies the unique internal name of the extensible switch port.

The internal port name is used by WMI-based policy management applications. For more information, see [Managing Hyper-V Extensible Switch Policies](https://learn.microsoft.com/windows-hardware/drivers/network/managing-hyper-v-extensible-switch-extensibility-policies).

### `PortFriendlyName`

 An NDIS_SWITCH_PORT_FRIENDLYNAME value that specifies the user-friendly description of the extensible switch port.

### `PortType`

An [NDIS_SWITCH_PORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_switch_port_type) value that specifies the type of the extensible switch port.

### `IsValidationPort`

 If TRUE, indicates a port that is temporarily created for test and validation purposes before a VM network adapter connection is established. For more information about this port type, see [Validation Ports](https://learn.microsoft.com/windows-hardware/drivers/network/validation-ports).

### `PortState`

 An [NDIS_SWITCH_PORT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_switch_port_state) value that specifies the current state of the port.

## Remarks

The **InformationBuffer** member of the [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure contains a pointer to an **NDIS_SWITCH_PORT_PARAMETERS** structure for the following OID requests:

* [OID_SWITCH_PORT_CREATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-create)
* [OID_SWITCH_PORT_UPDATED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-updated)
* [OID_SWITCH_PORT_DELETE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-delete)
* [OID_SWITCH_PORT_TEARDOWN](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-teardown)

OID query requests of [OID_SWITCH_PORT_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-array) return an [NDIS_SWITCH_PORT_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_array) structure that contains an array of elements. Each element is formatted as an **NDIS_SWITCH_PORT_PARAMETERS** structure.

Extensible switch extensions can access the port property buffer inside an **NDIS_SWITCH_PORT_PARAMETERS** structure by using the [NDIS_SWITCH_PORT_AT_ARRAY_INDEX](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-switch-port-at-array-index) macro.

**Note** The **NDIS_SWITCH_PORT_NAME** and **NDIS_SWITCH_PORT_FRIENDLYNAME** data types are type-defined by the [IF_COUNTED_STRING](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-if_counted_string_lh) structure. A string that is defined by this structure does not have to be null-terminated. However, the length of the string must be set in the **Length** member of this structure. If the string is null-terminated, the **Length** member must not include the terminating null character.

## See also

[IF_COUNTED_STRING](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-if_counted_string_lh)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NDIS_SWITCH_PORT_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_array)

[NDIS_SWITCH_PORT_AT_ARRAY_INDEX](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-switch-port-at-array-index)

[NDIS_SWITCH_PORT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_parameters)

[NDIS_SWITCH_PORT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_switch_port_state)

[NDIS_SWITCH_PORT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_switch_port_type)

[OID_SWITCH_PORT_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-array)

[OID_SWITCH_PORT_CREATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-create)

[OID_SWITCH_PORT_DELETE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-delete)

[OID_SWITCH_PORT_TEARDOWN](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-teardown)