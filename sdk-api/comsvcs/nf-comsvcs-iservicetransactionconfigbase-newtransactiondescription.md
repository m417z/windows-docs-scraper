# IServiceTransactionConfigBase::NewTransactionDescription

## Description

Sets the name that is used when transaction statistics are displayed.

## Parameters

### `szTxDesc` [in]

The description of the transaction.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_FAIL, and S_OK.

## Remarks

If you do not provide a description by using this method, the value of the *szTrackerCtxName* parameter from the [IServiceTrackerConfig::TrackerConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iservicetrackerconfig-trackerconfig) method is used to describe the transaction.

## See also

[IServiceTransactionConfigBase](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicetransactionconfigbase)