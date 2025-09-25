# PERF_INSTANCE_DEFINITION structure

## Description

Describes an instance of a performance object.

## Members

### `ByteLength`

Size of this structure, including the instance name that follows, in bytes. This value must be an 8-byte multiple.

### `ParentObjectTitleIndex`

Index of the name of the parent object in the title database. For example, if the object is a thread, the parent object is a process, or if the object is a logical drive, the parent is a physical drive.

### `ParentObjectInstance`

Position of the instance within the parent object that is associated with this instance. The position is zero-based.

### `UniqueID`

A unique identifier that you can use to identify the instance instead of
using the name to identify
the instance. If you do not use unique identifiers to distinguish the counter instances, set this member to PERF_NO_UNIQUE_ID.

### `NameOffset`

Offset from the beginning of this structure to the Unicode name of this instance.

### `NameLength`

Length of the instance name, including the null-terminator, in bytes. This member is zero if the instance does not have a name.

Do not include in the length any padding that you added to the instance name to ensure that **ByteLength** is aligned to an 8-byte boundary.

## Remarks

The object contains instances if the **NumInstances** member of [PERF_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_object_type) is greater than zero. Use the **DefinitionLength** member of **PERF_OBJECT_TYPE** to find the first instance of the object. For details, see [Performance Data Format](https://learn.microsoft.com/windows/desktop/PerfCtrs/performance-data-format).

Consumers should use the parent instance name, if specified, to create a full instance name that is used for display. The convention is to form the name as parent/child.

Providers should use unique instance names. If you do not, it makes it difficult for consumers to calculate and display performance values because they cannot tell if the current instance refers to the same instance that was queried previously (instances can come and go).

Providers must allocate enough space for the instance name to ensure that **ByteLength** is aligned to an 8-byte boundary.

## See also

[PERF_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/winperf/ns-winperf-perf_object_type)