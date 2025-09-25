# IContextState::SetMyTransactionVote

## Description

Sets the consistent flag.

## Parameters

### `txVote` [in]

The consistent flag. For a list of values, see the [TransactionVote](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-transactionvote) enumeration. Set this parameter to TxCommit if the consistent flag is true;set it to TxAbort if the consistent flag is false.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **CONTEXT_E_NOJIT** | [Just-in-Time Activation](https://learn.microsoft.com/windows/desktop/cossdk/com--just-in-time-activation) is not available to this context. |

## Remarks

COM+ inspects this flag only when deactivating the object, and the flag can be set multiple times within a method call.

The default value of the consistent flag is true.

## See also

[Consistent and Done Flags](https://learn.microsoft.com/windows/desktop/cossdk/consistent-and-done-flags)

[IContextState](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icontextstate)