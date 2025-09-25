# KeGetCurrentNodeNumber function (ntddk.h)

## Description

The **KeGetCurrentNodeNumber** routine gets the NUMA node number for the logical processor that the caller is running on.

## Return value

**KeGetCurrentNodeNumber** returns the node number.

## Remarks

In a non-uniform memory access (NUMA) multiprocessor architecture, a node is a collection of processors that share fast access to a region of memory. Memory access is non-uniform because a processor can access the memory in its node faster than it can access the memory in other nodes.

In a NUMA multiprocessor system that contains *n* nodes, the nodes are numbered from 0 to *n*-1. To get the highest node number (*n*-1) in the system, call the [KeQueryHighestNodeNumber](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryhighestnodenumber) routine.

## See also

[KeQueryHighestNodeNumber](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryhighestnodenumber)