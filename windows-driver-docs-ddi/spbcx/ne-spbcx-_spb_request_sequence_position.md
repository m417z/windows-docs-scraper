# _SPB_REQUEST_SEQUENCE_POSITION enumeration

## Description

The **SPB_REQUEST_SEQUENCE_POSITION** enumeration indicates the position of an I/O request in the list of transfers for an [I/O transfer sequence](https://learn.microsoft.com/windows-hardware/drivers/spb/i-o-transfer-sequences).

## Constants

### `SpbRequestSequencePositionInvalid`

For internal use only.

### `SpbRequestSequencePositionSingle`

A single-transfer I/O request. This request is either a read or write ([IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read) or [IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)) request that is not part of a sequence, or it is an [IOCTL_SPB_EXECUTE_SEQUENCE](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_execute_sequence) I/O control request for a sequence that consists of a single transfer.

The controller should select the target before performing the transfer, and release the target after the transfer finishes.

### `SpbRequestSequencePositionFirst`

The first I/O request in a sequence. This request is the read or write request that immediately follows the lock ([IOCTL_SPB_LOCK_CONTROLLER](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_lock_controller-control-code)) I/O control request that signals the start of the sequence.

The controller should select the target before performing this transfer, and the target should remain selected after the transfer finishes.

### `SpbRequestSequencePositionContinue`

An I/O request in the middle of a sequence. This request is a read or write request that is neither the first nor the last transfer in the sequence.

In some cases, the SPB framework extension (SpbCx) cannot identify the last transfer and labels the last transfer as **SpbRequestSequencePositionContinue** instead of **SpbRequestSequencePositionLast**. For more information, see the following Remarks section.

The controller should already have the target selected before it starts this transfer, and the target should remain selected after the transfer finishes.

### `SpbRequestSequencePositionLast`

The last I/O request in a sequence. This request is the read or write request that immediately precedes the unlock ([IOCTL_SPB_UNLOCK_CONTROLLER](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_unlock_controller-control-code)) I/O control request that signals the end of the sequence.

In some cases, SpbCx cannot identify the last transfer and labels the last transfer as **SpbRequestSequencePositionContinue** instead of **SpbRequestSequencePositionLast**. For more information, see the following Remarks section.

The controller should already have the target selected before it starts this transfer, and should release the target after the transfer finishes.

### `SpbRequestSequencePositionMax`

For internal use only.

## Remarks

A client (peripheral driver) of the SPB controller can perform an I/O transfer sequence by sending a series of read and write requests to a target device on the bus. Each read or write request in the series occupies a position in the list of transfers for the sequence. The values in the **SPB_REQUEST_SEQUENCE_POSITION** enumeration indicate the relative positions of the read and write requests in this list.

The [SpbRequestGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbrequestgetparameters) method retrieves the SPB-specific parameter values from an I/O request and writes them to an [SPB_REQUEST_PARAMETERS](https://learn.microsoft.com/previous-versions/hh406209(v=vs.85)) structure. Included in these parameters is an **SPB_REQUEST_SEQUENCE_POSITION** enumeration value that indicates the position of the I/O request in the I/O transfer sequence of which it is part.

If **SpbRequestGetParameters** is called to retrieve the position value of an I/O request that is not a part of a sequence, this method assigns an appropriate **SPB_REQUEST_SEQUENCE_POSITION** enumeration value to the request.

For read and write requests, the position value is set to one of the following values: **SpbRequestSequencePositionSingle**, **SpbRequestSequencePositionFirst**, **SpbRequestSequencePositionContinue**, or **SpbRequestSequencePositionLast**.

If the client sends a simple read or write (**IRP_MJ_READ** or **IRP_MJ_WRITE**) request that is not part of a sequence, the position value is set to **SpbRequestSequencePositionSingle**.

If the client sends a lock (**IOCTL_SPB_LOCK_CONTROLLER**) request to signal the start of a sequence, the position value for the first transfer (read or write request) in the sequence is **SpbRequestSequencePositionFirst**, and the position value for the remaining transfers in the sequence is **SpbRequestSequencePositionContinue**. In this case, SpbCx cannot assign **SpbRequestSequencePositionLast** to the last transfer because it does not know that the client has sent the last read or write request until the client sends the unlock (**IOCTL_SPB_UNLOCK_CONTROLLER**) request that ends the sequence.

For lock requests, the position value is set to **SpbRequestSequencePositionFirst**. For unlock requests, the position value is set to **SpbRequestSequencePositionLast**.

Some controllers might support special operations, such as full-duplex bus transfers that simultaneously read from and write to a target device. A client can perform a custom sequence operation by locking the controller and sending a series of custom I/O requests, which SpbCx passes to the SPB controller driver's [EvtSpbControllerIoOther](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_other) callback function. In this case, the position value for the first custom I/O request in the sequence is **SpbRequestSequencePositionFirst**, and the position value for the remaining custom I/O requests in the sequence is **SpbRequestSequencePositionContinue**. The sequence ends when the client unlocks the controller. If the *EvtSpbControllerIoOther* callback function receives a custom I/O request that is not part of a sequence, the position value for this request is **SpbRequestSequencePositionSingle**.

For a position value of **SpbRequestSequencePositionLast**, the **Length** member of the **SPB_REQUEST_PARAMETERS** structure can be 0 to indicate that the target should simply be released and that no I/O data should be transferred (or, equivalently, to indicate that a 0-byte transfer should occur, if the controller cannot release the device without running the clock).

For position values of **SpbRequestSequencePositionContinue** and **SpbRequestSequencePositionLast**, the transfer direction might have changed from the previous transfer and the SPB controller driver might need to indicate this possible direction change on the bus (for example, an I2C controller issues a new START condition). For more information about transfer directions, see [SPB_TRANSFER_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ne-spb-spb_transfer_direction).

## See also

* [EvtSpbControllerIoSequence](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_sequence)
* [IOCTL_SPB_LOCK_CONTROLLER](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_lock_controller-control-code)
* [IOCTL_SPB_UNLOCK_CONTROLLER](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_unlock_controller-control-code)
* [IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read)
* [IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)
* [SPB_REQUEST_PARAMETERS](https://learn.microsoft.com/previous-versions/hh406209(v=vs.85))
* [SPB_TRANSFER_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ne-spb-spb_transfer_direction)
* [SpbRequestGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbrequestgetparameters)