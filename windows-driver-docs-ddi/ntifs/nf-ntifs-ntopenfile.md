# NtOpenFile function

## Description

The **NtOpenFile** routine opens an existing file, directory, device, or volume.

## Parameters

### `FileHandle` [out]

Pointer to a HANDLE variable that receives a handle to the file.

### `DesiredAccess` [in]

Specifies an [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that determines the requested access to the object. For more information, see the **DesiredAccess** parameter of [**NtCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile).

### `ObjectAttributes` [in]

Pointer to an [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfwdm/ns-wudfwdm-_object_attributes) structure that specifies the object name and other attributes. Use [**InitializeObjectAttributes**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfwdm/nf-wudfwdm-initializeobjectattributes) to initialize this structure. If the caller is not running in a system thread context, it must set the OBJ_KERNEL_HANDLE attribute when it calls **InitializeObjectAttributes**.

### `IoStatusBlock` [out]

Pointer to an [IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure that receives the final completion status and information about the requested operation.

### `ShareAccess` [in]

Specifies the type of share access for the file. For more information, see the **ShareAccess** parameter of [**NtCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile).

### `OpenOptions` [in]

Specifies the options to apply when opening the file. For more information, see the **CreateOptions** parameter of [**NtCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile).

## Return value

**NtOpenFile** returns STATUS_SUCCESS or the appropriate NTSTATUS error code. In the latter case, the caller can find more information about the cause of the failure by checking the **IoStatusBlock** parameter.

## Remarks

**NtOpenFile** supplies a handle that the caller can use to manipulate a file's data, or the file object's state and attributes. **NtOpenFile** provides a subset of the functionality provided by [**NtCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile). For more information, see [Using Files in a Driver](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-files-in-a-driver).

Once the handle pointed to by **FileHandle** is no longer in use, the driver must call [**NtClose**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose) to close it.

If the caller is not running in a system thread context, it must ensure that any handles it creates are private handles. Otherwise, the handle can be accessed by the process in whose context the driver is running. For more information, see [Object Handles](https://learn.microsoft.com/windows-hardware/drivers/kernel/object-handles).

Callers of **NtOpenFile** must be running at IRQL = PASSIVE_LEVEL and [with special kernel APCs enabled](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

If the call to this function occurs in user mode, you should use the name "**NtOpenFile**" instead of "**ZwOpenFile**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[**ACCESS_MASK**](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[**InitializeObjectAttributes**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfwdm/nf-wudfwdm-initializeobjectattributes)

[**NtClose**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)

[**NtCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)