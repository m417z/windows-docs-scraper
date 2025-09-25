# NDIS_SWITCH_DEREFERENCE_SWITCH_NIC callback function

## Description

The *DereferenceSwitchNic* function decrements the Hyper-V extensible switch reference counter for a network adapter that is connected to an extensible switch port. The reference counter was incremented through a previous call to [ReferenceSwitchNic](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_reference_switch_nic).

## Parameters

### `NdisSwitchContext` [in]

An NDIS_SWITCH_CONTEXT value that contains the handle of the extensible switch module to which the Hyper-V extensible switch extension is attached. When the extension calls [NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers), this handle is returned through the *NdisSwitchContext* parameter.

### `SwitchPortId` [in]

An NDIS_SWITCH_PORT_ID value that contains the unique identifier of the extensible switch port to which the virtual network adapter is connected.

### `SwitchNicIndex` [in]

An NDIS_SWITCH_NIC_INDEX value that specifies the index of the virtual network adapter for which the extensible switch reference counter is to be incremented.

For more information on NDIS_SWITCH_NIC_INDEX values, see [Network Adapter Index Values](https://learn.microsoft.com/windows-hardware/drivers/network/network-adapter-index-values).

## Return value

If the call succeeds, the function returns NDIS_STATUS_SUCCESS. Otherwise, it returns an NDIS_STATUS_*Xxx* error code that is defined in Ndis.h.

## Remarks

The extensible switch extension calls *DereferenceSwitchNic* to decrement the reference counter for a network adapter that is connected to an extensible switch port. While the extensible switch reference counter has a nonzero value, the protocol edge of the extensible switch will not issue an object identifier (OID) set request of [OID_SWITCH_NIC_DELETE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-delete) to delete the connection to the adapter.

The extension must call *DereferenceSwitchNic* if it had previously called [ReferenceSwitchNic](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_reference_switch_nic) for a network adapter connection.

## See also

[NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers)

[OID_SWITCH_NIC_DELETE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-delete)

[ReferenceSwitchNic](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_reference_switch_nic)