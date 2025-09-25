# mmioSendMessage function

## Description

The **mmioSendMessage** function sends a message to the I/O procedure associated with the specified file.

## Parameters

### `hmmio`

File handle for a file opened by using the [mmioOpen](https://learn.microsoft.com/previous-versions/dd757331(v=vs.85)) function.

### `uMsg`

Message to send to the I/O procedure.

### `lParam1`

Parameter for the message.

### `lParam2`

Parameter for the message.

## Return value

Returns a value that corresponds to the message. If the I/O procedure does not recognize the message, the return value should be zero.

## Remarks

Use this function to send custom user-defined messages. Do not use it to send the MMIOM_OPEN, MMIOM_CLOSE, MMIOM_READ, MMIOM_WRITE, MMIOM_WRITEFLUSH, or MMIOM_SEEK messages. Define custom messages to be greater than or equal to the MMIOM_USER constant.