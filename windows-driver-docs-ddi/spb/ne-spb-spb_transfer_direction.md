# SPB_TRANSFER_DIRECTION enumeration

## Description

The **SPB_TRANSFER_DIRECTION** enumeration describes the direction (read or write) of a single transfer in an [I/O transfer sequence](https://learn.microsoft.com/windows-hardware/drivers/spb/i-o-transfer-sequences).

## Constants

### `SpbTransferDirectionNone`

The data transfer direction is undefined.

### `SpbTransferDirectionFromDevice`

The data transfer direction is from the device to system memory (read from device).

### `SpbTransferDirectionToDevice`

The data transfer direction is from system memory to the device (write to device).

### `SpbTransferDirectionMax`

Reserved for use by the operating system.

## Remarks

The values in this enumeration indicate the directions of the individual transfers in an I/O transfer sequence. The input buffer for an [IOCTL_SPB_EXECUTE_SEQUENCE](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_execute_sequence) I/O control request is an [SPB_TRANSFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_list) structure that specifies a list of transfers for the sequence. Each transfer is described by an [SPB_TRANSFER_LIST_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_list_entry) structure that contains the transfer parameters, which include the transfer direction. The transfer direction is **SpbTransferDirectionFromDevice** for a read operation, and is **SpbTransferDirectionToDevice** for a write operation.

Your SPB controller driver can call the [SpbRequestGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbrequestgetparameters) method to retrieve a set of SPB-specific parameters from an I/O request. One of these parameters is an **SPB_TRANSFER_DIRECTION** enumeration value that indicates the transfer direction of the previous I/O request. The SPB controller driver can use this direction value to determine whether the current read or write ([IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read) or [IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)) request requires a change in transfer direction on the bus.

In addition, **SpbRequestGetParameters** retrieves a position value that indicates the relative position of a read or write request in the list of transfers for the multiple-request sequence. If a read request or a write request has a position value of **SpbRequestSequencePositionSingle** or **SpbRequestSequencePositionFirst**, the direction value for the previous transfer is **SpbTransferDirectionNone** (that is, there is no previous transfer direction). For a read or write request that has a position value of **SpbRequestSequencePositionMiddle** or **SpbRequestSequencePositionLast**, the direction value indicates whether the previous transfer was a read or a write. For an unlock ([IOCTL_SPB_UNLOCK_CONTROLLER](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_unlock_controller-control-code)) request, which has a position value of **SpbRequestSequencePositionLast**, the direction value indicates whether the last transfer in the sequence was a read or a write.

A lock ([IOCTL_SPB_LOCK_CONTROLLER](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_lock_controller-control-code)) request has no previous direction. Similarly, an I/O control request that is passed to the [EvtSpbControllerIoOther](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_other) callback function has no previous direction. For either of these requests, the previous direction value retrieved by **SpbRequestGetParameters** is **SpbTransferDirectionNone**.

## See also

- [EvtSpbControllerIoOther](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_other)
- [IOCTL_SPB_EXECUTE_SEQUENCE](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_execute_sequence)
- [IOCTL_SPB_LOCK_CONTROLLER](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_lock_controller-control-code)
- [IOCTL_SPB_UNLOCK_CONTROLLER](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_unlock_controller-control-code)
- [IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read)
- [IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)
- [SPB_TRANSFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_list)
- [SPB_TRANSFER_LIST_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_list_entry)
- [SpbRequestGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbrequestgetparameters)