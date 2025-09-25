## Description

The **ZwOpenSection** routine opens a handle for an existing [section object](https://learn.microsoft.com/windows-hardware/drivers/).

## Parameters

### `SectionHandle` [out]

Pointer to a HANDLE variable that receives a handle to the section object.

### `DesiredAccess` [in]

Specifies an [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that determines the requested access to the object. For more information, see the *DesiredAccess* parameter of [ZwCreateSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatesection).

### `ObjectAttributes` [in]

Pointer to an [**OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that specifies the object name and other attributes. Use [InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes) to initialize this structure. If the caller is not running in a system thread context, it must set the OBJ_KERNEL_HANDLE attribute when it calls **InitializeObjectAttributes**.

## Return value

**ZwOpenSection** returns STATUS_SUCCESS on success, or the appropriate error code on failure. Possible return values include:

## Remarks

If the section does not exist or the system did not grant the requested access, the operation fails.

Once the handle pointed to by *SectionHandle* is no longer in use, the driver must call [ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose) to close it.

If the caller is not running in a system thread context, it must ensure that any handles it creates are private handles. Otherwise, the handle can be accessed by the process in whose context the driver is running. For more information, see [Object Handles](https://learn.microsoft.com/windows-hardware/drivers/kernel/object-handles).

If the call to this function occurs in user mode, you should use the name "**NtOpenSection**" instead of "**ZwOpenSection**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwCreateSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatesection)

[ZwMapViewOfSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwmapviewofsection)

[ZwUnmapViewOfSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwunmapviewofsection)