# VideoPortInterlockedExchange function

## Description

The **VideoPortInterlockedExchange** function locks or unlocks a block of memory by setting a user-defined lock variable to **TRUE** or **FALSE**, respectively. It returns the previously-held value of the lock variable.

## Parameters

### `Target` [in, out]

Pointer to a user-defined lock variable that is used to control access to a memory buffer.

### `Value` [in]

Specifies the value to be stored in *Target*, which indicates whether the memory buffer is to be locked or unlocked. Use **TRUE** to lock the memory buffer, and **FALSE** to unlock the memory buffer.

## Return value

**VideoPortInterlockedExchange** returns the value that *Target* had prior to the function call.

## Remarks

**VideoPortInterlockedExchange** can be used to prevent DMA common-buffer contention in multiple-processor systems.

When the buffer is not being read from or written to, the lock variable should have a value of **FALSE**. A subsequent call to **VideoPortInterlockedExchange** with its *Target* parameter set to **TRUE** resets the lock variable to **TRUE**, after which this function returns **FALSE**. The buffer is now locked, preventing access by other threads. When the current operations on the buffer are complete, unlock the buffer with a call to **VideoPortInterlockedExchange** with its *Target* parameter set to **FALSE**.

## See also

[VideoPortGetCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetcommonbuffer)

[VideoPortInterlockedDecrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportinterlockeddecrement)

[VideoPortInterlockedIncrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportinterlockedincrement)