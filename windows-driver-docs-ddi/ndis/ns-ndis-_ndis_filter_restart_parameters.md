# _NDIS_FILTER_RESTART_PARAMETERS structure

## Description

The NDIS_FILTER_RESTART_PARAMETERS structure defines the restart parameters for the filter
module.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure
for the NDIS_FILTER_RESTART_PARAMETERS structure. NDIS sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_FILTER_RESTART_PARAMETERS, the
**Revision** member to NDIS_FILTER_RESTART_PARAMETERS_REVISION_1, and the Size member to
NDIS_SIZEOF__FILTER_RESTART_PARAMETERS_REVISION_1.

### `MiniportMediaType`

The
NdisMedium
*Xxx* type that the base underlying miniport adapter supports. For more information, see
[NDIS_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_medium).

### `MiniportPhysicalMediaType`

The physical medium type for the base underlying miniport adapter. For more information, see
[OID_GEN_PHYSICAL_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-physical-medium).

### `RestartAttributes`

A pointer to an [NDIS_RESTART_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_restart_attributes) structure.

### `LowerIfIndex`

The NDIS network interface index of the interface just below the current filter module. That is,
if there are filter modules or NDIS 5.*x* filter intermediate drivers that are installed over a physical miniport adapter or the
highest-level MUX intermediate driver, this member contains the interface index of the filter module
interface or filter intermediate driver interface that is just below the current filter module. If there
are no filter module or filter intermediate driver interfaces installed over the physical miniport
adapter or the highest-level MUX intermediate driver, this member contains the interface index of the
underlying physical miniport adapter or the highest-level MUX intermediate driver virtual
miniport.

### `LowerIfNetLuid`

The NDIS network interface
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) value of the interface just below the
current filter module. That is, if there are filter modules or NDIS 5.*x* filter intermediate drivers that are installed over a physical miniport adapter or the
highest-level MUX intermediate driver, this member contains the network interface NET_LUID of the filter
module interface or filter intermediate driver interface that is just below the current filter module.
If there are no filter module or filter intermediate driver interfaces installed over the physical
miniport adapter or the highest-level MUX intermediate driver, this member contains the network
interface NET_LUID of the underlying physical miniport adapter or the highest-level MUX intermediate
driver virtual miniport.

### `Flags`

Reserved for future use.

## Remarks

To define filter module restart parameters, NDIS passes a pointer to an NDIS_FILTER_RESART_PARAMETERS
structure to the
[FilterRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_restart) function.

Filter drivers can modify the restart attributes that are specified by underlying drivers. For more
information about how to modify restart attributes, see
[FilterRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_restart).

## See also

[FilterRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_restart)

[NDIS_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_medium)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_RESTART_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_restart_attributes)

[OID_GEN_PHYSICAL_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-physical-medium)