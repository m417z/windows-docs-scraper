# NDIS_SWITCH_REFERENCE_SWITCH_NIC callback function

## Description

The *ReferenceSwitchNic* function increments the Hyper-V extensible switch reference counter for a network adapter that is connected to an extensible switch port.

## Parameters

### `NdisSwitchContext` [in]

An NDIS_SWITCH_CONTEXT value that contains the handle of the extensible switch module to which the Hyper-V extensible switch extension is attached. When the extension calls [NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers), this handle is returned through the *NdisSwitchContext* parameter.

### `SwitchPortId` [in]

An NDIS_SWITCH_PORT_ID value that contains the unique identifier of the extensible switch port to which the virtual network adapter is connected.

### `SwitchNicIndex` [in]

An NDIS_SWITCH_NIC_INDEX value that specifies the index of the virtual network adapter for which the extensible switch reference counter is to be incremented.

For more information on NDIS_SWITCH_NIC_INDEX values, see [Network Adapter Index Values](https://learn.microsoft.com/windows-hardware/drivers/network/network-adapter-index-values).

**Note** This parameter must specify the index value of a network adapter that is in a connected state. Index values for network adapters that are in a created or disconnected state cannot be specified. For more information about network connection states, see [Hyper-V Extensible Switch Port and Network Adapter States](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-port-and-network-adapter-states).

## Return value

If the call succeeds, the function returns NDIS_STATUS_SUCCESS. Otherwise, it returns an NDIS_STATUS_*Xxx* error code that is defined in Ndis.h.

## Remarks

The extensible switch extension calls *ReferenceSwitchNic* to increment a reference counter for a network adapter that is connected to an extensible switch port. While the reference counter has a nonzero value, the protocol edge of the extensible switch will not issue an object identifier (OID) set request of [OID_SWITCH_NIC_DELETE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-delete) to delete the connection to the adapter.

After the extension calls *ReferenceSwitchNic*, it must call [DereferenceSwitchNic](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_dereference_switch_nic) to decrement the extensible switch reference counter.

The extension should call *ReferenceSwitchNic* before it performs the following operations:

* Forwards an [OID_SWITCH_NIC_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-request) OID request over the extensible switch control path to an underlying physical network adapter.

  For more information, see [Managing OID Requests to Physical Network Adapters](https://learn.microsoft.com/windows-hardware/drivers/network/managing-oid-requests-to-physical-network-adapters).
* Forwards an [NDIS_STATUS_SWITCH_NIC_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-switch-nic-status) status indication over the extensible switch control path from an underlying external adapter.

  For more information, see [Managing NDIS Status Indications from Physical Network Adapters](https://learn.microsoft.com/windows-hardware/drivers/network/managing-ndis-status-indications-from-physical-network-adapters).

**Note** The extension must not call *ReferenceSwitchNic* when forwarding packets over the extensible switch data path. The extensible switch interface manages its own reference counters for packets that are forwarded to ports and network adapter connections over the data path.

The extension calls *ReferenceSwitchNic* after the network adapter connection has reached the *Network adapter connection created* state. The extension must not call *ReferenceSwitchNic* after the connection has reached the *Network adapter disconnected* or *Network adapter deleted* states. For more information about these states, see [Hyper-V Extensible Switch Port and Network Adapter States](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-port-and-network-adapter-states).

**Note** When the extension calls *ReferenceSwitchNic*, it does not have to synchronize the call with its code that handles OID requests. As a result, it is possible for the extension to call *ReferenceSwitchNic* while the protocol edge of the extensible switch issues an OID request of [OID_SWITCH_NIC_DISCONNECT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-disconnect). However, if the call to *ReferenceSwitchNic* completes with NDIS_STATUS_SUCCESS, the extension can still forward [OID_SWITCH_NIC_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-request) OID request or [NDIS_STATUS_SWITCH_NIC_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-switch-nic-status) status indications after it handles the OID_SWITCH_NIC_DISCONNECT OID request.

## See also

[DereferenceSwitchNic](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_dereference_switch_nic)

[NDIS_STATUS_SWITCH_NIC_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-switch-nic-status)

[NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers)

[OID_SWITCH_NIC_DELETE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-delete)

[OID_SWITCH_NIC_DISCONNECT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-disconnect)

[OID_SWITCH_NIC_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-request)