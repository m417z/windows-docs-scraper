# _NDIS_QOS_PARAMETERS structure

## Description

The **NDIS_QOS_PARAMETERS** structure specifies the NDIS Quality of Service (QoS) parameters that are enabled on a network adapter that supports the IEEE 802.1 Data Center Bridging (DCB) interface.

## Members

### `Header`

The type, revision, and size of the **NDIS_QOS_PARAMETERS** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_QOS_PARAMETERS. To specify the version of the **NDIS_QOS_PARAMETERS** structure, the driver must set the **Revision** member of **Header** to the following value:

#### NDIS_QOS_PARAMETERS_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_QOS_PARAMETERS_REVISION_1.

### `Flags`

A **ULONG** value that contains a bitwise **OR** of flags that specify the status of the NDIS QoS parameters for the network adapter. For more information about this member, see [Overview of the Flags Member](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_qos_parameters#overview).

### `NumTrafficClasses`

A **ULONG** value that specifies the number of NDIS QoS traffic classes that are enabled on the network adapter. Each traffic class is referenced through an identifier in the range from zero to (**NumTrafficClasses**–1).

**Note** The value of the **NumTrafficClasses** member must be less than or equal to **min**(**NDIS_QOS_MAXIMUM_TRAFFIC_CLASSES**, *MaxNumTrafficClasses*), where *MaxNumTrafficClasses* is the value of the **MaxNumTrafficClasses** member that was specified in the [NDIS_QOS_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_qos_capabilities) structure.

### `PriorityAssignmentTable`

An array of **UCHAR** elements where each element represents the traffic class associated with an IEEE 802.1p priority level. The **PriorityAssignmentTable** array is indexed by the 802.1p priority level (0–7).

Each element contains the traffic class identifier. This identifier is the index of the [NDIS_QOS_CLASSIFICATION_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_qos_classification_element) structure for the traffic class within the classification array.

**Note** Each element in the **PriorityAssignmentTable** array must be assigned a valid traffic class identifier. A traffic class identifier can be assigned to more than one element in the **PriorityAssignmentTable** array.

### `TcBandwidthAssignmentTable`

An array of **UCHAR** elements that specifies the percentage of the bandwidth allocation assigned to each traffic class. The **TcBandwidthAssignmentTable** array is indexed by the traffic class identifier.

Each element of the **TcBandwidthAssignmentTable** array specifies the bandwidth allocation for the traffic classes. The total value of all bandwidth allocation assignments in the **TcBandwidthAssignmentTable** array must equal 100.

**Note** Bandwidth allocation is supported only for the Enhanced Transmission Selection (ETS) TSA. If the element for the traffic class in the **TsaAssignmentTable** array is not set to NDIS_QOS_TSA_ETS, the element for the traffic class in the **TcBandwidthAssignmentTable** array must be set to zero.

### `TsaAssignmentTable`

An array of **UCHAR** elements that specifies the TSA assigned to each traffic class. The **TsaAssignmentTable** array is indexed by the traffic class identifier.

Each element of the **TsaAssignmentTable** array contains one of the following values:

#### NDIS_QOS_TSA_STRICT

The strict priority algorithm must be used as the TSA for the traffic class. For more information about this TSA, see [Strict Priority Algorithm](https://learn.microsoft.com/windows-hardware/drivers/network/strict-priority-algorithm).

#### NDIS_QOS_TSA_CBS

The IEEE 802.1Qav credit-based shaper (CBS) algorithm must be used as the TSA for the traffic class.

**Note** Starting with Windows Server 2012, the DCB component (Msdcb.sys) does not support the CBS TSA and won't enable this parameter through object identifier (OID) method requests of [OID_QOS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-parameters). For more information on the DCB component, see [NDIS QoS Architecture for Data Center Bridging](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-qos-architecture-for-data-center-bridging).

#### NDIS_QOS_TSA_ETS

The IEEE 802.1Qaz Enhanced Transmission Selection (ETS) algorithm must be used as the TSA for the traffic class. For more information about this TSA, see [Enhanced Transmission Selection (ETS) Algorithm](https://learn.microsoft.com/windows-hardware/drivers/network/enhanced-transmission-selection--ets--algorithm).

### `PfcEnable`

A bitmap of 32 bits. The most-significant 24 bits are reserved for future use. The least-significant 8 bits are used to specify whether PFC
is enabled on the IEEE 802.1p priority level. If the bit is set to one, PFC is enabled for the priority level.

| Bit range | Meaning |
| --- | --- |
| 31:24 | Reserved for future use. |
| 7 | If set to one, PFC is enabled on 802.1p priority level 7 (*network control*). |
| 6 | If set to one, PFC is enabled on 802.1p priority level 6 (*internetwork control*). |
| 5 | If set to one, PFC is enabled on 802.1p priority level 5 (*voice*). |
| 4 | If set to one, PFC is enabled on 802.1p priority level 4 (*video*). |
| 3 | If set to one, PFC is enabled on 802.1p priority level 3 (*critical applications*). |
| 2 | If set to one, PFC is enabled on 802.1p priority level 2 (*excellent effort*). |
| 1 | If set to one, PFC is enabled on 802.1p priority level 1 (*background*). |
| 0 | If set to one, PFC is enabled on 802.1p priority level 0 (*best effort*). |

**Note** The total number of 802.1p priority levels that have PFC enabled must be less than or equal to the value of the **MaxNumPfcEnabledTrafficClasses** member in the [NDIS_QOS_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_qos_capabilities) structure.

For more information about priority levels, see [IEEE 802.1p Priority Levels](https://learn.microsoft.com/windows-hardware/drivers/network/ieee-802-1p-priority-levels).

### `NumClassificationElements`

A **ULONG** value that specifies the number of elements in the traffic classification array. The offset to the first element in this array is specified by the **FirstClassificationElementOffset** member.

**Note** Each element in the array is formatted as an [NDIS_QOS_CLASSIFICATION_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_qos_classification_element) structure.

### `ClassificationElementSize`

A **ULONG** value that specifies the size, in bytes, of each element in the traffic classification array.

**Note** Starting with NDIS 6.30, this member must be set to `sizeof(NDIS_QOS_CLASSIFICATION_ELEMENT`).

### `FirstClassificationElementOffset`

A **ULONG** value that specifies the offset, in bytes, to the first element in an array of traffic classification elements that follow this structure. The offset is measured from the start of the **NDIS_QOS_PARAMETERS** structure up to the beginning of the first element. Each element in the array is an [NDIS_QOS_CLASSIFICATION_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_qos_classification_element) structure.

**Note** If **NumClassificationElements** is set to zero, this member is ignored.

## Remarks

The **NDIS_QOS_PARAMETERS** structure specifies the parameters that define how the network adapter prioritizes transmit, or *egress*, packets. This structure is used in the following OID requests:

* OID query request of [OID_QOS_OPERATIONAL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-operational-parameters). This OID request returns the operational QoS parameters that are currently provisioned on the network adapter.
* OID query request of [OID_QOS_REMOTE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-remote-parameters). This OID request returns the remote QoS parameters that are currently provisioned on the network adapter.
* OID method requests of [OID_QOS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-parameters). This OID request provisions the network adapter with the local QoS parameters.

The miniport driver also returns an **NDIS_QOS_PARAMETERS** structure in the following NDIS status indications:

* [NDIS_STATUS_QOS_OPERATIONAL_PARAMETERS_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-qos-operational-parameters-change). This miniport driver issues this status indication when its operational QoS parameters change.
* [NDIS_STATUS_QOS_REMOTE_PARAMETERS_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-qos-remote-parameters-change). This miniport driver issues this status indication when its remote QoS parameters change.

For more information about the types of NDIS QoS parameters, see [Overview of NDIS QoS Parameters](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-ndis-qos-parameters).

### Overview of the Flags Member

The **Flags** member contains a bitwise **OR** of flags that specify the status of the NDIS QoS parameters for the network adapter.

The miniport driver sets the **Flags** member when it issues the following NDIS status indications:

* [NDIS_STATUS_QOS_OPERATIONAL_PARAMETERS_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-qos-operational-parameters-change)
* [NDIS_STATUS_QOS_REMOTE_PARAMETERS_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-qos-remote-parameters-change)

The DCB component sets the **Flags** member when it issues an OID method request of [OID_QOS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-parameters).

**Note** Only the DCB component can issue the OID request. An overlying protocol or filter driver must not issue this OID.
For more information on the DCB component, see [NDIS QoS Architecture for Data Center Bridging](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-qos-architecture-for-data-center-bridging).

The following flags are defined for the **Flags** member.

**Note** NDIS guarantees that both the **NDIS_QOS_PARAMETERS_ETS_CONFIGURED** and **NDIS_QOS_PARAMETERS_PFC_CONFIGURED** flags are set or cleared together.

The **NDIS_QOS_PARAMETERS_*Xxx*_CHANGED** flags provide hints as to whether the corresponding group of parameters has changed from a previous [OID_QOS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-parameters) method request or **NDIS_QOS_PARAMETERS_*Xxx*_CHANGED** status notification. When the miniport driver issues the **NDIS_QOS_PARAMETERS_*Xxx*_CHANGED** status notifications, it can optionally set these flags.

**Note** If the **NDIS_QOS_PARAMETERS_*Xxx*_CHANGED** flags are not set, overlying drivers must not assume that the corresponding group of parameters are supported or enabled on the underlying network adapter.

## See also

[NDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_hardware_assist_attributes)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_QOS_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_qos_capabilities)

[NDIS_QOS_CLASSIFICATION_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_qos_classification_element)

[NDIS_STATUS_QOS_OPERATIONAL_PARAMETERS_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-qos-operational-parameters-change)

[NDIS_STATUS_QOS_REMOTE_PARAMETERS_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-qos-remote-parameters-change)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)

[OID_QOS_CURRENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-current-capabilities)

[OID_QOS_HARDWARE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-hardware-capabilities)