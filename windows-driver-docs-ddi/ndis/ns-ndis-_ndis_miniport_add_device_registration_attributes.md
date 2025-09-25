# _NDIS_MINIPORT_ADD_DEVICE_REGISTRATION_ATTRIBUTES structure

## Description

The NDIS_MINIPORT_ADD_DEVICE_REGISTRATION_ATTRIBUTES structure specifies a driver-defined context
area for an added device.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_MINIPORT_ADD_DEVICE_REGISTRATION_ATTRIBUTES structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_MINIPORT_ADD_DEVICE_REGISTRATION_ATTRIBUTES, the
**Revision** member to NDIS_MINIPORT_ADD_DEVICE_REGISTRATION_ATTRIBUTES_REVISION_1, and the
**Size** member to NDIS_SIZEOF_MINIPORT_ADD_DEVICE_REGISTRATION_ATTRIBUTES_REVISION_1.

### `MiniportAddDeviceContext`

A handle for a driver-allocated context area.

### `Flags`

Reserved.

## Remarks

Miniport drivers initialize an NDIS_MINIPORT_ADD_DEVICE_REGISTRATION_ATTRIBUTES structure in the
[MiniportAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_add_device) function and pass
this structure to the
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) function.

NDIS later passes the context handle in the
**MiniportAddDeviceContext** member of NDIS_MINIPORT_ADD_DEVICE_REGISTRATION_ATTRIBUTES to the
*MiniportAddDeviceContext* parameter of the
[MiniportRemoveDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_remove_device),
[MiniportStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pnp_irp), and
[MiniportFilterResourceRequirements](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pnp_irp) functions. NDIS passes the same handle to the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function in
the
**MiniportAddDeviceContext** member of the
[NDIS_MINIPORT_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_init_parameters) structure.

## See also

[MiniportAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_add_device)

[MiniportFilterResourceRequirements](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pnp_irp)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportRemoveDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_remove_device)

[MiniportStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pnp_irp)

[NDIS_MINIPORT_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_init_parameters)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)