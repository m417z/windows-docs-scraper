# NDIS_SWITCH_REFERENCE_SWITCH_PORT callback function

## Description

The *ReferenceSwitchPort* function increments the Hyper-V extensible switch reference counter for an extensible switch port.

## Parameters

### `NdisSwitchContext` [in]

An NDIS_SWITCH_CONTEXT value that contains the handle of the extensible switch module to which the Hyper-V extensible switch extension is attached. When the extension calls [NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers), this handle is returned through the *NdisSwitchContext* parameter.

### `SwitchPortId` [in]

An NDIS_SWITCH_PORT_ID value that contains the unique identifier of the extensible switch port for which the extensible switch reference counter is incremented.

**Note** The *SwitchPortId* parameter must specify the identifier of a port that is in a created state. Identifiers for ports that are in a teardown or deleted state cannot be specified. For more information about port states, see [Hyper-V Extensible Switch Port and Network Adapter States](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-port-and-network-adapter-states).

## Return value

If the call succeeds, the function returns NDIS_STATUS_SUCCESS. Otherwise, it returns an NDIS_STATUS_*Xxx* error code that is defined in Ndis.h.

## Remarks

The extensible switch extension calls *ReferenceSwitchPort* to increment the reference counter for an extensible switch port. While the reference counter has a nonzero value, the protocol edge of the extensible switch will not issue an object identifier (OID) set request of [OID_SWITCH_PORT_DELETE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-delete) to delete the extensible switch port.

After the extension calls *ReferenceSwitchPort*, it must call [DereferenceSwitchPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_dereference_switch_port) to decrement the reference counter.

The extension calls *ReferenceSwitchPort* after the port has reached the *Port created* state. The extension must not call *ReferenceSwitchPort* after the connection has reached the *Port tearing down* or *Port not created* states. For more information about these states, see [Hyper-V Extensible Switch Port and Network Adapter States](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-port-and-network-adapter-states).

 The extension must call *ReferenceSwitchPort* when it performs any operation that requires the port to be in an active state. For example, the extension must call *ReferenceSwitchPort* before it issues an OID method request of [OID_SWITCH_PORT_PROPERTY_ENUM](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-enum).

The extension calls *ReferenceSwitchPort* after the port has reached the *Port created* state. The extension must not call [ReferenceSwitchNic](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_reference_switch_nic) after the port has reached the *Port tearing down* state. For more information about these states, see [Hyper-V Extensible Switch Port and Network Adapter States](https://learn.microsoft.com/windows-hardware/drivers/network/hyper-v-extensible-switch-port-and-network-adapter-states).

**Note** When the extension calls *ReferenceSwitchPort*, it does not have to synchronize the call with its code that handles OID requests. As a result, it is possible for the extension to call *ReferenceSwitchPort* while the protocol edge of the extensible switch issues an OID request of [OID_SWITCH_PORT_TEARDOWN](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-teardown). However, if the call to *ReferenceSwitchPort* completes with NDIS_STATUS_SUCCESS, the extension can still issue the [OID_SWITCH_PORT_PROPERTY_ENUM](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-enum) OID request after it handles the OID_SWITCH_PORT_TEARDOWN OID request.

## See also

[DereferenceSwitchNic](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_dereference_switch_nic)

[NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers)

[OID_SWITCH_PORT_DELETE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-delete)

[OID_SWITCH_PORT_PROPERTY_ENUM](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-enum)

[OID_SWITCH_PORT_TEARDOWN](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-teardown)