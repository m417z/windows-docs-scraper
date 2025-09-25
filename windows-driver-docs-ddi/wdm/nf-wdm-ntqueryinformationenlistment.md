# NtQueryInformationEnlistment function

## Description

The **ZwQueryInformationEnlistment** routine retrieves information about a specified [enlistment object](https://learn.microsoft.com/windows-hardware/drivers/kernel/enlistment-objects).

## Parameters

### `EnlistmentHandle` [in]

A handle to an enlistment object that was obtained by a previous call to [ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment) or [ZwOpenEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenenlistment). The handle must have ENLISTMENT_QUERY_INFORMATION access to the object.

### `EnlistmentInformationClass` [in]

An [ENLISTMENT_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_enlistment_information_class)-typed enumeration value that specifies the information to be obtained. This value must be one of the following values:

* **EnlistmentBasicInformation**
* **EnlistmentRecoveryInformation**

The enumeration's **EnlistmentFullInformation** value is not used with **ZwQueryInformationEnlistment**.

### `EnlistmentInformation` [out]

A pointer to a caller-allocated buffer that receives the information that the *EnlistmentInformationClass* parameter specifies. If the *EnlistmentInformationClass* parameter's value is **EnlistmentBasicInformation**, this buffer's structure type must be [ENLISTMENT_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_enlistment_basic_information). If the *EnlistmentInformationClass* parameter's value is **EnlistmentRecoveryInformation**, this buffer's type must match the caller-defined type that the caller used when it called [ZwSetInformationEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntsetinformationenlistment).

### `EnlistmentInformationLength` [in]

The length, in bytes, of the buffer that the *EnlistmentInformation* parameter points to.

### `ReturnLength` [out, optional]

A pointer to a caller-allocated variable that receives the length, in bytes, of the information that KTM writes to the *EnlistmentInformation* buffer. This parameter is optional and can be **NULL**.

## Return value

**ZwQueryInformationEnlistment** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_OBJECT_TYPE_MISMATCH** | The specified handle is not a handle to an enlistment object. |
| **STATUS_INVALID_HANDLE** | The object handle is invalid. |
| **STATUS_INVALID_INFO_CLASS** | The *EnlistmentInformationClass* parameter's value is invalid. |
| **STATUS_INFO_LENGTH_MISMATCH** | The *EnlistmentInformationLength* parameter's value is invalid. |
| **STATUS_ACCESS_DENIED** | The caller does not have appropriate access to the enlistment object. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

A resource manager can call [ZwSetInformationEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntsetinformationenlistment) to set enlistment-specific recovery information for an enlistment object and then call **ZwQueryInformationEnlistment** to retrieve the recovery information.

For more information about **ZwQueryInformationEnlistment**, see [Handling Recovery Operations](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-recovery-operations).

Callers of **ZwQueryInformationEnlistment** must be running at IRQL = PASSIVE_LEVEL.

**NtQueryInformationEnlistment** and **ZwQueryInformationEnlistment** are two versions of the same Windows Native System Services routine.

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[ENLISTMENT_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_enlistment_basic_information)

[ENLISTMENT_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_enlistment_information_class)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment)

[ZwOpenEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenenlistment)

[ZwSetInformationEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntsetinformationenlistment)