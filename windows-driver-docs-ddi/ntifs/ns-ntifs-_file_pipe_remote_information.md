# _FILE_PIPE_REMOTE_INFORMATION structure

## Description

The **FILE_PIPE_REMOTE_INFORMATION** structure contains information about the remote end of a named pipe.

## Members

### `CollectDataTime`

The maximum amount of time, in 100-nanosecond intervals, that elapses before transmission of data from the client machine to the server.

### `MaximumCollectionCount`

The maximum size, in bytes, of data that will be collected on the client machine before transmission to the server.

## Remarks

Remote information is not available for local pipes or for the server end of a remote pipe.

For information about pipes, see [Pipes](https://learn.microsoft.com/windows/desktop/ipc/pipes).