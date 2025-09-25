## Description

The **RtlCopyMemory** routine copies the contents of a source memory block to a destination memory block.

## Parameters

### `Destination` [out]

A pointer to the destination memory block to copy the bytes to.

### `Source` [in]

A pointer to the source memory block to copy the bytes from.

### `Length` [in]

The number of bytes to copy from the source to the destination.

## Syntax

```cpp
void RtlCopyMemory(
   void*       Destination,
   const void* Source,
   size_t      Length
);
```

## Remarks

**RtlCopyMemory** runs faster than **RtlMoveMemory**. However, **RtlCopyMemory** requires that the source memory block, which is defined by *Source* and *Length*, cannot overlap the destination memory block, which is defined by *Destination* and *Length*. In contrast, **RtlMoveMemory** correctly handles the case in which the source and destination memory blocks overlap.

New drivers should use the **RtlCopyMemory** routine instead of **RtlCopyBytes**.

Callers of **RtlCopyMemory** can be running at any IRQL if the source and destination memory blocks are in nonpaged system memory. Otherwise, the caller must be running at IRQL <= APC_LEVEL.

## See also

[RtlMoveMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlmovememory)