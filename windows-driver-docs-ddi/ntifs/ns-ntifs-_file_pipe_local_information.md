# _FILE_PIPE_LOCAL_INFORMATION structure

## Description

The **FILE_PIPE_LOCAL_INFORMATION** structure contains information about the local end of a named pipe.

## Members

### `NamedPipeType`

One of the following named pipe types.

| Value | Meaning |
| --- | --- |
| FILE_PIPE_BYTE_STREAM_TYPE (0x00000000) | Data is read from the pipe as a stream of bytes. |
| FILE_PIPE_MESSAGE_TYPE (0x00000001) | Data is read from the pipe as a stream of messages. |

### `NamedPipeConfiguration`

One of the following named pipe configurations.

| Value | Meaning |
| --- | --- |
| FILE_PIPE_INBOUND (0x00000000) | The flow of data in the pipe goes from client to server only. |
| FILE_PIPE_OUTBOUND (0x00000001) | The flow of data in the pipe goes from server to client only. |
| FILE_PIPE_FULL_DUPLEX (0x00000002) | The pipe is bidirectional; both server and client processes can read from and write to the pipe. |

### `MaximumInstances`

The maximum number of instances that can be created for this pipe. The first instance of the pipe must specify this value.

### `CurrentInstances`

The number of current named pipe instances.

### `InboundQuota`

The inbound quota, in bytes, for the named pipe.

### `ReadDataAvailable`

The amount of data available, in bytes, to be read from the named pipe.

### `OutboundQuota`

The outbound quota, in bytes, for the named pipe.

### `WriteQuotaAvailable`

The write quota, in bytes, for the named pipe.

### `NamedPipeState`

The connection status for the named pipe. This state has one of the following values.

| Value | Meaning |
| --- | --- |
| FILE_PIPE_DISCONNECTED_STATE (0x00000001) | Named pipe is disconnected. |
| FILE_PIPE_LISTENING_STATE (0x00000002) | Named pipe is waiting to establish a connection. |
| FILE_PIPE_CONNECTED_STATE (0x00000003) | Named pipe is connected. |
| FILE_PIPE_CLOSING_STATE (0x00000004) | Named pipe is in the process of being closed. |

### `NamedPipeEnd`

The type of the named pipe end, which specifies whether this is the client or the server side of a named pipe.

| Value | Meaning |
| --- | --- |
| FILE_PIPE_CLIENT_END (0x00000000) | This is the client end of a named pipe. |
| FILE_PIPE_SERVER_END (0x00000001) | This is the server end of a named pipe. |

## Remarks

For information about pipes, see [Pipes](https://learn.microsoft.com/windows/desktop/ipc/pipes).