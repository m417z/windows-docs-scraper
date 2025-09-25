# _NDIS_MSIX_CONFIG_PARAMETERS structure

## Description

The NDIS_MSIX_CONFIG_PARAMETERS structure defines a requested configuration operation and specifies
the parameters that are required for that particular operation.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_MSIX_CONFIG_PARAMETERS structure. The miniport driver sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT, the
**Revision** member to NDIS_MSIX_CONFIG_PARAMETERS_REVISION_1, and the
**Size** member to NDIS_SIZEOF_MSIX_CONFIG_PARAMETERS_REVISION_1.

### `ConfigOperation`

The requested configuration operation for a MSI-X table entry. This operation is specified as one
of the values from the
[NDIS_MSIX_TABLE_OPERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ne-ndis-_ndis_msix_table_config) enumeration.

### `TableEntry`

The MSI-X table entry index.

### `MessageNumber`

The MSI-X message number that is assigned to the device. This value is required for the
**NdisMSIXTableConfigSetTableEntry** operation. This parameter is not used for the
**NdisMSIXTableConfigMaskTableEntry** or
**NdisMSIXTableConfigUnmaskTableEntry** operations.

## Remarks

To mask, unmask, or map MSI-X table entries, an NDIS driver passes the NDIS_MSIX_CONFIG_PARAMETERS
structure to the
[NdisMConfigMSIXTableEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismconfigmsixtableentry) function. NDIS_MSIX_CONFIG_PARAMETERS defines a requested configuration
operation and specifies the parameters that are required for that operation.

## See also

[NDIS_MSIX_TABLE_OPERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ne-ndis-_ndis_msix_table_config)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisMConfigMSIXTableEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismconfigmsixtableentry)