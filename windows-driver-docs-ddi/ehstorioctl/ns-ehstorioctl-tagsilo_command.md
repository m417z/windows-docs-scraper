# tagSILO_COMMAND structure

## Description

This structure describes a storage silo driver command.

## Members

### `SiloIndex`

### `Command`

This member contains the 1667 command value.

### `cbCommandBuffer`

This member contains the size of the 1667 command buffer.

### `rgbCommandBuffer`

## Remarks

Together, **cbCommandBufferSize** and **rgbCommandBuffer** members indicate the raw data payload for the silo command, and are sent as-is to the device. The structure of the data in this buffer is silo-dependent. The structure is assumed to be shared knowledge between the client issuing this IOCTL and the device firmware implementation of this particular silo.