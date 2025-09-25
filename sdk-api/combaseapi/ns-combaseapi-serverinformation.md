# ServerInformation structure

## Description

Represents the implementation of a Component Object Model (COM) interface in a server process.

## Members

### `dwServerPid`

The process ID of the server.

### `dwServerTid`

The thread ID of the server object if it's in the STA, 0 if it's in the MTA, and **0x0000FFFF** if it's in the NA.

### `ui64ServerAddress`

*ui64ServerAddress* is considered a 64-bit value type, rather than a pointer to a 64-bit value, and isn't a pointer to an object in the debugger process. Instead, this address is passed to the [ReadProcessMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-readprocessmemory) function.

## Remarks

The **ServerInformation** structure is used by the [CoDecodeProxy](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-codecodeproxy) function to enable native debuggers to locate the implementation of a COM interface in a server process, given a Windows Runtime interface on a proxy to the Windows Runtime object.

## See also

[CoDecodeProxy](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-codecodeproxy)