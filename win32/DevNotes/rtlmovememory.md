# RtlMoveMemory function

Copies the contents of a source memory block to a destination memory block, and supports overlapping source and destination memory blocks.

## Parameters

*Destination* \[out\]

A pointer to the destination memory block to copy the bytes to.

*Source* \[in\]

A pointer to the source memory block to copy the bytes from.

*Length* \[in\]

The number of bytes to copy from the source to the destination.

## Return value

None

## Remarks

The source memory block, which is defined by *Source* and *Length*, can overlap the destination memory block, which is defined by *Destination* and *Length*.

The [**RtlCopyMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory) routine runs faster than **RtlMoveMemory**, but **RtlCopyMemory** requires that the source and destination memory blocks do not overlap.

Callers of **RtlMoveMemory** can be running at any IRQL if the source and destination memory blocks are in nonpaged system memory. Otherwise, the caller must be running at IRQL <= APC\_LEVEL.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Target platform<br> | [Universal](https://msdn.microsoft.com/Library/Windows/Hardware/EB2264A4-BAE8-446B-B9A5-19893936DDCA) |
| Header<br> | Wdm.h (include Wdm.h, Ntddk.h, or Ntifs.h) |
| Library<br> | Ntdll.lib |
| DLL<br> | Ntdll.dll |

## See also

[**RtlCopyMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory)

