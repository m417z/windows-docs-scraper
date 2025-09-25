# AtaPortRequestWorkerRoutine function

## Description

The **AtaPortRequestWorkerRoutine** routine requests a worker routine.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension` [in]

A pointer to the channel extension.

### `CallBackRoutine`

A pointer of type IDE_HW_DPC to the worker routine to call.

## Return value

None

## Remarks

The miniport driver can request a worker routine to perform tasks that cannot be done in the interrupt service routine. Transferring operations to a worker routine is an effective way to keep the interrupt service routine as small as possible.

The worker routine is not synchronized with the interrupt.

When the port driver calls the worker routine, the port driver will pass the pointer to the channel extension that is stored in *ChannelExtension*.

The *WorkerRoutine* function pointer is declared in *Irb.h* as follows:

```
typedef
VOID
(*IDE_HW_DPC) (
  IN PVOID ChannelExtension
  );
```