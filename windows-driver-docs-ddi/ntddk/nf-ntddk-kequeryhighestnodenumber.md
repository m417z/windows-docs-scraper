# KeQueryHighestNodeNumber function (ntddk.h)

## Description

The **KeQueryHighestNodeNumber** routine returns the highest node number in a multiprocessor system that has a non-uniform memory access (NUMA) architecture.

## Return value

**KeQueryHighestNodeNumber** returns the highest node number.

## Remarks

In a non-uniform memory access (NUMA) multiprocessor architecture, a node is a collection of processors that share fast access to a region of memory. Memory access is non-uniform because a processor can access the memory in its node faster than it can access the memory in other nodes.

If a NUMA multiprocessor system contains *n* nodes, the nodes are numbered from 0 to *n*-1, and **KeQueryHighestNodeNumber** returns *n*-1. If a system contains one node, **KeQueryHighestNodeNumber** returns zero.

If a system does not have a NUMA architecture, **KeQueryHighestNodeNumber** returns zero. An example of non-NUMA architecture is a symmetric multiprocessor system (SMP).

When Windows initializes a NUMA multiprocessor system, it assigns logical processors to nodes and counts the number of resulting nodes. Windows defines the capacity of a node as the number of processors that are present when the system starts in addition to any other logical processors that can be added to the node while the system is running. If, during initialization, Windows encounters a NUMA hardware node that contains more logical processors than will fit into a group, Windows splits the node into smaller, logical nodes. Each of these nodes does not exceed the maximum group size. The value that is returned by **KeQueryHighestNodeNumber** indicates the number of logical nodes in the system.

After the system has been initialized, the node count remains fixed while the system continues to run. This count might include memory-only nodes, which are nodes that contain memory but no active logical processors.