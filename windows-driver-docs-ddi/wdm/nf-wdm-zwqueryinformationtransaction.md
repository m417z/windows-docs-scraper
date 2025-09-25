# ZwQueryInformationTransaction function

## Description

The **ZwQueryInformationTransaction** routine retrieves information about a specified transaction.

## Parameters

### `TransactionHandle` [in]

A handle to a [transaction object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-objects) that was obtained by a previous call to [ZwCreateTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransaction) or [ZwOpenTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransaction). The handle must have TRANSACTION_QUERY_INFORMATION access to the object.

### `TransactionInformationClass` [in]

A [TRANSACTION_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_transaction_information_class)-typed value that specifies the information to obtain. The value must be one of the following values:

* **TransactionBasicInformation**
* **TransactionPropertiesInformation**
* **TransactionEnlistmentInformation**

The **TransactionFullInformation** value is not used with **ZwQueryInformationTransaction**.

### `TransactionInformation` [out]

A pointer to a caller-allocated buffer that receives the information that the *TransactionInformationClass* parameter specifies. The buffer's structure type must be [TRANSACTION_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transaction_basic_information), [TRANSACTION_PROPERTIES_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transaction_properties_information), or [TRANSACTION_ENLISTMENTS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transaction_enlistments_information).

### `TransactionInformationLength` [in]

The length, in bytes, of the buffer that the *TransactionInformation* parameter points to, including the length of any additional array elements that the caller has allocated to receive information.

### `ReturnLength` [out, optional]

A pointer to a caller-allocated variable that receives the length, in bytes, of the information that KTM writes to the *TransactionInformation* buffer. This parameter is optional and can be **NULL**.

## Return value

**ZwQueryInformationTransaction** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_INFO_CLASS** | The *TransactionInformationClass* parameter's value is invalid. |
| **STATUS_INFO_LENGTH_MISMATCH** | The length of the buffer that is specified by the *TransactionInformationLength* parameter is incorrect. |
| **STATUS_OBJECT_TYPE_MISMATCH** | The handle that the *TransactionHandle* parameter specifies is not a handle to a transaction object. |
| **STATUS_INVALID_HANDLE** | An object handle is invalid. |
| **STATUS_ACCESS_DENIED** | The caller does not have appropriate access to the transaction object. |
| **STATUS_BUFFER_OVERFLOW** | The buffer that the *TransactionInformation* parameter specifies is too small. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

For more information about how to use **ZwQueryInformationTransaction**, see [Creating a Transactional Client](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-transactional-client).

**NtQueryInformationTransaction** and **ZwQueryInformationTransaction** are two versions of the same Windows Native System Services routine.

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[TRANSACTION_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transaction_basic_information)

[TRANSACTION_ENLISTMENTS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transaction_enlistments_information)

[TRANSACTION_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_transaction_information_class)

[TRANSACTION_PROPERTIES_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transaction_properties_information)

[TmGetTransactionId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmgettransactionid)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwCreateTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransaction)

[ZwOpenTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransaction)

[ZwSetInformationTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntsetinformationtransaction)