# AtaPortRequestSynchronizedRoutine function

## Description

The **AtaPortRequestSynchronizedRoutine** routine is used by the miniport driver to request synchronization with the interrupt service routine (ISR).

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension` [in]

A pointer to the channel extension.

### `CallBackRoutine`

A pointer to the routine to call.

## Return value

None

## Remarks

This routine is typically used by miniport drivers that set the **SyncWithIsr** member of the [IDE_CHANNEL_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_channel_configuration) structure to **FALSE**. When **SyncWithIsr** is set to **FALSE**, the miniport driver should use the **AtaPortRequestSynchronizedRoutine** routine to ensure synchronized access to data structures that are modified in the ISR.

The pointer to the channel extension that is stored in *ChannelExtension* will be passed to the worker routine when it is called.

When the port driver calls the routine that is pointed to by *SynchronizedRoutine*, it passes the pointer to the channel extension that is stored in *ChannelExtension*.

The *SynchronizedRoutine* function pointer is declared in *Irb.h* as follows:

```
typedef
VOID
(*IDE_HW_DPC) (
  IN PVOID ChannelExtension
  );
```

## See also

[AtaPortControllerSyncRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportcontrollersyncroutine)