## Description

The **KeQueryLogicalProcessorRelationship** routine gets information about the relationships of one or more processors to the other processors in a multiprocessor system.

## Parameters

### `ProcessorNumber` [in, optional]

A pointer to a [PROCESSOR_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_processor_number) structure that identifies the logical processor for which the caller requests relationship information. To request information about all logical processors in the system, set this parameter to **NULL**.

### `RelationshipType` [in]

Specifies the type of relationship information that is requested by the caller. Set this parameter to one of the following [LOGICAL_PROCESSOR_RELATIONSHIP](https://learn.microsoft.com/windows/win32/api/winnt/ne-winnt-logical_processor_relationship) enumeration values:

- **RelationProcessorCore**

- **RelationNumaNode**
Starting in Windows Server 2022, each NUMA node is assigned a primary group. Requests for **RelationNumaNode** will return **RelationNumaNode** structures that contain only a single group affinity, that of the node's primary group if a processor number is not specified, that of the group containing the given processor if a processor number is specified (GroupCount == 1, size of structure is unchanged). For more info, see [**KeQueryNodeActiveAffinity**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerynodeactiveaffinity) and [NUMA Support](https://learn.microsoft.com/windows/win32/procthread/numa-support).

- **RelationCache**

- **RelationProcessorPackage**

- **RelationGroup**

- **RelationProcessorDie**

- **RelationNumaNodeEx**

- **RelationAll**

 Starting in Windows Server 2022, requests for **RelationNumaNodeEx** or **RelationAll** will return **RelationNumaNode** structures that contain an array of affinities for the node over all groups (GroupCount reports number of affinities, size of structure is variable). For more info, see [NUMA Support](https://learn.microsoft.com/windows/win32/procthread/numa-support).

### `Information` [out, optional]

A pointer to a caller-allocated buffer into which the routine writes an array of one or more [SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-system_logical_processor_information_ex) structures that contain the information requested by the caller. If the function fails, the contents of this buffer are undefined. Set *Information* = **NULL** to obtain the required buffer length before you allocate the buffer. For more information, see the following Remarks section.

### `Length` [in, out]

A pointer to a location that contains the size, in bytes, of the buffer that is pointed to by *Information*. On entry, **Length* contains the size of the caller-allocated buffer that is pointed to by *Information*. During the call, the routine overwrites the value that is pointed to by *Length* with the buffer size that is required to contain the requested relationship information.

## Return value

**KeQueryLogicalProcessorRelationship** returns STATUS_SUCCESS if the call is successful. Possible error return values include the following:

| Return code | Description |
|---|---|
| **STATUS_INVALID_PARAMETER** | The *ProcessorNumber* parameter points to a PROCESSOR_NUMBER structure that contains invalid information. |
| **STATUS_INFO_LENGTH_MISMATCH** | The caller-allocated buffer that is pointed to by the *Information* parameter is not large enough to contain the requested relationship information. |

## Remarks

To determine the buffer size to allocate, initially call **KeQueryLogicalProcessorRelationship** with *Information* = **NULL** and **Length* = 0. In response, the routine writes the required buffer size to**Length* and returns STATUS_INFO_LENGTH_MISMATCH. Next, allocate a buffer of the required size and call **KeQueryLogicalProcessorRelationship** a second time. In this second call, set *Information* to the buffer address and **Length* to the buffer size. If the second call succeeds, the routine writes the requested relationship information to the buffer and returns STATUS_SUCCESS.

### Examples

The following code example gets processor relationship information for all the logical processors in a multiprocessor system:

```cpp
//
// Get required buffer size.
//
NTSTATUS Status;
PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX Info = NULL;
ULONG BufferSize = 0;
Status = KeQueryLogicalProcessorRelationship(NULL, RelationAll, NULL, &BufferSize);

NT_ASSERT(Status == STATUS_INFO_LENGTH_MISMATCH && BufferSize > 0);

//
// Allocate buffer (assume IRQL <= APC_LEVEL).
//
Info = ExAllocatePoolWithTag(PagedPool, BufferSize, ' gaT');
if (Info == NULL)
{
    Status = STATUS_INSUFFICIENT_RESOURCES;
}

//
// Get processor relationship information.
//
if (NT_SUCCESS(Status))
{
    Status = KeQueryLogicalProcessorRelationship(NULL, RelationAll, Info, &BufferSize);
}
```

The NT_ASSERT macro is defined in the Wdm.h header file. The NT_SUCCESS macro is defined in the Ntdef.h header file.

## See also

[LOGICAL_PROCESSOR_RELATIONSHIP](https://learn.microsoft.com/windows/win32/api/winnt/ne-winnt-logical_processor_relationship)

[PROCESSOR_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_processor_number)

[SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-system_logical_processor_information_ex)