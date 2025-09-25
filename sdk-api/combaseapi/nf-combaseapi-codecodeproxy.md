# CoDecodeProxy function

## Description

Locates the implementation of a Component Object Model (COM) interface in a server process given an interface to a proxied object.

## Parameters

### `dwClientPid` [in]

The process ID of the process that contains the proxy.

### `ui64ProxyAddress` [in]

The address of an interface on a proxy to the object. *ui64ProxyAddress* is considered a 64-bit value type, rather than a pointer to a 64-bit value, and isn't a pointer to an object in the debugger process. Instead, this address is passed to the [ReadProcessMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-readprocessmemory) function.

### `pServerInformation` [out]

A structure that contains the process ID, the thread ID, and the address of the server.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The server information was successfully retrieved. |
| **E_ACCESSDENIED** | The caller is an app container, or the developer license is not installed. |
| **RPC_E_INVALID_IPID** | *ui64ProxyAddress* does not point to a proxy. |

## Remarks

The **CoDecodeProxy** function is a COM API that enables native debuggers to locate the implementation of a COM interface in a server process given an interface on a proxy to the object.

Also, the **CoDecodeProxy** function enables the debugger to monitor cross-apartment function calls and fail such calls when appropriate.

You can call the **CoDecodeProxy** function from a 32-bit or 64-bit process. *ui64ProxyAddress* can be a 32-bit or 64-bit address. The **CoDecodeProxy** function returns a 32-bit or 64-bit address in the *pServerInformation* field. If it returns a 64-bit address, you should pass the address to the [ReadProcessMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-readprocessmemory) function only from a 64-bit process.

## See also

[ReadProcessMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-readprocessmemory)

[ServerInformation](https://learn.microsoft.com/windows/desktop/api/combaseapi/ns-combaseapi-serverinformation)