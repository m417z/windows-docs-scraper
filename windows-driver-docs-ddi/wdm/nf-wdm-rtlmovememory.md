## Description

The **RtlMoveMemory** routine copies the contents of a source memory block to a destination memory block, and supports overlapping source and destination memory blocks.

## Parameters

### `Destination` [out]

A pointer to the destination memory block to copy the bytes to.

### `Source` [in]

A pointer to the source memory block to copy the bytes from.

### `Length` [in]

The number of bytes to copy from the source to the destination.

## Syntax

```cpp
void RtlMoveMemory(
   void*       Destination,
   const void* Source,
   size_t      Length
);
```

## Remarks

The source memory block, which is defined by *Source* and *Length*, can overlap the destination memory block, which is defined by *Destination* and *Length*.

The [RtlCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory) routine runs faster than **RtlMoveMemory**, but **RtlCopyMemory** requires that the source and destination memory blocks do not overlap.

Callers of **RtlMoveMemory** can be running at any IRQL if the source and destination memory blocks are in nonpaged system memory. Otherwise, the caller must be running at IRQL <= APC_LEVEL.

## See also

[RtlCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory)