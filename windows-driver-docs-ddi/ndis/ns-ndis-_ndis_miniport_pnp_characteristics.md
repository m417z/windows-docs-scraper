# _NDIS_MINIPORT_PNP_CHARACTERISTICS structure

## Description

The NDIS_MINIPORT_PNP_CHARACTERISTICS structure specifies entry points for functions that allow a
miniport driver to process some Plug and Play (PnP) I/O request packets (IRPs).

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_MINIPORT_PNP_CHARACTERISTICS structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_MINIPORT_PNP_CHARACTERISTICS, the
**Revision** member to NDIS_MINIPORT_PNP_CHARACTERISTICS_REVISION_1, and the
**Size** member to NDIS_SIZEOF_MINIPORT_PNP_CHARACTERISTICS_REVISION_1.

### `MiniportAddDeviceHandler`

The entry point of the caller's
[MiniportAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_add_device) function.

### `MiniportRemoveDeviceHandler`

The entry point of the caller's
[MiniportRemoveDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_remove_device) function.

### `MiniportFilterResourceRequirementsHandler`

The entry point of the caller's
[MiniportFilterResourceRequirements](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pnp_irp) function.

### `MiniportStartDeviceHandler`

The entry point of the caller's
[MiniportStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pnp_irp) function, if
any. If this function is not required, set this member to **NULL**.

### `Flags`

Reserved.

## Remarks

Miniport drivers that support MSI-X and will change the interrupt affinity for each MSI-X message
register functions that are defined in the NDIS_MINIPORT_PNP_CHARACTERISTICS structure. To register these
functions, call the
[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) function
from the
[MiniportSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options) function and
specify an NDIS_MINIPORT_PNP_CHARACTERISTICS structure at the
*OptionalHandlers* parameter of
**NdisSetOptionalHandlers**.

## See also

[MiniportAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_add_device)

[MiniportFilterResourceRequirements](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pnp_irp)

[MiniportRemoveDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_remove_device)

[MiniportSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options)

[MiniportStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pnp_irp)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers)