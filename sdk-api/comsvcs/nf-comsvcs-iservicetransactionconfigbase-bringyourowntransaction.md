# IServiceTransactionConfigBase::BringYourOwnTransaction

## Description

Enables you to run the enclosed code in an existing transaction that you provide.

## Parameters

### `szTipURL` [in]

The Transaction Internet Protocol (TIP) URL of the existing transaction in which you want to run the enclosed code.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_FAIL, and S_OK.

## Remarks

When you bring your own transaction, that transaction's settings override the settings from the inherited methods of the [IServiceTransactionConfigBase](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicetransactionconfigbase) interface.

The [IServiceTransactionConfig::ConfigureBYOT](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iservicetransactionconfig-configurebyot) and the **BringYourOwnTransaction** methods are identical in behavior; the only difference is the type of parameter passed to each method.

## See also

[Bring Your Own Transaction (BYOT)](https://learn.microsoft.com/windows/desktop/cossdk/bring-your-own-transaction--byot-)

[IServiceTransactionConfigBase](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicetransactionconfigbase)