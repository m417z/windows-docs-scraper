# GetLogicalProcessorInformationEx function

## Description

Retrieves information about the relationships of logical processors and related hardware.

## Parameters

### `RelationshipType` [in]

The type of relationship to retrieve. This parameter can be one of the following [LOGICAL_PROCESSOR_RELATIONSHIP](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-logical_processor_relationship) values.

| Value | Meaning |
| --- | --- |
 **RelationProcessorCore**<br><br>0 | Retrieves information about logical processors that share a single processor core. || **RelationNumaNode**<br><br>1 | Retrieves information about logical processors that are part of the same NUMA node. |
| **RelationCache**<br><br>2 | Retrieves information about logical processors that share a cache. |
||  |  |
| --- | --- |
| **RelationProcessorPackage**<br><br>3 | Retrieves information about logical processors that share a physical package. |
| **RelationGroup**<br><br>4 | Retrieves information about logical processors that share a processor group. |
| **RelationProcessorDie**<br><br>5 | Retrieves information about logical processors that share a processor die. |

 **RelationNumaNodeEx**<br><br>6 | Retrieves information about logical processors that are part of the same NUMA node (with full affinity). || **RelationProcessorModule**<br><br>7 | Retrieves information about logical processors that share a processor module. |
| **RelationAll**<br><br>0xffff | Retrieves information about logical processors for all relationship types (cache, NUMA node, processor core, physical package, processor group, processor die, and processor module). |

### `Buffer` [out, optional]

A pointer to a buffer that receives a sequence of variable-sized [SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-system_logical_processor_information_ex) structures. If the function fails, the contents of this buffer are undefined.

### `ReturnedLength` [in, out]

On input, specifies the length of the buffer pointed to by *Buffer*, in bytes. If the buffer is large enough to contain all of the data, this function succeeds and *ReturnedLength* is set to the number of bytes returned. If the buffer is not large enough to contain all of the data, the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INSUFFICIENT_BUFFER, and *ReturnedLength* is set to the buffer length required to contain all of the data. If the function fails with an error other than ERROR_INSUFFICIENT_BUFFER, the value of *ReturnedLength* is undefined.

## Return value

If the function succeeds, the return value is TRUE and at least one [SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-system_logical_processor_information_ex) structure is written to the output buffer.

If the function fails, the return value is FALSE. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

 If a 32-bit process running under WOW64 calls this function on a system with more than 64 processors, some of the processor affinity masks returned by the function may be incorrect. This is because the high-order **DWORD** of the 64-bit [KAFFINITY](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority) structure that represents all 64 processors is "folded" into a 32-bit **KAFFINITY** structure in the caller's buffer. As a result, the affinity masks for processors 32 through 63 are incorrectly represented as duplicates of the masks for processors 0 through 31. In addition, the affinity masks for processors 32 through 63 are incorrectly represented as duplicates of the masks for processors 0 through 31. In addition, the sum of all per-group **ActiveProcessorCount** and **MaximumProcessorCount** values reported in [PROCESSOR_GROUP_INFO](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-processor_group_info) structures may exclude some active logical processors.

When this function is called with a relationship type of **RelationProcessorCore**, it returns a [PROCESSOR_RELATIONSHIP](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-processor_relationship) structure for every active processor core in every processor group in the system. This is by design, because an unaffinitized 32-bit thread can run on any logical processor in a given group, including processors 32 through 63. A 32-bit caller can use the total count of **PROCESSOR_RELATIONSHIP** structures to determine the actual number of active processor cores on the system. However, the affinity of a 32-bit thread cannot be explicitly set to logical processor 32 through 63 of any processor group.

To compile an application that uses this function, set _WIN32_WINNT >= 0x0601. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

### Behavior starting with Windows Server 2022 (21H2, build 20348) ###

The behavior of this and other NUMA functions has been modified to better support systems with nodes containing more that 64 processors. For more information about this change, including information about enabling the old behavior of this API, see [NUMA Support](https://learn.microsoft.com/windows/win32/procthread/numa-support).

Requests for [RelationNumaNode](https://learn.microsoft.com/windows/win32/api/winnt/ne-winnt-logical_processor_relationship) will return [NUMA_NODE_RELATIONSHIP](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-numa_node_relationship) structures that contain only the affinity of the node within it's primary group. The [GroupCount](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-numa_node_relationship) value will be 1 and the structure size is fixed.

Requests for **RelationNumaNodeEx** or **RelationAll** will return **NUMA_NODE_RELATIONSHIP** structures that contain an array of affinities for the node over all groups. The **GroupCount** reports the number of affinities and the size of structure is variable.

## See also

[SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-system_logical_processor_information_ex)