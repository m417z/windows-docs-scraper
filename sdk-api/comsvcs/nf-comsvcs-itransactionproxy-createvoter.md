# ITransactionProxy::CreateVoter

## Description

Provides a ballot so that a COM+ transaction context can vote on the transaction.

## Parameters

### `pTxAsync` [in]

An implementation of **ITransactionVoterNotifyAsync2** that notifies the voter of a vote request.

### `ppBallot` [out]

An implementation of **ITransactionVoterBallotAsync2** that allows the voter to approve or veto the non-DTC transaction.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and S_OK.

## See also

[ITransactionProxy](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-itransactionproxy)