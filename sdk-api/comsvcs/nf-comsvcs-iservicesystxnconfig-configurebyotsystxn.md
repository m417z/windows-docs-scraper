# IServiceSysTxnConfig::ConfigureBYOTSysTxn

## Description

Enables you to run the enclosed code in the scope of an existing transaction that you specify with a transaction proxy.

## Parameters

### `pTxProxy` [in]

The [ITransactionProxy](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-itransactionproxy) interface of the existing transaction in which you will run the enclosed code.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_FAIL, and S_OK.

## See also

[IServiceSysTxnConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicesystxnconfig)