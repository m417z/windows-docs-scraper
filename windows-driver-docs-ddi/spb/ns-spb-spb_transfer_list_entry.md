# SPB_TRANSFER_LIST_ENTRY structure

## Description

The **SPB_TRANSFER_LIST_ENTRY** structure describes a single transfer in an [I/O transfer sequence](https://learn.microsoft.com/windows-hardware/drivers/spb/i-o-transfer-sequences).

## Members

### `Direction`

The direction of the transfer. This member is set to one of the following [SPB_TRANSFER_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ne-spb-spb_transfer_direction) enumeration values:

- **SpbTransferDirectionFromDevice**
- **SpbTransferDirectionToDevice**

### `DelayInUs`

An optional delay, in microseconds, before this transfer begins. For more information, see the description of the **DelayInUs** member in [SPB_TRANSFER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/ns-spbcx-spb_transfer_descriptor).

### `Buffer`

The buffer for this transfer. This member uses one of the following buffer formats: simple buffer, scatter-gather list, or (for kernel-mode clients) MDL. For more information about buffer formats, see [SPB_TRANSFER_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_buffer).

## Remarks

To request an I/O transfer sequence for a target device on the bus, a client (peripheral driver) of the SPB controller driver sends an [IOCTL_SPB_EXECUTE_SEQUENCE](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_execute_sequence) request that describes the sequence. The transfers in the sequence are described by an [SPB_TRANSFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_list) structure that is followed by an array of one or more **SPB_TRANSFER_LIST_ENTRY** structures. Each element in this array describes an individual transfer in the sequence.

## See also

- [IOCTL_SPB_EXECUTE_SEQUENCE](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_execute_sequence)
- [SPB_TRANSFER_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_buffer)
- [SPB_TRANSFER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/ns-spbcx-spb_transfer_descriptor)
- [SPB_TRANSFER_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ne-spb-spb_transfer_direction)
- [SPB_TRANSFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_list)