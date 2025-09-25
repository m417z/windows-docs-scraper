# MINIDUMP_MEMORY_DESCRIPTOR64 structure

## Description

Describes a range of memory.

## Members

### `StartOfMemoryRange`

The starting address of the memory range.

### `DataSize`

The size of the memory range.

## Remarks

**MINIDUMP_MEMORY_DESCRIPTOR64** is used for full-memory minidumps where all of the raw memory is sequential at the end of the minidump. There is no need for individual relative virtual addresses (RVAs), because the RVA is the base RVA plus the sum of the preceding data blocks. The **MINIDUMP_MEMORY_DESCRIPTOR64** structure is defined as follows.

```cpp

typedef struct _MINIDUMP_MEMORY_DESCRIPTOR64 {
    ULONG64 StartOfMemoryRange;
    ULONG64 DataSize;
} MINIDUMP_MEMORY_DESCRIPTOR64, *PMINIDUMP_MEMORY_DESCRIPTOR64;
```

## See also

[MINIDUMP_LOCATION_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_location_descriptor)