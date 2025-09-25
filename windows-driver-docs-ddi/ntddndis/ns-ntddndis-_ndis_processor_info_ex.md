# _NDIS_PROCESSOR_INFO_EX structure

## Description

The **NDIS_PROCESSOR_INFO_EX** structure specifies information about a processor in the local
computer.

## Members

### `ProcNum`

The processor number that is assigned to the processor.

### `SocketId`

The socket identifier for the processor. This is the number that is assigned to the motherboard
socket on the local computer. That is, it is a physical processor identifier. The possible values for
this member are zero to the number of sockets on the motherboard minus one.

### `CoreId`

The core ID of the processor. The value is in the range from zero through the number in the
**NumCoresPerSocket** member of the NDIS_SYSTEM_PROCESSOR_INFO_EX structure minus one.

### `HyperThreadId`

The hyper-threading ID of the processor. The value is in the range from zero through the number in
the
**MaxHyperThreadingProcsPerCore** member of the NDIS_SYSTEM_PROCESSOR_INFO_EX structure minus
one.

### `NodeId`

The node identifier of the processor. This is the number of the NUMA node to which the processor
belongs. This range of possible values is zero to the number of NUMA nodes on the local computer minus
one.

### `NodeDistance`

The node distance of the processor. If the handle at the
*NdisHandle* parameter that the caller passed to the
[NdisGetProcessorInformationEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetprocessorinformationex) function is not **NULL** and is a miniport adapter handle, this member
contains the distance of the corresponding NIC from this processor's NUMA node. Otherwise, this member
is zero for miniport drivers or USHORT_MAX (0xffff) for other drivers.

## Remarks

The NDIS_PROCESSOR_INFO_EX structure is used in the
[NDIS_SYSTEM_PROCESSOR_INFO_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_system_processor_info_ex) structure.

## See also

[NDIS_PROCESSOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_processor_info)

[NDIS_SYSTEM_PROCESSOR_INFO_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_system_processor_info_ex)

[NdisGetProcessorInformationEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetprocessorinformationex)