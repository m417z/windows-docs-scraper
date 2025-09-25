# IoGetDeviceNumaNode function

## Description

The **IoGetDeviceNumaNode** routine gets the node number of a device.

## Parameters

### `Pdo` [in]

A pointer to a physical device object (PDO). This parameter points to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that represents a physical device.

### `NodeNumber` [out]

A pointer to a location into which the routine writes the node number, if the node number is known.

## Return value

**IoGetDeviceNumaNode** returns STATUS_SUCCESS if the call is successful. Possible error return values include the following:

| Return code | Description |
| --- | --- |
| **STATUS_NOT_FOUND** | The node number of this device is unknown. |
| **STATUS_INVALID_PARAMETER** | The *Pdo* parameter is **NULL** or does not point to a valid device object. |

## Remarks

In a non-uniform memory access (NUMA) multiprocessor architecture, a node is a collection of processors that share fast access to a region of memory. Memory access is non-uniform because a processor can access the memory in its node faster than it can access the memory in other nodes.

A device (for example, a network controller or storage controller) that is connected to a particular node can access the memory in this node faster than it can access the memory in other nodes. The *Pdo* parameter points to a PDO that represents the bus connection between the device and the node.

If a NUMA multiprocessor system contains *n* nodes, the nodes are numbered from 0 to *n*-1. To obtain the highest node number, call the [KeQueryHighestNodeNumber](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryhighestnodenumber) routine.

After the system is initialized, the node count remains fixed while the system continues to run. This count might include memory-only nodes, which are nodes that contain memory but no active logical processors. A node in which all the logical processors are inactive is effectively a memory-only node until the first processor in the node starts to run. Do not assume that the node that a device is connected to contains active processors.

If a system does not have a NUMA architecture, the routine writes zero to the location that the *NodeNumber* parameter points to. An example of non-NUMA architecture is a symmetric multiprocessor system (SMP).

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[KeQueryHighestNodeNumber](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryhighestnodenumber)