# _NDIS_QOS_CLASSIFICATION_ELEMENT structure

## Description

The **NDIS_QOS_CLASSIFICATION_ELEMENT** structure specifies an NDIS Quality of Service (QoS) traffic classification for a network adapter that supports the IEEE 802.1 Data Center Bridging (DCB) interface.

Each traffic classification specifies the following:

* A classification *condition* that is based on a data pattern within the egress packet data.

  Starting with NDIS 6.30, classification conditions are based on a 16-bit value, such as a UDP or TCP destination port or a media access control (MAC) EtherType.
* A classification *action* that defines the traffic class to be used to handle the egress packet.

  Starting with NDIS 6.30, classification actions specify an 802.1p priority level.

For example, a traffic classification could specify that all egress packets for destination TCP port number 3260 (*condition*) are assigned an 802.1p priority level 3 (*action*).

## Members

### `Header`

The type, revision, and size of the **NDIS_QOS_CLASSIFICATION_ELEMENT** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_QOS_CLASSIFICATION_ELEMENT. To specify the version of the **NDIS_QOS_CLASSIFICATION_ELEMENT** structure, the driver must set the **Revision** member of **Header** to the following value:

#### NDIS_QOS_CLASSIFICATION_ELEMENT_REVISION_1

Original version for NDIS 6.30.

Set the **Size** member to NDIS_SIZEOF_QOS_CLASSIFICATION_ELEMENT_REVISION_1.

### `Flags`

A **ULONG** value that contains a bitwise OR of flags that specify the state of the NDIS QoS traffic classifications that a miniport driver supports. The following flags are defined:

#### NDIS_QOS_CLASSIFICATION_ENFORCED_BY_MINIPORT

If this flag is set, the miniport driver accepts the traffic classification parameters that are specified in the **NDIS_QOS_CLASSIFICATION_ELEMENT** structure. If the driver accepts the parameters, it must configure the network adapter to perform the traffic classification as specified by the parameters.

**Note** This flag is set only in the **NDIS_QOS_CLASSIFICATION_ELEMENT** structures that the miniport driver returns to NDIS from an [OID_QOS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-parameters) OID method request.

### `ConditionSelector`

A **USHORT** value that specifies the type of the data pattern that is contained in the **ConditionField** member. For example, the data pattern type could specify a destination UDP port whose value is specified by the **ConditionField** member.

