## Description

The **ZwOpenProcess** routine opens a handle to a process object and sets the access rights to this object.

## Parameters

### `ProcessHandle` [out]

A pointer to a variable of type HANDLE. The **ZwOpenProcess** routine writes the process handle to the variable that this parameter points to.

### `DesiredAccess` [in]

An [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that contains the access rights that the caller has requested to the process object.

### `ObjectAttributes` [in]

A pointer to an [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that specifies the attributes to apply to the process object handle. The **ObjectName** field of this structure must be set to **NULL**. For more information, see the following **Remarks** section.

### `ClientId` [in, optional]

A pointer to a client ID that identifies the thread whose process is to be opened. This parameter must be a non-**NULL** pointer to a valid client ID. For more information, see the following **Remarks** section.

## Return value

**ZwOpenProcess** returns STATUS_SUCCESS if the call is successful. Possible return values include the following error status codes:

| Return code | Description |
|---|---|
| **STATUS_INVALID_PARAMETER_MIX** | The caller either supplied an object name or failed to supply a client ID. |
| **STATUS_INVALID_CID** | The specified client ID is not valid. |
| **STATUS_INVALID_PARAMETER** | The requested access rights are not valid for a process object. |
| **STATUS_ACCESS_DENIED** | The requested access rights cannot be granted. |

## Remarks

As is the case with kernel handles opened by other system service calls such as **ZwCreateKey** and **ZwCreateFile**,
the caller is responsible for calling [**ZwClose**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose) to close the handle when it is no longer required.

The *ClientId* parameter must point to a client ID that identifies the thread whose process is to be opened. In addition, the **ObjectName** field of the structure pointed to by *ObjectAttributes* must be set to **NULL**.

If the call to this function occurs in user mode, you should use the name "**NtOpenProcess**" instead of "**ZwOpenProcess**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)