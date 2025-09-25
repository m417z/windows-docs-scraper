# AtaPortRequestTimer function

## Description

The **AtaPortRequestTimer** routine requests a timer callback.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension` [in]

A pointer to the channel extension.

### `CallBackRoutine`

A pointer to the timer routine.

### `TimerValue` [in]

Time interval in units of microseconds.

## Return value

None

## Remarks

The **AtaPortRequestTimer** routine informs the ATA port driver that it must call the timer routine that is pointed to by *TimerRoutine* in the number of microseconds indicated by *TimerValue*.

The ATA port driver passes a pointer to the channel extension to the timer routine.

## See also

[AtaPortStallExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportstallexecution)