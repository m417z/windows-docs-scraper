# _IRB_REQ_ASYNC_READ structure

## Description

This structure contains the fields necessary for the 1394 stack to carry out an asynchronous read request.

## Members

### `DestinationAddress`

Specifies the 1394 64-bit destination address for this read operation. The driver only needs to fill in the **IA_Destination_Offset** member of **DestinationAddress**; the bus driver fills in the **IA_Destination_ID** member. See [IO_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_io_address) for the structure description.

### `nNumberOfBytesToRead`

Specifies the number of bytes to be read from the 1394 node.

### `nBlockSize`

Specifies the size of each individual block within the data stream that is read as a whole from the 1394 node. If this parameter is zero, the maximum packet size for the device and speed selected is used to issue these read requests, unless raw-mode addressing is used.

If raw-mode addressing is used, the client driver should set the **nBlockSize** member to the maximum asynchronous payload size that is supported by the device at the connected speed.

For more information on raw-mode addressing, see [Sending Asynchronous I/O Request Packets on the IEEE 1394 Bus.](https://learn.microsoft.com/windows-hardware/drivers/ieee/sending-asynchronous-i-o-request-packets-on-the-ieee-1394-bus)

**Note** In Windows 7 and later versions of Windows, you can specify new values higher speed and greater sized payloads. For more information, see [New Flags for Speed and Payload Size](https://learn.microsoft.com/windows-hardware/drivers/ieee/device-driver-interface--ddi--changes-in-windows-7) and [IEEE 1394 IOCTL Changes](https://learn.microsoft.com/windows-hardware/drivers/ieee/device-driver-interface--ddi--changes-in-windows-7) in Device Driver Interface (DDI) Changes in Windows 7.

### `fulFlags`

Specifies any nondefault settings for this operation. The following flags are provided.

| Flag | Description |
| --- | --- |
| ASYNC_FLAGS_NONINCREMENTING | When the bus driver splits the request into blocks, begin the operation for each block at the same address, rather than treating each block as consecutive sections of the device's address space. Used only in asynchronous requests larger than **u.AsyncRead.nBlockSize** or the maximum packet size for the current speed. |
| ASYNC_FLAGS_PING | The bus driver returns the elapsed time of the operation in **u.AsyncRead.ElapsedTime**. |

### `Mdl`

Points to an MDL that describes the device driver's buffer, which receives data from the 1394 node.

### `ulGeneration`

Specifies the bus reset generation as known by the device driver that submits this asynchronous request. If the generation count specified does not match the actual generation of the bus, this request is returned with an error of STATUS_INVALID_GENERATION.

### `chPriority`

Reserved. Drivers must set this to zero.

### `nSpeed`

Reserved. Drivers must set this to zero.

### `tCode`

Reserved. Drivers must set this to zero.

### `Reserved`

Reserved. Drivers must set this to zero.

### `ElapsedTime`

Elapsed time in nanoseconds. Only valid for flag ASYNC_FLAGS_PING.