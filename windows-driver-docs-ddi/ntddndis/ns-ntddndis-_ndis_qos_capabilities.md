# _NDIS_QOS_CAPABILITIES structure

## Description

The **NDIS_QOS_CAPABILITIES** structure specifies the NDIS Quality of Service (QoS) capabilities of a network adapter that supports the IEEE 802.1 Data Center Bridging (DCB) interface.

## Members

### `Header`

The type, revision, and size of the **NDIS_QOS_CAPABILITIES** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_QOS_CAPABILITIES. To specify the version of the **NDIS_QOS_CAPABILITIES** structure, the driver must set the **Revision** member of **Header** to the following value:

#### NDIS_QOS_CAPABILITIES_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_QOS_CAPABILITIES_REVISION_1.

### `Flags`

A **ULONG** value that contains a bitwise **OR** of flags that specify the NDIS QoS capabilities that a network adapter supports. The following flags are defined:

#### NDIS_QOS_CAPABILITIES_STRICT_TSA_SUPPORTED

If this flag is set, the network adapter supports the strict priority transmission selection algorithm (TSA). For more information about this algorithm, see [Strict Priority Algorithm](https://learn.microsoft.com/windows-hardware/drivers/network/strict-priority-algorithm).

**Note** In order to be compliant with DCB, the network adapter must support the strict priority TSA.

#### NDIS_QOS_CAPABILITIES_MACSEC_BYPASS_SUPPORTED

If this flag is set, the network adapter supports the ability to bypass media access control security (MACsec) processing. For more information about MACsec, refer to the 802.1AE-2006 standard.

#### NDIS_QOS_CAPABILITIES_CEE_DCBX_SUPPORTED

If this flag is set, the network adapter and miniport driver supports the protocols that pre-date the IEEE 802.1Qaz Data Center Bridging Exchange (DCBX) protocol. These protocols include the Converged Enhanced Ethernet (CEE) suite of protocols.

#### NDIS_QOS_CAPABILITIES_IEEE_DCBX_SUPPORTED

If this flag is set, the network adapter and miniport driver supports the IEEE 802.1Qaz DCBX protocol. The DCBX protocol allows DCB parameters to be exchanged between two directly connected peers. This allows these peers to adapt and tune these parameters in order to optimize data transfer over the connection.
For more information about this protocol, see [Overview of Data Center Bridging](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-data-center-bridging).

**Note** If this flag is set, the miniport driver must reject any send requests for DCBX packets.

### `MaxNumTrafficClasses`

A **ULONG** value that specifies the maximum number of NDIS QoS traffic classes that the network adapter supports. For more information, see [NDIS QoS Traffic Classes](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-qos-traffic-classes).

**Note** In order for the network adapter to support NDIS QoS for DCB, it must support at least three traffic classes.

### `MaxNumEtsCapableTrafficClasses`

A **ULONG** value that specifies the maximum number of QoS traffic classes that the network adapter can use with the Enhanced Transmission Selection (ETS) algorithm. This value must be less than or equal to the value of the **MaxNumTrafficClasses** member.

 For more information about ETS, see [Enhanced Transmission Selection (ETS) Algorithm](https://learn.microsoft.com/windows-hardware/drivers/network/enhanced-transmission-selection--ets--algorithm).

**Note** In order for the network adapter to support NDIS QoS for DCB, it must support at least two ETS-capable traffic classes.

### `MaxNumPfcEnabledTrafficClasses`

A **ULONG** value that specifies the maximum number of QoS traffic classes that the network adapter can use with the Priority-based Flow Control (PFC) algorithm. This value must be less than or equal to the value of the **MaxNumTrafficClasses** member.

For more information about PFC, see [Priority-based Flow Control (PFC)](https://learn.microsoft.com/windows-hardware/drivers/network/priority-based-flow-control--pfc).

**Note** In order for the network adapter to support NDIS QoS for DCB, it must support at least one PFC-capable traffic class.

## Remarks

The miniport driver registers the NDIS QoS capabilities of the underlying network adapter from the driver's
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function by following these steps:

1. The miniport driver initializes an **NDIS_QOS_CAPABILITIES** structure with the NDIS QoS capabilities of the network adapter.
2. The miniport driver initializes an [NDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_hardware_assist_attributes)
   structure with the other hardware-assisted capabilities of the network adapter. The driver sets the **HardwareQosCapabilities** member of the **NDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES** structure to a pointer to the **NDIS_QOS_CAPABILITIES** structure.
3. The miniport driver calls [NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) and sets the *MiniportAttributes* parameter to
   a pointer to the [NDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_hardware_assist_attributes)
   structure.

The **NDIS_QOS_CAPABILITIES** structure is also returned in OID query requests of [OID_QOS_CURRENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-current-capabilities) and [OID_QOS_HARDWARE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-hardware-capabilities).

## See also

[NDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_hardware_assist_attributes)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)

[OID_QOS_CURRENT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-current-capabilities)

[OID_QOS_HARDWARE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-qos-hardware-capabilities)