# IServiceTransactionConfig::ConfigureBYOT

## Description

Enables you to configure the transaction that you use when you bring your own transaction.

## Parameters

### `pITxByot` [in]

A pointer to the **ITransaction** interface of the existing transaction in which you want to run the enclosed code.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_FAIL, and S_OK.

## Remarks

When you bring your own transaction, that transaction's settings override the settings from the inherited methods of the [IServiceTransactionConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicetransactionconfig) interface.

The **ConfigureBYOT** and the [IServiceTransactionConfigBase::BringYourOwnTransaction](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iservicetransactionconfigbase-bringyourowntransaction) methods are identical in behavior; the only difference is the type of parameter passed to each method.

## See also

[Bring Your Own Transaction (BYOT)](https://learn.microsoft.com/windows/desktop/cossdk/bring-your-own-transaction--byot-)

[IServiceTransactionConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicetransactionconfig)