# _NDIS_RECEIVE_SCALE_PARAMETERS_V2 structure

## Description

> [!WARNING]
> Some information in this topic relates to prereleased product, which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.
>
> RSSv2 is preview only in Windows 10, version 1803.

The **NDIS_RECEIVE_SCALE_PARAMETERS_V2** structure specifies the Receive Side Scaling (RSS) parameters for a miniport adapter that advertises support for [RSS Version 2 (RSSv2)](https://learn.microsoft.com/windows-hardware/drivers/network/receive-side-scaling-version-2-rssv2-). It is used in the [OID_GEN_RECEIVE_SCALE_PARAMETERS_V2](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-receive-scale-parameters-v2) OID.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
**NDIS_RECEIVE_SCALE_PARAMETERS_V2** structure. Set the
**Type** member of the structure that
**Header** specifies to **NDIS_OBJECT_TYPE_RSS_PARAMETERS_V2**.

For NDIS 6.80 and later drivers, set the
**Revision** member to **NDIS_RECEIVE_SCALE_PARAMETERS_V2_REVISION_1** and the
**Size** member to **sizeof(NDIS_RECEIVE_SCALE_PARAMETERS_V2)**.

### `Flags`

A **ULONG** value that indicates which parameters are being changed. The driver can use these flags to quickly determine which parameters have changed and update the RSS settings accordingly.

In a query request, set this member to zero.

In a set request, the flags are defined as follows:

| Value | Meaning |
| --- | --- |
| **NDIS_RECEIVE_SCALE_PARAM_ENABLE_RSS** | A value of **1** indicates that RSS is enabled for the specified object. The miniport driver needs to look at other parameters.<br><br>A value of **0** indicates that RSS is disabled for the specified object. The **NumberOfQueues** and **NumberOfIndirectionTableEntries** parameters can change when RSS is disabled. Other parameters like **HashInformation** and **HashKey** should be ignored when RSS is disabled. |
| **NDIS_RECEIVE_SCALE_PARAM_HASH_INFO_CHANGED** | The value of the **HashInformation** parameter has changed. |
| **NDIS_RECEIVE_SCALE_PARAM_HASH_KEY_CHANGED** | The contents of the **HashSecretKey** member have changed. |
| **NDIS_RECEIVE_SCALE_PARAM_NUMBER_OF_QUEUES_CHANGED** | The number of queues per VPort has changed. |
| **NDIS_RECEIVE_SCALE_PARAM_NUMBER_OF_ENTRIES_CHANGED** | The number of entries in the indirection table has changed. |

### `HashInformation`

In a set request, this member is the hash type and hash function that the NIC should use to compute the hash
values for the incoming packets. If the hash function that is specified within the
**HashInformation** member is zero, RSS is disabled.

In a query request, this member is the hash type and hash function that the NIC is using.

Overlying drivers and NDIS can use the
[NDIS_RSS_HASH_INFO_FROM_TYPE_AND_FUNC](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-rss-hash-info-from-type-and-func) macro to combine the hash type and hash function into hash
information and set the
**HashInformation** member.

Miniport drivers can use the
[NDIS_RSS_HASH_TYPE_FROM_HASH_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-rss-hash-info-from-type-and-func) macro to get the hash type from
**HashInformation** and the
[NDIS_RSS_HASH_FUNC_FROM_HASH_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-rss-hash-info-from-type-and-func) macro to get the hash function.

This parameter can be changed at the same time that RSS is enabled, or afterward.

### `HashSecretKeySize`

The size of the secret key array of the hash function, in bytes. The size of the array is 40 bytes for **NdisHashFunctionToeplitz**.

This parameter can be changed at the same time that RSS is enabled, or afterward.

### `HashSecretKeyOffset`

The offset, in bytes, of the hash secret key.

This parameter can be changed at the same time that RSS is enabled, or afterward.

### `NumberOfQueues`

The maximum number of queues for the scaling entity. This parameter is an alias for the NUM_QUEUE_PAIRS variable of the [NDIS_NIC_SWITCH_VPORT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_vport_parameters) structure, which can also be queried or set through the [OID_NIC_SWITCH_VPORT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-vport-parameters) OID. It can be changed when RSS is enabled or disabled.

### `NumberOfIndirectionTableEntries`

The number of indirection table entries (ITEs) for the scaling entity. This value is a power of two and does not exceed the corresponding adapter's capabilities. It can be changed at the before RSS is enabled, or afterward.

New values for this parameter are also a power of two and do exceed adapter capabilities. When this number is increased, the miniport driver should clone the current indirection table into the new ITEs as many times as needed (this is possible because of the power-of-two restriction). When this number is decreased, the upper layer guarantees that the portion of the indirection table which is being removed contains exact replicas of the remaining portion.

## See also

[NDIS_NIC_SWITCH_VPORT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_vport_parameters)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_RSS_HASH_FUNC_FROM_HASH_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-rss-hash-info-from-type-and-func)

[NDIS_RSS_HASH_INFO_FROM_TYPE_AND_FUNC](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-rss-hash-info-from-type-and-func)

[NDIS_RSS_HASH_TYPE_FROM_HASH_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-rss-hash-info-from-type-and-func)

[OID_GEN_RECEIVE_SCALE_PARAMETERS_V2](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-receive-scale-parameters-v2)

[OID_NIC_SWITCH_VPORT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-vport-parameters)

[RSS Version 2 (RSSv2)](https://learn.microsoft.com/windows-hardware/drivers/network/receive-side-scaling-version-2-rssv2-)