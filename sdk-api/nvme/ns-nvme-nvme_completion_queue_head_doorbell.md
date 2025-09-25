# NVME_COMPLETION_QUEUE_HEAD_DOORBELL structure

## Description

Defines the doorbell register that updates the Head entry pointer for Completion Queue *y*.

The value of *y* is equivalent to the Queue Identifier, the 16-bit ID value that is assigned to the queue when it is created, this value indicates Completion Queue entries that have been processed by host software.

The Offset of the Completion Queue *y* Head Doorbell (CQyHDBL) is: `(1000h + ((2y + 1) * (4 << CAP.DSTRD)))`

Where `CAP.DSTRD` is the value of the **DSTRD** field in [NVME_CONTROLLER_CAPABILITIES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_capabilities).

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.CQH`

A Read/Write field that indicates the new value of the Completion Queue Head entry pointer.

This value will overwrite any previously provided Completion Queue Head (**CQH**) value. The difference between the last **CQH** write and the current **CQH** entry pointer write indicates the number of entries that are now available for re-use by the controller in the Completion Queue.

> [!NOTE]
> Completion Queue rollover must be accounted for.

### `DUMMYSTRUCTNAME.Reserved0`

A Read Only reserved field.

### `AsUlong`

## Remarks

The host should not read the doorbell registers. If a doorbell register is read, the value returned is vendor specific. Writing to a non-existent Completion Queue Head Doorbell has undefined results.

Host software should continue to process completion queue entries within Completion Queues regardless of whether there are entries available in any Submission Queue.

## See also