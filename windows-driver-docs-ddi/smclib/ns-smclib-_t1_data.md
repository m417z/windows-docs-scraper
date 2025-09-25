# _T1_DATA structure

## Description

The T1_DATA structure is used by the smart card driver library to process T1 I/O.

## Members

### `IFSC`

Contains the field size that can be transmitted.

### `IFSD`

Contains the field size that can be received.

### `BytesReceived`

Contains the number of bytes already received from the smart card.

### `BytesSent`

Contains the number of bytes already sent to the smart card.

### `BytesToSend`

Contains the total number of remaining bytes to send.

### `LastError`

Contains the T1 error code of the last received block.

### `MoreData`

### `NAD`

Contains the node address byte to send to the smart card.

### `OriginalState`

Contains the state before an error occurred.

### `Resend`

Contains the resend counter.

### `Resynch`

Contains the resynch counter.

### `RSN`

Contains the number of sent I-Blocks, as defined in the *ISO 7816-3 Specification*.

### `SSN`

Contains the send sequence number (SSN). This member has a value of 0 or 1 as defined in the *ISO 7816-3 Specification*.

### `State`

Contains the current state of the protocol.

### `Wtx`

Contains the waiting time extension for a T=1 transmission. If nonzero, this is a multiplier for the block waiting time. Usually, the driver will time out if the block waiting time expires. Several smart card operations require more time. The smart card answers with a waiting time extension. Therefore, the block waiting time must be multiplied with the **Wtx** value. If this value is nonzero, it applies as a waiting extension.

### `ReplyData`

A pointer to the buffer that contains the result of the operation.

### `WaitForReply`

If **TRUE**, execute the operation synchronously.

### `InfBytesSent`

### `Reserved`

Reserved, do not use.

## Remarks

This structure must not be directly modified by a reader driver.