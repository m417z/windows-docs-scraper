# VideoPortInterlockedDecrement function

## Description

The **VideoPortInterlockedDecrement** function decrements a caller-supplied variable as an atomic operation.

## Parameters

### `Addend` [in]

Pointer to the variable to be decremented.

## Return value

**VideoPortInterlockedDecrement** returns the decremented value.

## Remarks

When possible and whenever appropriate, **VideoPortInterlockedDecrement** is implemented inline by the compiler. It can be safely used on pageable data.

This function is atomic only with respect to other **VideoPortInterlocked***Xxx* calls.

## See also

[VideoPortInterlockedExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportinterlockedexchange)

[VideoPortInterlockedIncrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportinterlockedincrement)