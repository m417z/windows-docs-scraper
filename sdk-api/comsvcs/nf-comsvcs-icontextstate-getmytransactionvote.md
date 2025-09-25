# IContextState::GetMyTransactionVote

## Description

Retrieves the value of the consistent flag. Retrieving this value before deactivating the object allows the object to confirm its vote.

## Parameters

### `ptxVote` [out]

The consistent flag. For a list of values, see the [TransactionVote](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-transactionvote) enumeration. This parameter is set to TxCommit if the consistent flag is true; it is set to TxAbort if the consistent flag is false.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **CONTEXT_E_NOTRANSACTION** | The object is not running in a transaction. |

## Remarks

If the method fails, you may be able to determine that a transaction is not present, based on the **HRESULT** value. If the method succeeds, it returns a value based on the consistent flag. From this value, you can determine whether the object can be committed or must be aborted. Regardless of the object's state, the object must be participating in a transaction.

## See also

[Consistent and Done Flags](https://learn.microsoft.com/windows/desktop/cossdk/consistent-and-done-flags)

[IContextState](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icontextstate)