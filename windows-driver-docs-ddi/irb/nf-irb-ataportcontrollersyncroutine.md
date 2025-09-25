# AtaPortControllerSyncRoutine function

## Description

The **AtaPortControllerSyncRoutine** routine provides synchronized access to data structures that are shared across all channels on a controller.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension` [in]

A pointer to the channel extension.

### `CallBackRoutine`

A pointer to the routine to call.

## Return value

None

## Remarks

The miniport driver uses this routine to synchronize access to data structures that are shared across channels on a controller. The miniport driver, however, should use this routine very sparingly.

The *ControllerSyncRoutine* function pointer is declared in *Irb.h* as follows:

```
typedef
VOID
(*IDE_HW_DPC) (
  IN PVOID ChannelExtension
  );
```

## See also

[AtaPortRequestSynchronizedRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportrequestsynchronizedroutine)