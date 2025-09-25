# NVME_COMPLETION_QUEUE_HEAD_DOORBELL structure

## Description

Defines the doorbell register that updates the Tail entry pointer for Submission Queue *y*.

The value of *y* is equivalent to the Queue Identifier, the 16-bit ID value that is assigned to the queue when it is created, this value indicates to the controller that new commands have been submitted for processing.

The Offset of the Submission Queue *y* Tail Doorbell (CQyHDBL) is: `(1000h + ((2y) * (4 << CAP.DSTRD)))`

Where `CAP.DSTRD` is the value of the **DSTRD** field in [NVME_CONTROLLER_CAPABILITIES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_capabilities).

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.SQT`

A Read/Write field that indicates the new value of the Submission Queue Tail entry pointer.

This value will overwrite any previously provided Submission Queue Tail (**SQT**) value. The difference between the last **SQT** write and the current **SQT** write indicates the number of commands added to the Submission Queue.

> [!NOTE]
> Submission Queue rollover must be accounted for.

### `DUMMYSTRUCTNAME.Reserved0`

A Read Only reserved field.

### `AsUlong`

## Remarks

The host should not read the doorbell registers. If a doorbell register is read, the value returned is vendor specific. Writing to a non-existent Submission Queue Tail Doorbell has undefined results.

## See also