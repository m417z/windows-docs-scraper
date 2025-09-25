# ZwQueryFullAttributesFile function

## Description

The **ZwQueryFullAttributesFile** routine supplies network open information for the specified file.

## Parameters

### `ObjectAttributes` [in]

A pointer to an [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that supplies the attributes to be used for the file object.

### `FileInformation` [out]

A pointer to a [FILE_NETWORK_OPEN_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_network_open_information) structure that receives the returned file attributes information.

## Return value

**ZwQueryFullAttributesFile** returns STATUS_SUCCESS on success, or the appropriate error status.

## Remarks

Callers of **ZwQueryFullAttributesFile** must be running at IRQL = PASSIVE_LEVEL and [with special kernel APCs enabled](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

**NtQueryFullAttributesFile** and **ZwQueryFullAttributesFile** are two versions of the same Windows Native System Services routine. The **NtQueryFullAttributesFile** routine in the Windows kernel is not directly accessible to kernel-mode drivers. However, kernel-mode drivers can access this routine indirectly by calling the **ZwQueryFullAttributesFile** routine.

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[FILE_NETWORK_OPEN_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_network_open_information)

[OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)