# NdisMConfigMSIXTableEntry function

## Description

The
**NdisMConfigMSIXTableEntry** function performs configuration operations for MSI-X table entries for
device-assigned MSI-X messages.

## Parameters

### `NdisMiniportHandle` [in]

An NDIS miniport adapter handle that NDIS supplied to the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `MSIXConfigParameters` [in]

A pointer to a caller-allocated
[NDIS_MSIX_CONFIG_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_msix_config_parameters) structure that defines the requested configuration operation and
specifies the parameters that are required for that particular operation.

## Return value

**NdisMConfigMSIXTableEntry** returns an appropriate failure code from the underlying PCI bus driver
or one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The MSI-X table entry was reconfigured successfully. |
| **NDIS_STATUS_INVALID_PARAMETER** | **NdisMConfigMSIXTableEntry** failed because one or more members in the [NDIS_MSIX_CONFIG_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_msix_config_parameters) structure were invalid. |

## Remarks

NDIS miniport drivers that support MSI-X call the
**NdisMConfigMSIXTableEntry** function to mask, unmask, or map MSI-X table entries to device-assigned
MSI-X messages. Miniport drivers that support RSS use
**NdisMConfigMSIXTableEntry** to change the CPU affinity of MSI-X table entries at run time.

**NdisMConfigMSIXTableEntry** is a wrapper around the
[GUID_MSIX_TABLE_CONFIG_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_msix_table_config_interface) query. Miniport drivers can call
**NdisMConfigMSIXTableEntry** after NDIS calls the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function and
before the driver returns from the
[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) function.

The miniport driver can set the CPU affinity of MSI-X interrupt resources so that the device has at
least one MSI-X message for each RSS processor. Note that the PCI bus driver initially maps the
*n* MSI-X table entries (where
*n* is the number of MSI-X table entries that the NIC hadware reported to the bus) to the first
*n* MSI-X messages in modified resources. After NDIS calls
*MiniportInitializeEx*, when the miniport driver changes the target processor of a particular MSI-X
table entry, the driver calls
**NdisMConfigMSIXTableEntry** to map that table entry to an MSI-X message that already has the affinity
set to the desired processor.

For the
**NdisMSIXTableConfigSetTableEntry** operation, callers of
**NdisMConfigMSIXTableEntry** must run at IRQL <= DISPATCH_LEVEL.

For the
**NdisMSIXTableConfigMaskTableEntry** or
**NdisMSIXTableConfigUnmaskTableEntry** operations, callers of
**NdisMConfigMSIXTableEntry** can be running at any IRQL.

## See also

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_MSIX_CONFIG_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_msix_config_parameters)