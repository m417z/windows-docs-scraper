# ITransactionProxy::IsReusable

## Description

Indicates whether the non-DTC transaction context can be reused for multiple transactions.

## Parameters

### `pfIsReusable` [out]

**TRUE** if the non-DTC transaction context can be reused for multiple transactions; otherwise, **FALSE**.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and S_OK.

## See also

[ITransactionProxy](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-itransactionproxy)