# NdisFillMemory macro

## Description

The
**NdisFillMemory** function fills a caller-supplied buffer with the given character.

## Parameters

### `Destination` [in]

A pointer to the buffer to be filled.

### `Length` [in]

The number of bytes to be filled.

### `Fill` [in]

The value to fill the buffer.

## Remarks

Callers of
**NdisFillMemory** can be running at any IRQL, provided that the
*Destination* buffer is resident. If the buffer is pageable, a caller must be running at IRQL <
DISPATCH_LEVEL.

## See also

[RtlEqualMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlequalmemory)

[RtlZeroMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlzeromemory)