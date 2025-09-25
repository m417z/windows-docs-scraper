# _IRB_REQ_SEND_PHY_PACKET structure

## Description

This structure contains the fields necessary to carry out a SendPhyPacket request.

## Members

### `Flags`

Specifies any nondefault settings for this operation. Set to ASYNC_FLAGS_NO_STATUS to always return success from the send PHY packet operation, regardless of whether the send PHY packet succeeds or fails.

### `GenerationCount`

Specifies the bus reset generation as known by the device driver that submits this request. If the specified generation count does not match the actual generation of the bus, this request is returned with a status of STATUS_INVALID_GENERATION.

### `PhyPacket`

Specifies the 64-bit PHY packet that is sent to the 1394 bus.

## Remarks

If successful, the new 1394 bus driver (1394ohci.sys) sets **Irp->IoStatus.Status** to STATUS_SUCCESS. If **u.SendPhyPacket.GenerationCount** does not match the current bus generation count, the new 1394 bus driver sets **Irp->IoStatus.Status** to STATUS_INVALID_GENERATION