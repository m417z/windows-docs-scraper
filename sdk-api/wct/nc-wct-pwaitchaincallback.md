# PWAITCHAINCALLBACK callback function

## Description

An application-defined callback function that receives a wait chain. Specify this address when calling the
[OpenThreadWaitChainSession](https://learn.microsoft.com/windows/desktop/api/wct/nf-wct-openthreadwaitchainsession) function.

The **PWAITCHAINCALLBACK** type defines a pointer to this callback function.
*WaitChainCallback* is a placeholder for the application-defined function name.

## Parameters

### `WctHandle`

A handle to the WCT session created by the [OpenThreadWaitChainSession](https://learn.microsoft.com/windows/desktop/api/wct/nf-wct-openthreadwaitchainsession) function.

### `Context`

A optional pointer to an application-defined context structure specified by the [GetThreadWaitChain](https://learn.microsoft.com/windows/desktop/api/wct/nf-wct-getthreadwaitchain) function.

### `CallbackStatus`

The callback status. This parameter can be one of the following values, or one of the other [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller did not have sufficient privilege to open a target thread. |
| **ERROR_CANCELLED** | The asynchronous session was canceled by a call to the [CloseThreadWaitChainSession](https://learn.microsoft.com/windows/desktop/api/wct/nf-wct-closethreadwaitchainsession) function. |
| **ERROR_MORE_DATA** | The *NodeInfoArray* buffer is not large enough to contain all the nodes in the wait chain. The *NodeCount* parameter contains the number of nodes in the chain. The wait chain returned is still valid. |
| **ERROR_OBJECT_NOT_FOUND** | The specified thread could not be located. |
| **ERROR_SUCCESS** | The operation completed successfully. |
| **ERROR_TOO_MANY_THREADS** | The number of nodes exceeds WCT_MAX_NODE_COUNT. The wait chain returned is still valid. |

### `NodeCount`

The number of nodes retrieved, up to WCT_MAX_NODE_COUNT. If the array cannot contain all the nodes of the wait chain, the function fails, *CallbackStatus* is ERROR_MORE_DATA, and this parameter receives the number of array elements required to contain all the nodes.

### `NodeInfoArray`

An array of [WAITCHAIN_NODE_INFO](https://learn.microsoft.com/windows/desktop/api/wct/ns-wct-waitchain_node_info) structures that receives the wait chain.

### `IsCycle`

If the function detects a deadlock, this variable is set to **TRUE**; otherwise, it is set to **FALSE**.

## See also

[GetThreadWaitChain](https://learn.microsoft.com/windows/desktop/api/wct/nf-wct-getthreadwaitchain)

[OpenThreadWaitChainSession](https://learn.microsoft.com/windows/desktop/api/wct/nf-wct-openthreadwaitchainsession)

[WAITCHAIN_NODE_INFO](https://learn.microsoft.com/windows/desktop/api/wct/ns-wct-waitchain_node_info)