# NtSetInformationTransaction function

## Description

The **ZwSetInformationTransaction** routine sets information for a specified transaction.

## Parameters

### `TransactionHandle` [in]

A handle to a [transaction object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-objects) that was obtained by a previous call to [ZwCreateTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransaction) or [ZwOpenTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransaction). The handle must have TRANSACTION_SET_INFORMATION access to the object.

### `TransactionInformationClass` [in]

A [TRANSACTION_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_transaction_information_class)-typed value that specifies the type of information to set. The value must be **TransactionPropertiesInformation**.

### `TransactionInformation` [in]

A pointer to a caller-allocated buffer that contains the information to set. The buffer's structure type must be [TRANSACTION_PROPERTIES_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transaction_properties_information).

### `TransactionInformationLength` [in]

The length, in bytes, of the buffer that the *TransactionInformation* parameter points to.

## Return value

**ZwSetInformationTransaction** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_INFO_CLASS** | The *TransactionInformationClass* parameter's value is invalid. |
| **STATUS_OBJECT_TYPE_MISMATCH** | The handle that the *TransactionHandle* parameter specifies is not a handle to a transaction object. |
| **STATUS_INVALID_HANDLE** | An object handle is invalid. |
| **STATUS_ACCESS_DENIED** | The caller does not have appropriate access to the transaction object. |
| **STATUS_INFO_LENGTH_MISMATCH** | The *TransactionInformationLength* parameter's value is invalid. |
| **STATUS_INVALID_PARAMETER** | The contents of the buffer that the *TransactionInformation* buffer specifies is invalid. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

For more information about **ZwSetInformationTransaction**, see [Creating a Transactional Client](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-transactional-client).

**NtSetInformationTransaction** and **ZwSetInformationTransaction** are two versions of the same Windows Native System Services routine.

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[TRANSACTION_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_transaction_information_class)

[TRANSACTION_PROPERTIES_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transaction_properties_information)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwCreateTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransaction)

[ZwOpenTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransaction)

[ZwQueryInformationTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationtransaction)