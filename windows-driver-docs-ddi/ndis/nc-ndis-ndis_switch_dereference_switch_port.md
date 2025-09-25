# NDIS_SWITCH_DEREFERENCE_SWITCH_PORT callback function

## Description

The *DereferenceSwitchPort* function decrements the Hyper-V extensible switch reference counter for an extensible switch port. The reference counter was incremented through a previous call to [ReferenceSwitchPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_reference_switch_port).

## Parameters

### `NdisSwitchContext` [in]

An NDIS_SWITCH_CONTEXT value that contains the handle of the extensible switch module to which the Hyper-V extensible switch extension is attached. When the extension calls [NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers), this handle is returned through the *NdisSwitchContext* parameter.

### `SwitchPortId` [in]

An NDIS_SWITCH_PORT_ID value that contains the unique identifier of the extensible switch port for which the extensible switch reference counter is incremented.

## Return value

If the call succeeds, the function returns NDIS_STATUS_SUCCESS. Otherwise, it returns an NDIS_STATUS_*Xxx* error code that is defined in Ndis.h.

## Remarks

The extensible switch extension calls *DereferenceSwitchPort* to decrement the reference counter for an extensible switch port. While the extensible switch reference counter has a nonzero value, the protocol edge of the extensible switch will not issue an object identifier (OID) set request of [OID_SWITCH_PORT_DELETE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-delete) to delete the port.

The extension must call *DereferenceSwitchPort* if it had previously called [ReferenceSwitchPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_reference_switch_port) for an extensible switch port.

## See also

[NdisFGetOptionalSwitchHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfgetoptionalswitchhandlers)

[OID_SWITCH_PORT_DELETE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-delete)

[ReferenceSwitchPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_switch_reference_switch_port)