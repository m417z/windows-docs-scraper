# GetNumaProximityNodeEx function

## Description

Retrieves the NUMA node number that corresponds to the specified proximity identifier as a **USHORT** value.

## Parameters

### `ProximityId` [in]

The proximity identifier of the node.

### `NodeNumber` [out]

Points to a variable to receive the node number for the specified proximity identifier.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

A proximity domain identifier is an index to a NUMA node on a NUMA system. Proximity domain identifiers are found in the ACPI System Resource Affinity Table (SRAT), where they are used to associate processors and memory regions with a particular NUMA node. Proximity domain identifiers are also found in the ACPI namespace, where they are used to associate a device with a particular NUMA node. Proximity domain identifiers are typically used only by management applications provided by system manufacturers. Windows does not use proximity domain identifiers to identify NUMA nodes; instead, it assigns a unique number to each NUMA node in the system.

The relative distance between nodes on a system is stored in the ACPI System Locality Distance Information Table (SLIT), which is not exposed by any Windows functions. For more information about ACPI tables, see the [ACPI specifications](https://uefi.org/specifications).

The only difference between the **GetNumaProximityNodeEx** function and the [GetNumaProximityNode](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getnumaproximitynode) function is the data type of the *NodeNumber* parameter.

To compile an application that uses this function, set _WIN32_WINNT >= 0x0601. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[GetNumaProximityNode](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getnumaproximitynode)

[NUMA Support](https://learn.microsoft.com/windows/desktop/ProcThread/numa-support)