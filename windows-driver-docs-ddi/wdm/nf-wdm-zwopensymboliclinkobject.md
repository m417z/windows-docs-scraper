## Description

The **ZwOpenSymbolicLinkObject** routine opens an existing symbolic link.

## Parameters

### `LinkHandle` [out]

Pointer to a HANDLE variable that receives a handle to the symbolic link object.

### `DesiredAccess` [in]

Specifies an [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that determines the requested access to the object. The caller usually specified GENERIC_READ, so that the handle can be passed to [ZwQuerySymbolicLinkObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwquerysymboliclinkobject).

### `ObjectAttributes` [in]

Pointer to an [**OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that specifies the object name and other attributes. Use [InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes) to initialize this structure. If the caller is not running in a system thread context, it must set the OBJ_KERNEL_HANDLE attribute when it calls **InitializeObjectAttributes**.

## Return value

**ZwOpenSymbolicLinkObject** returns STATUS_SUCCESS on success or the appropriate error status.

## Remarks

Once the handle pointed to by *LinkHandle* is no longer in use, the driver must call [ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose) to close it.

If the caller is not running in a system thread context, it must ensure that any handles it creates are private handles. Otherwise, the handle can be accessed by the process in whose context the driver is running. For more information, see [Object Handles](https://learn.microsoft.com/windows-hardware/drivers/kernel/object-handles).

If the call to the **ZwOpenSymbolicLinkObject** function occurs in user mode, you should use the name "NtOpenSymbolicLinkObject" instead of "**ZwOpenSymbolicLinkObject**".

**NtOpenSymbolicLinkObject** and **ZwOpenSymbolicLinkObject** are two versions of the same Windows Native System Services routine. The **NtOpenSymbolicLinkObject** routine in the Windows kernel is not directly accessible to kernel-mode drivers. However, kernel-mode drivers can access this routine indirectly by calling the **ZwOpenSymbolicLinkObject** routine.

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwQuerySymbolicLinkObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwquerysymboliclinkobject)