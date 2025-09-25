# OpenThreadWaitChainSession function

## Description

Creates a new WCT session.

## Parameters

### `Flags` [in]

The session type. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | A synchronous session. |
| **WCT_ASYNC_OPEN_FLAG** | An asynchronous session. |

### `callback` [in, optional]

If the session is asynchronous, this parameter can be a pointer to a [WaitChainCallback](https://learn.microsoft.com/windows/desktop/api/wct/nc-wct-pwaitchaincallback) callback function.

## Return value

If the function succeeds, the return value is a handle to the newly created session.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

When you have finished using the session, call the [CloseThreadWaitChainSession](https://learn.microsoft.com/windows/desktop/api/wct/nf-wct-closethreadwaitchainsession) function.

#### Examples

For an example, see
[Using WCT](https://learn.microsoft.com/windows/desktop/Debug/using-wct).

## See also

[CloseThreadWaitChainSession](https://learn.microsoft.com/windows/desktop/api/wct/nf-wct-closethreadwaitchainsession)

[GetThreadWaitChain](https://learn.microsoft.com/windows/desktop/api/wct/nf-wct-getthreadwaitchain)

[Wait Chain Traversal](https://learn.microsoft.com/windows/desktop/Debug/wait-chain-traversal)

[WaitChainCallback](https://learn.microsoft.com/windows/desktop/api/wct/nc-wct-pwaitchaincallback)