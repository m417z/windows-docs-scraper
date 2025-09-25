## Description

The **ZwMakeTemporaryObject** routine changes the attributes of an object to make it temporary.

## Parameters

### `Handle` [in]

Handle to an object of any type.

## Return value

**ZwMakeTemporaryObject** returns STATUS_SUCCESS on success, or the appropriate NTSTATUS error code on failure.

## Remarks

**ZwMakeTemporaryObject** is a generic routine that operates on any type of object.

An object is permanent if it was created with the OBJ_PERMANENT object attribute specified. (For more information about object attributes, see [InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes).) A permanent object is created with a reference count of 1, so it is not deleted when a driver dereferences it.

An object is temporary if it is not permanent. **ZwMakeTemporaryObject** turns the specified object into a temporary object. If the object is already temporary, this routine does nothing.

A temporary object has a name only as long as its handle count is greater than zero. When the handle count reaches zero, the system deletes the object name and appropriately adjusts the object's pointer count.

If the call to this function occurs in user mode, you should use the name "**NtMakeTemporaryObject**" instead of "**ZwMakeTemporaryObject**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)

[ZwCreateDirectoryObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatedirectoryobject)

[ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)