For more information, see [Guidelines for Setting the ConditionSelector and ConditionField Members](https://learn.microsoft.com/).

### `ConditionField`

A **USHORT** value that contains the data pattern whose type is specified by the **ConditionSelector** member.

For more information, see [Guidelines for Setting the ConditionSelector and ConditionField Members](https://learn.microsoft.com/).

### `ActionSelector`

A **USHORT** value that specifies the type of action data that is contained in the **ActionField** member. Starting with NDIS 6.30, the action data type specifies an 802.1p priority level whose value is specified by the **ConditionField** member.

For more information, see [Guidelines for Setting the ActionSelector and ActionField Members](https://learn.microsoft.com/).

### `ActionField`

A **USHORT** value that contains an action value whose type is specified by the **ActionSelector** member.

For more information, see [Guidelines for Setting the ActionSelector and ActionField Members](https://learn.microsoft.com/).

## Remarks

A traffic classification specifies a *condition* and an *action* that the network adapter applies to egress packet data. When the adapter inspects the egress packet data and finds a matching classification condition, it applies the corresponding action to the egress packet.

**Note** Starting with NDIS 6.30, all actions are based on 802.1p priority levels. However, after the network adapter determines the priority level, it must use the egress policies for the NDIS QoS traffic class that is associated with the priority level. The association of priority levels to traffic classes is specified in the [NDIS_QOS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_qos_parameters) structure.

The **NDIS_QOS_CLASSIFICATION_ELEMENT** structure specifies each traffic classification element within the array that is specified by the [NDIS_QOS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_qos_parameters) structure. This structure is used in the following OID requests:

* OID query requests of [OID_QOS_OPERATIONAL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-operational-parameters) and [OID_QOS_REMOTE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-remote-parameters).
* OID method requests of [OID_QOS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-parameters).

The miniport driver also returns an [NDIS_QOS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_qos_parameters) structure that contains an array of **NDIS_QOS_CLASSIFICATION_ELEMENT** structures in the following NDIS status indications:

* [NDIS_STATUS_QOS_OPERATIONAL_PARAMETERS_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-qos-operational-parameters-change)
* [NDIS_STATUS_QOS_REMOTE_PARAMETERS_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-qos-remote-parameters-change)

For more information, see [NDIS QoS Traffic Classifications](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-qos-traffic-classifications).

### Guidelines for Setting the ConditionSelector and ConditionField Members

The following table defines the range of values for the **ConditionSelector** and **ConditionField** members.

| ConditionSelector value | ConditionField value |
| --- | --- |
| NDIS_QOS_CONDITION_RESERVED | The **ConditionField** member must be set to zero.<br><br>**Note** This condition is reserved for future use. |
| NDIS_QOS_CONDITION_DEFAULT | The **ConditionField** member must be set to zero. |
| NDIS_QOS_CONDITION_TCP_PORT | The **ConditionField** member contains a 16-bit destination TCP port value. |
| NDIS_QOS_CONDITION_UDP_PORT | The **ConditionField** member contains a 16-bit destination UDP port value. |
| NDIS_QOS_CONDITION_TCP_OR_UDP_PORT | The **ConditionField** member contains a 16-bit destination TCP or UDP port value. |
| NDIS_QOS_CONDITION_ETHERTYPE | The **ConditionField** member contains a 16-bit IEEE EtherType value.<br><br>**Note** The network adapter needs to determine the frame layout of the packet in order to inspect the EtherType. For example, the location of the EtherType field is different between an Ethernet II and 802.3 frame. |
| NDIS_QOS_CONDITION_NETDIRECT_PORT | The **ConditionField** member contains a 16-bit NetworkDirect port value. |

If the **ConditionSelector** member contains a value of NDIS_QOS_CONDITION_DEFAULT, the associated classification action must be applied to all egress packets that did not match any other classification conditions. When the DCB component issues an OID method request of [OID_QOS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-parameters), it may set the **ConditionSelector** to NDIS_QOS_CONDITION_DEFAULT in only the first **NDIS_QOS_CLASSIFICATION_ELEMENT** structure in the [NDIS_QOS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_qos_parameters) array.

If the **ConditionSelector** member contains a value of NDIS_QOS_CONDITION_NETDIRECT_PORT, the miniport driver must match the **ConditionField** member against either the source or destination port of a NetworkDirect connection. If the miniport driver accepts a NetDirect connection, the driver must match the **ConditionField** member against the source port of any packet it sends over that connection. If the miniport driver initiates a NetDirect connection, it must match the **ConditionField** member against the destination port of any packet it sends over that connection.

For more information on the DCB component, see [NDIS QoS Architecture for Data Center Bridging](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-qos-architecture-for-data-center-bridging).

### Guidelines for Setting the ActionSelector and ActionField Members

The following table defines the range of values for the **ActionSelector** and **ActionField** members.

| ActionSelector value | ActionField value |
| --- | --- |
| NDIS_QOS_ACTION_PRIORITY | The **ActionField** member contains a 3-bit IEEE 802.1p priority level value. For more information on these priority levels, see [IEEE 802.1p Priority Levels](https://learn.microsoft.com/windows-hardware/drivers/network/ieee-802-1p-priority-levels). |

Starting with NDIS 6.30, traffic classification actions define an IEEE 802.1p priority level to which the egress packet is assigned. When the network adapter assigns a priority level to an egress packet, the adapter also applies the parameters for the NDIS QoS traffic class associated with the specified priority level. These parameters determine how the network adapter transmits the packet, and include bandwidth allocation and transmission selection algorithm (TSA).

For more information on NDIS QoS traffic classes, see [NDIS QoS Traffic Classes](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-qos-traffic-classes).

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_QOS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_qos_parameters)

[NDIS_STATUS_QOS_OPERATIONAL_PARAMETERS_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-qos-operational-parameters-change)

[NDIS_STATUS_QOS_REMOTE_PARAMETERS_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-qos-remote-parameters-change)

[OID_QOS_OPERATIONAL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-operational-parameters)

[OID_QOS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-parameters)

[OID_QOS_REMOTE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-remote-parameters)