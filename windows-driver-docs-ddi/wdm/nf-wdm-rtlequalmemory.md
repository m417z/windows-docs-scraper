## Description

The **RtlEqualMemory** routine compares two blocks of memory to determine whether the specified number of bytes are identical.

## Parameters

### `Destination`

A pointer to a caller-allocated block of memory to compare.

### `Source`

A pointer to a caller-allocated block of memory that is compared to the block of memory to which *Source1* points.

### `Length`

Specifies the number of bytes to be compared.

## Syntax

```cpp
BOOL WINAPI
RtlEqualMemory(
   [in] void*  Destination,
   [in] void*  Source,
   [in] size_t Length
);
```

## Return value

**RtlEqualMemory** returns TRUE if Source1 and Source2 are equivalent; otherwise, it returns FALSE.

## Remarks

**RtlEqualMemory** begins the comparison with byte zero of each block.

Callers of **RtlEqualMemory** can be running at any IRQL if both blocks of memory are resident.

## See also

[RtlCompareMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcomparememory)