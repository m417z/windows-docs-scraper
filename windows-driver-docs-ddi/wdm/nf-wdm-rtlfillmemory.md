## Description

The **RtlFillMemory** routine fills a block of memory with the specified fill value.

## Parameters

### `Destination` [out]

A pointer to the block of memory to be filled.

### `Length` [in]

The number of bytes in the block of memory to be filled.

### `Fill` [in]

The value to fill the destination memory block with. This value is copied to every byte in the memory block that is defined by *Destination* and *Length*.

## Syntax

```cpp
void RtlFillMemory(
   void*  Destination,
   size_t Length
   int    Fill
);
```

## Remarks

Callers of **RtlFillMemory** can be running at any IRQL if the destination memory block is in nonpaged system memory. Otherwise, the caller must be running at IRQL <= APC_LEVEL.

## See also

[RtlZeroMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlzeromemory)