# DXGK_KSR_MEMORY_RANGE structure

## Description

The kernel soft reboot (KSR) memory range.

## Members

### `MemoryRangeDesc`

Provides a description of the memory range.

Bits 0-39: Physical page number of the first page. This is the physical page address shifted 12 bits right.

Bits 40-63: Number of pages.

## Remarks

## See also