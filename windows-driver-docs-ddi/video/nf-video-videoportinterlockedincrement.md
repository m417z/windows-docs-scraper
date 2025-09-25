# VideoPortInterlockedIncrement function

## Description

The **VideoPortInterlockedIncrement** function increments a caller-supplied variable as an atomic operation.

## Parameters

### `Addend` [in]

Pointer to the variable to be incremented.

## Return value

**VideoPortInterlockedIncrement** returns the incremented value.

## Remarks

When possible and whenever appropriate, **VideoPortInterlockedIncrement** is implemented inline by the compiler. It can be safely used on pageable data.

This function is atomic only with respect to other **VideoPortInterlocked***Xxx* calls.

## See also

[VideoPortInterlockedDecrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportinterlockeddecrement)

[VideoPortInterlockedExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportinterlockedexchange)