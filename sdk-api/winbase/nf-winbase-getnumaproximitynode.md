# GetNumaProximityNode function

## Description

Retrieves the NUMA node number that corresponds to the specified proximity domain identifier.

Use the [GetNumaProximityNodeEx](https://learn.microsoft.com/windows/desktop/api/systemtopologyapi/nf-systemtopologyapi-getnumaproximitynodeex) function to retrieve the node number as a **USHORT** value.

## Parameters

### `ProximityId` [in]

The proximity domain identifier of the node.

### `NodeNumber` [out]

The node number. If the processor does not exist, this parameter is 0xFF.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A proximity domain identifier is an index to a NUMA node on a NUMA system. Proximity domain identifiers are found in the ACPI System Resource Affinity Table (SRAT), where they are used to associate processors and memory regions with a particular NUMA node. Proximity domain identifiers are also found in the ACPI namespace, where they are used to associate a device with a particular NUMA node. Proximity domain identifiers are typically used only by management applications provided by system manufacturers. Windows does not use proximity domain identifiers to identify NUMA nodes; instead, it assigns a unique number to each NUMA node in the system.

The relative distance between nodes on a system is stored in the ACPI System Locality Distance Information Table (SLIT), which is not exposed by any Windows functions. For more information about ACPI tables, see the [ACPI specifications](https://uefi.org/acpi/specs).

## See also

[GetNumaProcessorNode](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getnumaprocessornode)

[GetNumaProximityNodeEx](https://learn.microsoft.com/windows/desktop/api/systemtopologyapi/nf-systemtopologyapi-getnumaproximitynodeex)

[NUMA Support](https://learn.microsoft.com/windows/desktop/ProcThread/numa-support)