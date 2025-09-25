# ZwQueryInformationTransactionManager function

## Description

The **ZwQueryInformationTransactionManager** routine retrieves information about a specified transaction manager object.

## Parameters

### `TransactionManagerHandle` [in]

A handle to a [transaction manager object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-manager-objects) that was obtained by a previous call to [ZwCreateTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransactionmanager) or [ZwOpenTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransactionmanager). The handle must have TRANSACTIONMANAGER_QUERY_INFORMATION access to the object.

### `TransactionManagerInformationClass` [in]

A [TRANSACTIONMANAGER_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_transactionmanager_information_class)-typed enumeration value that specifies the information to be obtained. This value must be one of the following:

* **TransactionManagerBasicInformation**
* **TransactionManagerLogInformation**
* **TransactionManagerLogPathInformation**

The enumeration's **TransactionManagerOnlineProbeInformation** value is not used with **ZwQueryInformationTransactionManager**.

### `TransactionManagerInformation` [out]

A pointer to a caller-allocated buffer that receives the information that the *TransactionManagerInformationClass* parameter specifies. The buffer's structure type must be [TRANSACTIONMANAGER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transactionmanager_basic_information), [TRANSACTIONMANAGER_LOG_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transactionmanager_log_information), [TRANSACTIONMANAGER_LOGPATH_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transactionmanager_logpath_information), or [TRANSACTIONMANAGER_RECOVERY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transactionmanager_recovery_information).

### `TransactionManagerInformationLength` [in]

The length, in bytes, of the buffer that the *TransactionManagerInformation* parameter points to, including the length of any additional array elements that the caller has allocated to receive information.

### `ReturnLength` [out, optional]

A pointer to a caller-allocated variable that receives the length, in bytes, of the information that KTM writes to the *TransactionManagerInformation* buffer. This parameter is optional and can be **NULL**.

## Return value

**ZwQueryInformationTransactionManager** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_INFO_CLASS** | The *TransactionManagerInformationClass* parameter's value is invalid. |
| **STATUS_INFO_LENGTH_MISMATCH** | The length of the buffer that is specified by the *TransactionManagerInformationLength* parameter is incorrect. |
| **STATUS_OBJECT_TYPE_MISMATCH** | The specified handle is not a handle to a transaction manager object. |
| **STATUS_INVALID_HANDLE** | An object handle is invalid. |
| **STATUS_ACCESS_DENIED** | The caller does not have appropriate access to the transaction manager object. |
| **STATUS_BUFFER_TOO_SMALL** | The buffer that is specified by the *TransactionManagerInformation* parameter is too small. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

For more information about how to use **ZwQueryInformationTransactionManager**, see [Using Log Streams with KTM](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-log-streams-with-ktm).

**NtQueryInformationTransactionManager** and **ZwQueryInformationTransactionManager** are two versions of the same Windows Native System Services routine.

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[TRANSACTIONMANAGER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transactionmanager_basic_information)

[TRANSACTIONMANAGER_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_transactionmanager_information_class)

[TRANSACTIONMANAGER_LOGPATH_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transactionmanager_logpath_information)

[TRANSACTIONMANAGER_LOG_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_transactionmanager_log_information)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwCreateTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransactionmanager)

[ZwOpenTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransactionmanager)

[ZwRecoverTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrecovertransactionmanager)

[ZwRollforwardTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrollforwardtransactionmanager)