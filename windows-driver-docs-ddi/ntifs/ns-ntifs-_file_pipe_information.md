# _FILE_PIPE_INFORMATION structure

## Description

The **FILE_PIPE_INFORMATION** structure contains information about a named pipe that is not specific to the local or the remote end of the pipe.

## Members

### `ReadMode`

One of the following values.

| Value | Meaning |
| --- | --- |
| FILE_PIPE_BYTE_STREAM_MODE (0x00000000) | Data is read from the pipe as a stream of bytes. |
| FILE_PIPE_MESSAGE_MODE (0x00000001) | Data is read from the pipe as a stream of messages. |

### `CompletionMode`

One of the following values.

| Value | Meaning |
| --- | --- |
| FILE_PIPE_QUEUE_OPERATION (0x00000000) | Blocking mode |
| FILE_PIPE_COMPLETE_OPERATION (0x00000001) | Non-blocking mode |

## Remarks

If **ReadMode** is set to FILE_PIPE_BYTE_STREAM_MODE, any attempt to change it must fail with a STATUS_INVALID_PARAMETER error code.

When **CompletionMode** is set to FILE_PIPE_QUEUE_OPERATION, if the pipe is connected to, read to, or written from, the operation is not completed until there is data to read, all data is written, or a client is connected.

**Note** A value of FILE_PIPE_QUEUE_OPERATION for **CompletionMode** can result in waiting indefinitely for a client process to perform an action.

When **CompletionMode** is set to FILE_PIPE_COMPLETE_OPERATION, if the pipe is being connected to, read to, or written from, the operation is completed immediately.

For information about pipes, see [Pipes](https://learn.microsoft.com/windows/desktop/ipc/pipes).