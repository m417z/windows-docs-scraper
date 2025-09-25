# _IRB_REQ_ASYNC_LOCK structure

## Description

This structure contains the fields necessary for the 1394 stack to carry out an asynchronous lock request.

## Members

### `DestinationAddress`

Specifies the 1394 64-bit destination address for this read operation. The driver only needs to fill in the **IA_Destination_Offset** member of **u.AsyncLock.DestinationAddress**; the bus driver fills in the **IA_Destination_ID** member. See [IO_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_io_address) for the structure description.

### `nNumberOfArgBytes`

Specifies the number of argument bytes used in performing this lock operation. May be zero, 4 or 8. See the **u.AsyncLock.fulTransactionType** member for details.

### `nNumberOfDataBytes`

Specifies the number of data bytes used in performing this lock operation. May be 4 or 8. See the **u.AsyncLock.fulTransactionType** member for details.

### `fulTransactionType`

Specifies which atomic transaction to execute on the 1394 node. The following function types are supported.

| fulTransactionType | Description |
| --- | --- |
| LOCK_TRANSACTION_MASK_SWAP | For each bit in the original value and the matching argument, reset the bit to be the same as the corresponding bit in the data value. The **nNumberOfArgBytes** and **nNumberOfDataBytes** members of **u.AsyncLock** must be the same. |
| LOCK_TRANSACTION_COMPARE_SWAP | If the original value and argument match, replace the original value with the data value. The **nNumberOfArgBytes** and **nNumberOfDataBytes** members of **u.AsyncLock** must be the same. |
| LOCK_TRANSACTION_FETCH_ADD | Add the data value to the original value. Big-endian addition is performed. The argument value is not used and the **nNumberOfArgBytes** member of **u.AsyncLock** must be zero. |
| LOCK_TRANSACTION_LITTLE_ADD | Add the data value to the original value. Little-endian addition is performed. The argument value is not used and the **nNumberOfArgBytes** member of **u.AsyncLock** must be zero. |
| LOCK_TRANSACTION_BOUNDED_ADD | If the original value and the argument differ, add the data value to the original value. The **nNumberOfArgBytes** and **nNumberOfDataBytes** members of **u.AsyncLock** must be the same. |
| LOCK_TRANSACTION_WRAP_ADD | If the original value and the argument differ, add the data value to original value. Otherwise, replace the original value with the data value. The **nNumberOfArgBytes** and **nNumberOfDataBytes** members of **u.AsyncLock** must be the same. |

### `fulFlags`

Not currently used. Drivers should set this to zero.

### `Arguments`

Specifies the arguments used in this lock operation.

### `DataValues`

Specifies the data values used in this lock operation.

### `pBuffer`

Points to a buffer that receives lock data values returned from the node. The size of the buffer must be at least equal to the **u.AsyncLock.nNumberOfDataBytes** member.

### `ulGeneration`

Specifies the bus reset generation as known by the device driver who submitted this asynchronous request. If the generation count specified does not match the actual generation of the bus, then this request is returned with an error.

### `chPriority`

Reserved.

### `nSpeed`

Reserved.

### `tCode`

Reserved.

### `Reserved`

Reserved.