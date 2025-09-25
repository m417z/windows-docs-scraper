# CloseThreadWaitChainSession function

## Description

Closes the specified WCT session and cancels any outstanding asynchronous operations.

## Parameters

### `WctHandle` [in]

A handle to the WCT session created by the [OpenThreadWaitChainSession](https://learn.microsoft.com/windows/desktop/api/wct/nf-wct-openthreadwaitchainsession) function.

## Remarks

If the WCT session was opened in asynchronous mode (with WCT_ASYNC_OPEN_FLAG), the function cancels any outstanding operations after their callback functions have been called and returned, and then it returns.

#### Examples

For an example, see
[Using WCT](https://learn.microsoft.com/windows/desktop/Debug/using-wct).

## See also

[OpenThreadWaitChainSession](https://learn.microsoft.com/windows/desktop/api/wct/nf-wct-openthreadwaitchainsession)

[Wait Chain Traversal](https://learn.microsoft.com/windows/desktop/Debug/wait-chain-traversal)