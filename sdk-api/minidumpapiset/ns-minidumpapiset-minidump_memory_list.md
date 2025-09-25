# MINIDUMP_MEMORY_LIST structure

## Description

Contains a list of memory ranges.

## Members

### `NumberOfMemoryRanges`

The number of structures in the **MemoryRanges** array.

### `MemoryRanges`

An array of
[MINIDUMP_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_memory_descriptor) structures.

## Remarks

The **MINIDUMP_MEMORY64_LIST** structure is defined as follows. It is used for full-memory minidumps.

```cpp

typedef struct _MINIDUMP_MEMORY64_LIST {
    ULONG64 NumberOfMemoryRanges;
    RVA64 BaseRva;
    MINIDUMP_MEMORY_DESCRIPTOR64 MemoryRanges [0];
} MINIDUMP_MEMORY64_LIST, *PMINIDUMP_MEMORY64_LIST;
```

Note that **BaseRva** is the overall base RVA for the memory list. To locate the data for a particular descriptor, start at **BaseRva** and increment by the size of a descriptor until you reach the descriptor.

## See also

[MINIDUMP_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_memory_descriptor)

[MINIDUMP_STREAM_TYPE](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-minidump_stream_type)