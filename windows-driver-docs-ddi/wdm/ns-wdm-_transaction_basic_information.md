# _TRANSACTION_BASIC_INFORMATION structure

## Description

The **TRANSACTION_BASIC_INFORMATION** structure contains information about a [transaction object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-objects).

## Members

### `TransactionId`

A GUID that KTM has assigned to the transaction object. This value is also known as the transaction's [unit of work (UOW) identifier](https://learn.microsoft.com/windows-hardware/drivers/kernel/ktm-objects).

### `State`

A [TRANSACTION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_transaction_state)-typed value that specifies the transaction's current state.

### `Outcome`

A [TRANSACTION_OUTCOME](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_transaction_outcome)-typed value that specifies the transaction's outcome (result).

## Remarks

The **TRANSACTION_BASIC_INFORMATION** structure is used with the [ZwQueryInformationTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransaction) routine. This routine fills in the structure's members.

## See also

[TRANSACTION_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_transaction_information_class)

[TRANSACTION_OUTCOME](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_transaction_outcome)

[TRANSACTION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_transaction_state)

[TmGetTransactionId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmgettransactionid)

[ZwQueryInformationTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransaction)