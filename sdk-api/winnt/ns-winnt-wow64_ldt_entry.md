# WOW64_LDT_ENTRY structure

## Description

Describes an entry in the descriptor table for a 32-bit thread on a 64-bit system. This structure is valid only on 64-bit systems.

## Members

### `LimitLow`

The low-order part of the address of the last byte in the segment.

### `BaseLow`

The low-order part of the base address of the segment.

### `HighWord`

The high-order portion of the descriptor. This member may be interpreted as bytes or collections of bits, depending on the level of detail required.

### `HighWord.Bytes`

### `HighWord.Bytes.BaseMid`

Middle bits (16–23) of the base address of the segment.

### `HighWord.Bytes.Flags1`

Values of the **Type**, **Dpl**, and **Pres** members in the **Bits** structure.

### `HighWord.Bytes.Flags2`

Values of the **LimitHi**, **Sys**, **Reserved_0**, **Default_Big**, and **Granularity** members in the **Bits** structure.

### `HighWord.Bytes.BaseHi`

High bits (24–31) of the base address of the segment.

### `HighWord.Bits`

### `HighWord.Bits.BaseMid`

The middle bits (16–23) of the base address of the segment.

### `HighWord.Bits.Type`

The type of segment. This member can be one of the following values:

### `HighWord.Bits.Dpl`

The privilege level of the descriptor. This member is an integer value in the range 0 (most privileged) through 3 (least privileged).

### `HighWord.Bits.Pres`

The present flag. This member is 1 if the segment is present in physical memory or 0 if it is not.

### `HighWord.Bits.LimitHi`

The high bits (16–19) of the address of the last byte in the segment.

### `HighWord.Bits.Sys`

The space that is available to system programmers. This member might be used for marking segments in some system-specific way.

### `HighWord.Bits.Reserved_0`

Reserved.

### `HighWord.Bits.Default_Big`

The size of segment. If the segment is a data segment, this member contains 1 if the segment is larger than 64 kilobytes (KB) or 0 if the segment is smaller than or equal to 64 KB.

If the segment is a code segment, this member contains 1. The segment runs with the default (native mode) instruction set.

### `HighWord.Bits.Granularity`

The granularity. This member contains 0 if the segment is byte granular, 1 if the segment is page granular.

### `HighWord.Bits.BaseHi`

The high bits (24–31) of the base address of the segment.

## Remarks

The
[Wow64GetThreadSelectorEntry](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-wow64getthreadselectorentry) function fills this structure with information from an entry in the descriptor table. You can use this information to convert a segment-relative address to a linear virtual address.

The base address of a segment is the address of offset 0 in the segment. To calculate this value, combine the **BaseLow**, **BaseMid**, and **BaseHi** members.

The limit of a segment is the address of the last byte that can be addressed in the segment. To calculate this value, combine the **LimitLow** and **LimitHi** members.

The **WOW64_LDT_ENTRY** structure has the same layout for a 64-bit process as the [LDT_ENTRY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ldt_entry) structure has for a 32-bit process.

## See also

[Debugging Structures](https://learn.microsoft.com/windows/desktop/Debug/debugging-structures)

[Wow64GetThreadSelectorEntry](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-wow64getthreadselectorentry)