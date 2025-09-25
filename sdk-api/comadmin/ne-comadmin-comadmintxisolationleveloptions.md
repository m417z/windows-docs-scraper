# COMAdminTxIsolationLevelOptions enumeration

## Description

Indicates the isolation level that is to be used for transactions.

## Constants

### `COMAdminTxIsolationLevelAny:0`

Any isolation level is supported. A downstream component that has this isolation level always uses the same isolation level that its immediate upstream component uses. If the root object in a transaction has its isolation level configured to COMAdminTxIsolationLevelAny, its isolation level becomes COMAdminTxIsolationLevelSerializable.

### `COMAdminTxIsolationLevelReadUnCommitted`

A transaction can read any data, even if it is being modified by another transaction. Any type of new data can be inserted during a transaction. This is the least safe isolation level but allows the highest concurrency.

### `COMAdminTxIsolationLevelReadCommitted`

A transaction cannot read data that is being modified by another transaction that has not committed. Any type of new data can be inserted during a transaction. This is the default isolation level in Microsoft SQL Server.

### `COMAdminTxIsolationLevelRepeatableRead`

Data read by a current transaction cannot be changed by another transaction until the current transaction finishes. Any type of new data can be inserted during a transaction.

### `COMAdminTxIsolationLevelSerializable`

Data read by a current transaction cannot be changed by another transaction until the current transaction finishes. No new data can be inserted that would affect the current transaction. This is the safest isolation level and is the default, but allows the lowest level of concurrency.

## Remarks

This enumeration is used to configure the transaction isolation level for components that use transactions. It is also used to configure the isolation level for using the transaction service without components by being passed as a parameter to [IServiceTransactionConfigBase::IsolationLevel](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iservicetransactionconfigbase-isolationlevel). This method is called through [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) for either the work submitted through the activity created by [CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity) or the work that is enclosed between calls to [CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain) and [CoLeaveServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coleaveservicedomain).

If a downstream component is configured with a higher isolation level than an upstream component and attempts to enlist in a transaction, an error results and the transaction aborts.

## See also

[CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity)

[CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain)

[Configuring Transaction Isolation Levels](https://learn.microsoft.com/windows/desktop/cossdk/configuring-transaction-isolation-levels)