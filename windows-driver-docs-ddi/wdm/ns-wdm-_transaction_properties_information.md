# _TRANSACTION_PROPERTIES_INFORMATION structure

## Description

The **TRANSACTION_PROPERTIES_INFORMATION** structure contains a [transaction object's](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-objects) properties.

## Members

### `IsolationLevel`

Reserved for future use.

### `IsolationFlags`

Reserved for future use.

### `Timeout`

A time-out value. If the transaction has not been committed by the time specified by this parameter, KTM rolls back the transaction. The time-out value is expressed in system time units (100-nanosecond intervals), and can specify either an absolute time or a relative time. If the value of the **Timeout** member is negative, the expiration time is relative to the current system time. Otherwise, the expiration time is absolute. Set this member to zero if no time-out is required. If **Timeout** is zero, the transaction never times out.

### `Outcome`

A [TRANSACTION_OUTCOME](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_transaction_outcome)-typed value that identifies the transaction's outcome (result). You can obtain this value by calling [ZwQueryInformationTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransaction), but you cannot set the value with [ZwSetInformationTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntsetinformationtransaction).

### `DescriptionLength`

The size, in bytes, of the buffer that contains the **Description** member's array.

### `Description`

A caller-allocated array of characters that contains or receives the transaction's description string. The [TPS client](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-transactional-client) can specify this string when it calls [ZwCreateTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransaction). The client can retrieve the string by calling by calling **ZwQueryInformationTransaction**, and it can modify the string by calling **ZwSetInformationTransaction**.

## Remarks

The **TRANSACTION_PROPERTIES_INFORMATION** structure is used with the [ZwQueryInformationTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransaction) and [ZwSetInformationTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntsetinformationtransaction) routines.

## See also

[TRANSACTION_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_transaction_information_class)

[TRANSACTION_OUTCOME](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_transaction_outcome)

[ZwCreateTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransaction)

[ZwQueryInformationTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransaction)

[ZwSetInformationTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntsetinformationtransaction)