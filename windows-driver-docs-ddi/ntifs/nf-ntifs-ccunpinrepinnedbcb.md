# CcUnpinRepinnedBcb function

## Description

The **CcUnpinRepinnedBcb** routine unpins a repinned buffer control block (BCB).

## Parameters

### `Bcb` [in]

Pointer to the repinned BCB.

### `WriteThrough` [in]

Set to **TRUE** if the BCB should be written through.

### `IoStatus` [out]

Pointer to an IO_STATUS_BLOCK structure. If the call to **CcUnpinRepinnedBcb** succeeds, *IoStatus.Status* is set to STATUS_SUCCESS. Otherwise, it is set to an appropriate NTSTATUS error code. *IoStatus.Information* is set to the actual number of bytes that were successfully flushed to disk.

## Remarks

File systems call **CcUnpinRepinnedBcb** to write a previously pinned buffer through to disk.

Every call to [CcRepinBcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccrepinbcb) must be matched by a subsequent call to **CcUnpinRepinnedBcb**.

Because **CcUnpinRepinnedBcb** acquires the BCB resource exclusively, the caller must be extremely careful to avoid deadlocks. If possible, the caller should own no resources. Otherwise the caller must guarantee that it has nothing else pinned in the same cached file. Normally **CcUnpinRepinnedBcb** is called during request completion, after all other resources have been released.

**CcUnpinRepinnedBcb** synchronously writes the buffer (for write-through requests) and unpins the BCB repinned by the earlier call to [CcRepinBcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccrepinbcb).

## See also

[CcRepinBcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccrepinbcb)