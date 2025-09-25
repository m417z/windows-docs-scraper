# MINIDUMP_LOCATION_DESCRIPTOR structure

## Description

Contains information describing the location of a data stream within a minidump file.

## Members

### `DataSize`

The size of the data stream, in bytes.

### `Rva`

The relative virtual address (RVA) of the data. This is the byte offset of the data stream from the beginning of the minidump file.

## Remarks

In this context, a data stream refers to a block of data within a minidump file.

This structure uses 32-bit locations for RVAs in the first 4GB and 64-bit locations are used for larger RVAs. The **MINIDUMP_LOCATION_DESCRIPTOR64** structure is defined as follows.

```cpp

typedef struct _MINIDUMP_LOCATION_DESCRIPTOR64 {
  ULONG64 DataSize;
  RVA64 Rva;
} MINIDUMP_LOCATION_DESCRIPTOR64;
```

## See also

[MINIDUMP_DIRECTORY](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_directory)

[MINIDUMP_EXCEPTION_STREAM](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_exception_stream)

[MINIDUMP_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_memory_descriptor)