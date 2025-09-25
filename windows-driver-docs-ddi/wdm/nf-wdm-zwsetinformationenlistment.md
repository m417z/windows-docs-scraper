# ZwSetInformationEnlistment function

## Description

The **ZwSetInformationEnlistment** routine sets information for a specified [enlistment object](https://learn.microsoft.com/windows-hardware/drivers/kernel/enlistment-objects).

## Parameters

### `EnlistmentHandle` [in]

A handle to an enlistment object that was obtained by a previous call to [ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment) or [ZwOpenEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenenlistment). The handle must have ENLISTMENT_SET_INFORMATION access to the object.

### `EnlistmentInformationClass` [in]

A [ENLISTMENT_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_enlistment_information_class)-typed enumeration value that specifies the type of information to be set. This value must be **EnlistmentRecoveryInformation**.

The enumeration's **EnlistmentBasicInformation** and **EnlistmentFullInformation** values are not used with **ZwSetInformationEnlistment**.

### `EnlistmentInformation` [in]

A pointer to a caller-allocated buffer that contains caller-defined recovery information for the enlistment.

### `EnlistmentInformationLength` [in]

The length, in bytes, of the buffer that the *EnlistmentInformation* parameter points to.

## Return value

**ZwSetInformationEnlistment** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_OBJECT_TYPE_MISMATCH** | The specified handle is not a handle to an enlistment object. |
| **STATUS_INVALID_HANDLE** | The object handle is invalid. |
| **STATUS_INVALID_INFO_CLASS** | The *EnlistmentInformationClass* parameter's value is invalid. |
| **STATUS_INFO_LENGTH_MISMATCH** | The *EnlistmentInformationLength* parameter's value is invalid. |
| **STATUS_ACCESS_DENIED** | The caller does not have appropriate access to the enlistment object. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

A resource manager can use the **ZwSetInformationEnlistment** routine to set recovery information for an enlistment. KTM writes the recovery information to the log stream, and the resource manager can call [ZwQueryInformationEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationenlistment) to read this information from the log stream at any time.

Each subsequent call to **ZwSetInformationEnlistment** deletes the recovery information that the previous call specified before it stores the new recovery information.

For more information about how to use **ZwSetInformationEnlistment**, see [Using Log Streams with KTM](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-log-streams-with-ktm).

**NtSetInformationEnlistment** and **ZwSetInformationEnlistment** are two versions of the same Windows Native System Services routine.

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[ENLISTMENT_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_enlistment_information_class)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment)

[ZwOpenEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenenlistment)

[ZwQueryInformationEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationenlistment)