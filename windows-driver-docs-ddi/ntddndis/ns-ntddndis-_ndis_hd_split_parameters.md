# _NDIS_HD_SPLIT_PARAMETERS structure

## Description

The NDIS_HD_SPLIT_PARAMETERS structure defines the current header-data split settings of a miniport
adapter.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
provider characteristics structure (NDIS_HD_SPLIT_PARAMETERS). The driver sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT, the
**Revision** member to NDIS_ HD_SPLIT_PARAMETERS_REVISION_1, and the
**Size** member to NDIS_SIZEOF_HD_SPLIT_PARAMETERS_REVISION_1.

### `HDSplitCombineFlags`

A set of flags that specify the current header-data split settings of a miniport adapter. A
protocol driver or user-mode application can specify a bitwise OR of the following flags:

#### NDIS_HD_SPLIT_COMBINE_ALL_HEADERS

The miniport adapter should combine split frames. If header-data split is enabled in the
hardware, the miniport driver should combine the header and data before indicating the frame to
NDIS.

## Remarks

The NDIS_HD_SPLIT_PARAMETERS structure is used in the
[OID_GEN_HD_SPLIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-hd-split-parameters) OID set
request to specify the current header-data split settings of a miniport adapter.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_GEN_HD_SPLIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-hd-split-parameters)