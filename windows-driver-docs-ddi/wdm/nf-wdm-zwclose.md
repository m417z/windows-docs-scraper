## Description

The **ZwClose** routine closes an object handle.

## Parameters

### `Handle` [in]

Handle to an object of any type.

## Return value

**ZwClose** returns STATUS_SUCCESS on success, or the appropriate NTSTATUS error code on failure. In particular, it returns STATUS_INVALID_HANDLE if *Handle* is not a valid handle, or STATUS_HANDLE_NOT_CLOSABLE if the calling thread does not have permission to close the handle.

## Remarks

**ZwClose** is a generic routine that operates on any type of object.

Closing an open object handle causes that handle to become invalid. The system also decrements the handle count for the object and checks whether the object can be deleted. The system does not actually delete the object until all of the object's handles are closed and no referenced pointers remain.

A driver must close every handle that it opens as soon as the handle is no longer required. Kernel handles, which are those that are opened by a system thread or by specifying the OBJ_KERNEL_HANDLE flag, can be closed only when the previous processor mode is **KernelMode**. This requirement applies both to system threads and to dispatch routines for IRPs that were issued from kernel mode. (For more information about the previous processor mode, see [ExGetPreviousMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exgetpreviousmode).) For example, a handle that [ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey) returns to a [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine cannot subsequently be closed by the same driver's [dispatch routines](https://learn.microsoft.com/windows-hardware/drivers/). A **DriverEntry** routine runs in a system process, whereas dispatch routines usually run either in the context of the thread issuing the current I/O request, or, for lower-level drivers, in an arbitrary thread context.

A non-kernel handle can be closed only if one of two conditions is met: The previous processor mode is **KernelMode**, or the calling thread has sufficient permission to close the handle. An example of the latter occurs when the calling thread is the one that created the handle.

Callers of **ZwClose** should not assume that this routine automatically waits for all I/O to complete prior to returning.

If the call to this function occurs in user mode, you should use the name "**NtClose**" instead of "**ZwClose**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwCreateDirectoryObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatedirectoryobject)

[ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)

[ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey)

[ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey)

[ZwOpenSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopensection)