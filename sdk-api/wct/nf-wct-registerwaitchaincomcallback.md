# RegisterWaitChainCOMCallback function

## Description

Register COM callback functions for WCT.

## Parameters

### `CallStateCallback` [in]

The address of the **CoGetCallState** function.

### `ActivationStateCallback` [in]

The address of the **CoGetActivationState** function.

## Remarks

If a thread is blocked on a COM call, WCT can retrieve COM ownership information using these callback functions. If this function is callback multiple times, only the last addresses retrieved are used.

#### Examples

For an example, see
[Using WCT](https://learn.microsoft.com/windows/desktop/Debug/using-wct).

## See also

[Wait Chain Traversal](https://learn.microsoft.com/windows/desktop/Debug/wait-chain-traversal)