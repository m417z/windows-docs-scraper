# _NDIS_SRIOV_PROBED_BARS_INFO structure

## Description

The **NDIS_SRIOV_PROBED_BARS_INFO** structure specifies the values of the PCI Express (PCIe) Base Address Registers (BARs) of a network adapter that supports the single root I/O virtualization (SR-IOV) interface.

The values specified by the **NDIS_SRIOV_PROBED_BARS_INFO** structure are those that were reported by the adapter following a query that was performed by the PCI bus driver. This query determines the memory or I/O address space that is required by the device.

## Members

### `Header`

The type, revision, and size of the **NDIS_SRIOV_PROBED_BARS_INFO** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SRIOV_PROBED_BARS_INFO** structure, the driver must set the **Revision** member of **Header** to the following value:

#### NDIS_SRIOV_PROBED_BARS_INFO_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_SRIOV_PROBED_BARS_INFO_REVISION_1.

### `BaseRegisterValuesOffset`

A ULONG value that contains the offset, in units of bytes, from the beginning of this structure to an array of ULONG values. The array contains a ULONG value for each BAR of the PCIe network adapter.

The maximum number of elements within this array is PCI_TYPE0_ADDRESSES.

For more information, see the Remarks section.

## Remarks

The **NDIS_SRIOV_PROBED_BARS_INFO** structure is used in OID query requests of [OID_SRIOV_PROBED_BARS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-probed-bars). Each
element in the array that follows the **NDIS_SRIOV_PROBED_BARS_INFO** structure contains a ULONG value for a BAR of the network adapter. The offsets of the elements within the array must match the offsets of the BARs on the adapter.

**Note** Each element in the array must contain the BAR value that was returned during the BAR query that was performed by the PCI bus driver.

For more information about the base address registers of a PCI device, see the *PCI Local Bus Specification*.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_SRIOV_PROBED_BARS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-probed-bars)