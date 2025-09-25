## Description

The **RECEIVE_TOKEN_INFORMATION_HEADER** structure contains information returned as status from an offload data transfer operation.

## Members

### `AvailableData`

The amount of data available in the **SenseData** array and any additional result information.

### `ResponseToServiceAction`

A response code indicating which command action the response is for. The service action codes are the following.

| Value | Meaning |
|--|--|
| **SERVICE_ACTION_POPULATE_TOKEN** | The response information is for a POPULATE TOKEN command. |
| **SERVICE_ACTION_WRITE_USING_TOKEN** | The response information is for a WRITE USING TOKEN command. |

### `Reserved1`

Reserved.

### `OperationStatus`

The current status of the copy operation. The status can be one of the following values.

| Value | Meaning |
|--|--|
| 0x01 | The operation completed successfully. |
| 0x02 | The operation completed unsuccessfully. |
| 0x04 | The operation completed successfully but the copy initiator should verify that all data was transferred. |
| 0x10 | The operation is in progress. Foreground or background operation state is unknown. |
| 0x11 | The operation is in progress in the foreground. |
| 0x12 | The operation is in progress in the background. |
| 0x60 | The operation was terminated. Possibly by an existing resource reservation. |

### `Reserved2`

Reserved.

### `OperationCounter`

The number of commands processed for the current copy operation.

### `EstimatedStatusUpdateDelay`

The recommended time, in milliseconds, to wait before sending the next RECEIVE COPY STATUS command for updated information about the current copy operation.

### `CompletionStatus`

SCSI status code for the copy command operation.

### `SenseDataFieldLength`

The length, in bytes, of the entire data area available for sense data. This value is always >= **SenseDataLength**.

### `SenseDataLength`

The length, in bytes, of the data in **SenseData**.

### `TransferCountUnits`

The byte units applied to *TransferCount*. Each unit expansion is a exponent in base 2. The multiplier value of **TRANSFER_COUNT_UNITS_KIBIBYTES**, for example, is 1024 and not 1000. The defined units are the following.

| Value | Meaning |
|--|--|
| **TRANSFER_COUNT_UNITS_BYTES** | Transfer count is in bytes. |
| **TRANSFER_COUNT_UNITS_KIBIBYTES** | Transfer count is in kilobytes. |
| **TRANSFER_COUNT_UNITS_MEBIBYTES** | Transfer count is in megabytes. |
| **TRANSFER_COUNT_UNITS_GIBIBYTES** | Transfer count is in gigabytes. |
| **TRANSFER_COUNT_UNITS_TEBIBYTES** | Transfer count is in terabytes. |
| **TRANSFER_COUNT_UNITS_PEBIBYTES** | Transfer count is in petabytes. |
| **TRANSFER_COUNT_UNITS_EXBIBYTES** | Transfer count is in exabytes. |
| **TRANSFER_COUNT_UNITS_NUMBER_BLOCKS** | Transfer count is not an exponent, but in units of logical block length. |

### `TransferCount`

The length of data transferred in the operation. The unit type in **TransferCountUnits** is applied to this value to give the total byte count.

### `SegmentsProcessed`

The number of segments processed for the data transfer operation. Segments are copy length units used internally by a storage device's copy provider. On Windows systems, this value is reserved and applications must ignore this member.

### `Reserved3`

Reserved.

### `SenseData`

Sense data returned for the copy operation.

## Remarks

If **RECEIVE_TOKEN_INFORMATION_HEADER** is for a POPULATE TOKEN command operation, and the command completed successfully, a [**RECEIVE_TOKEN_INFORMATION_RESPONSE_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-receive_token_information_response_header) structure will also be present after **SenseData** at an offset of **SenseDataFieldLength** from the beginning of the **SenseData** array. The **RECEIVE_TOKEN_INFORMATION_RESPONSE_HEADER** structure will contain the token created as a representation of data (ROD) for the range parameters sent with the command.

All multibyte values are in big endian format. Prior to evaluation, these values must be converted to match the endian format of the current platform.

## See also

[**RECEIVE_TOKEN_INFORMATION_RESPONSE_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-receive_token_information_response_header)