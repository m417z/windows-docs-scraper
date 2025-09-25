# GetThreadWaitChain function

## Description

Retrieves the wait chain for the specified thread.

## Parameters

### `WctHandle` [in]

A handle to the WCT session created by the [OpenThreadWaitChainSession](https://learn.microsoft.com/windows/desktop/api/wct/nf-wct-openthreadwaitchainsession) function.

### `Context` [in, optional]

A pointer to an application-defined context structure to be passed to the callback function for an asynchronous session.

### `Flags` [in]

The wait chain retrieval options. This parameter can be one of more of the following values.

| Value | Meaning |
| --- | --- |
| **WCT_OUT_OF_PROC_COM_FLAG** | Enumerates all threads of an out-of-proc MTA COM server to find the correct thread identifier. |
| **WCT_OUT_OF_PROC_CS_FLAG** | Retrieves critical-section information from other processes. |
| **WCT_OUT_OF_PROC_FLAG** | Follows the wait chain into other processes. Otherwise, the function reports the first thread in a different process but does not retrieve additional information. |

### `ThreadId` [in]

The identifier of the thread.

### `NodeCount` [in, out]

On input, a number from 1 to WCT_MAX_NODE_COUNT that specifies the number of nodes in the wait chain. On return, the number of nodes retrieved. If the array cannot contain all the nodes of the wait chain, the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_MORE_DATA, and this parameter receives the number of array elements required to contain all the nodes.

For asynchronous sessions, check the value that is passed to the callback function. Do not free the variable until the callback function has returned.

### `NodeInfoArray` [out]

An array of [WAITCHAIN_NODE_INFO](https://learn.microsoft.com/windows/desktop/api/wct/ns-wct-waitchain_node_info) structures that receives the wait chain.

For asynchronous sessions, check the value that is passed to the callback function. Do not free the array until the callback function has returned.

### `IsCycle` [out]

If the function detects a deadlock, this variable is set to **TRUE**; otherwise, it is set to **FALSE**.

For asynchronous sessions, check the value that is passed to the callback function. Do not free the variable until the callback function has returned.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller did not have sufficient privilege to open a target thread. |
| **ERROR_INVALID_PARAMETER** | One of the input parameters is invalid. |
| **ERROR_IO_PENDING** | The WCT session was opened in asynchronous mode. The results will be returned through the [WaitChainCallback](https://learn.microsoft.com/windows/desktop/api/wct/nc-wct-pwaitchaincallback) callback function. |
| **ERROR_MORE_DATA** | The *NodeInfoArray* buffer is not large enough to contain all the nodes in the wait chain. The *NodeCount* parameter contains the number of nodes in the chain. The wait chain returned is still valid. |
| **ERROR_NOT_SUPPORTED** | The operating system is not providing this service. |
| **ERROR_OBJECT_NOT_FOUND** | The specified thread could not be located. |
| **ERROR_TOO_MANY_THREADS** | The number of nodes exceeds WCT_MAX_NODE_COUNT. The wait chain returned is still valid. |

## Remarks

If the session is asynchronous, the function returns **FALSE** and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_IO_PENDING. To obtain the results, see the [WaitChainCallback](https://learn.microsoft.com/windows/desktop/api/wct/nc-wct-pwaitchaincallback) callback function.

If the specified thread is not blocked or is blocked on an unsupported synchronization element, the function returns a single item in *NodeInfoArray*.

The caller must have the SE_DEBUG_NAME privilege. If the caller has insufficient privileges, the function fails if the first thread cannot be accessed. Otherwise, the last node in the array will have its **ObjectStatus** member set to WctStatusNoAcces.

If any subset of nodes in the array forms a cycle, the function sets the *IsCycle* parameter to **TRUE**.

Wait chain information is dynamic; it was correct when the function was called but may be out-of-date by the time it is reviewed by the caller.

#### Examples

For an example, see
[Using WCT](https://learn.microsoft.com/windows/desktop/Debug/using-wct).

## See also

[OpenThreadWaitChainSession](https://learn.microsoft.com/windows/desktop/api/wct/nf-wct-openthreadwaitchainsession)

[WAITCHAIN_NODE_INFO](https://learn.microsoft.com/windows/desktop/api/wct/ns-wct-waitchain_node_info)

[Wait Chain Traversal](https://learn.microsoft.com/windows/desktop/Debug/wait-chain-traversal)

[WaitChainCallback](https://learn.microsoft.com/windows/desktop/api/wct/nc-wct-pwaitchaincallback)