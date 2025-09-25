## Description

The **ZwDeleteKey** routine deletes an open key from the registry.

## Parameters

### `KeyHandle` [in]

Handle to the registry key to be deleted. The handle is created by a successful call to [ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey) or [ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey).

## Return value

**ZwDeleteKey** returns an NTSTATUS value. Possible return values include:

- **STATUS_SUCCESS**

- **STATUS_ACCESS_DENIED**

- **STATUS_INVALID_HANDLE**

- **STATUS_CANNOT_DELETE** (see Remarks)

## Remarks

Before calling **ZwDeleteKey**, ensure that all the keys and values under the given key have been deleted. Delete each subkey first, starting with the leaf keys and work your way up.

The handle must have been opened for DELETE access for this routine to succeed. For more information, see the *DesiredAccess* parameter for [ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey).

A call to **ZwDeleteKey** causes the handle that is specified in the *KeyHandle* parameter—and all other handles to the deleted key—to become invalid. After a call to **ZwDeleteKey** invalidates the key handles, you must call [ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose) to close the key handles.

For more information about working with registry keys, see [Using the Registry in a Driver](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-the-registry-in-a-driver).

If the call to this function occurs in user mode, you should use the name "**NtDeleteKey**" instead of "**ZwDeleteKey**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey)

[ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey)