# CSC_TransactionConfig enumeration

## Description

Indicates how transactions are configured for [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig).

## Constants

### `CSC_NoTransaction:0`

Transactions are never used within the enclosed context. This is the default transaction setting for [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) when [CSC_InheritanceConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_inheritanceconfig) is set to CSC_Ignore.

### `CSC_IfContainerIsTransactional`

Transactions are used only if the enclosed context is using a transaction; a new transaction is never created. This is the default transaction setting for [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) when [CSC_InheritanceConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_inheritanceconfig) is set to CSC_Inherit.

### `CSC_CreateTransactionIfNecessary`

Transactions are always used. The existing transaction is used, or if the enclosed context does not already use transactions, a new transaction is created.

### `CSC_NewTransaction`

A new transaction is always created.

## Remarks

This enumeration is used to configure transactions through [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) for either the work submitted through the activity created by [CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity) or the work that is enclosed between calls to [CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain) and [CoLeaveServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coleaveservicedomain).

## See also

[COM+ Transactions](https://learn.microsoft.com/windows/desktop/cossdk/com--transactions)

[CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig)

[CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity)

[CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain)

[IServiceTransactionConfigBase::ConfigureTransaction](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iservicetransactionconfigbase-configuretransaction)