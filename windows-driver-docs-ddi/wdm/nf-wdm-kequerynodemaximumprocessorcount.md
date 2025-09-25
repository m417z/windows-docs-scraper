# KeQueryNodeMaximumProcessorCount function (wdm.h)

## Description

The **KeQueryNodeMaximumProcessorCount** routine returns the maximum number of logical processors that a specified node in a non-uniform memory access (NUMA) multiprocessor system can contain.

## Parameters

### `NodeNumber` [in]

The node number. If a NUMA multiprocessor system contains *n* nodes, valid node numbers are in the range 0 to *n*-1. To get the highest node number (*n*-1) in the system, call the [KeQueryHighestNodeNumber](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryhighestnodenumber) routine.

## Return value

**KeQueryNodeMaximumProcessorCount** returns the maximum number of logical processors.

## Remarks

In a multiprocessor system with a NUMA architecture, a node is a collection of processors that share fast access to a region of memory. Memory access is non-uniform because a processor can access the memory in its node faster than it can access the memory in other nodes.

The count returned by this routine includes any logical processors that can be dynamically added to the node while the multiprocessor system is running.

## See also

[KeQueryHighestNodeNumber](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryhighestnodenumber)