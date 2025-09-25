# ICrmMonitorLogRecords::get_TransactionState

## Description

Retrieves the current state of the transaction.

## Parameters

### `pVal` [out]

The current transaction state, represented by an [CrmTransactionState](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-crmtransactionstate) enumeration value.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_POINTER** | A **NULL** pointer was provided as an argument. |

## See also

[ICrmMonitorLogRecords](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmmonitorlogrecords)