# MmMapMemoryDumpMdlEx function

## Description

The **MmMapMemoryDumpMdlEx** function maps an MDL into a specified virtual address.

Only one MDL can be mapped at a time. For use by crash dump, hibernate and live dump routines only.

## Parameters

### `Va`

Supplies the VA to map.

### `PageTotal`

Supplies the total number of pages in the VA range.

### `MemoryDumpMdl`

Supplies the MDL to map.

### `Flags`

Supplies **MM_DUMP_MAP_INVALIDATE** to indicate the mapping PTEs should be zeroed and the local TB flushed.

## Return value

This function returns NTSTATUS.

## Remarks

## See also