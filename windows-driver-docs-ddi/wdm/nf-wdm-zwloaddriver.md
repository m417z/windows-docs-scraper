## Description

The **ZwLoadDriver** routine loads a driver into the system.

## Parameters

### `DriverServiceName` [in]

Pointer to a counted Unicode string that specifies a path to the driver's registry key, \Registry\Machine\System\CurrentControlSet\Services\\<*DriverName*>, where <*DriverName*> is the name of the driver.

## Return value

**ZwLoadDriver** returns STATUS_SUCCESS or an appropriate error NTSTATUS value.

## Remarks

**ZwLoadDriver** dynamically loads a device or file system driver into the currently running system.

If the system is running in safe mode, and the driver fails to load because it is not on the safe mode list, **ZwLoadDriver** returns STATUS_SUCCESS.

A minifilter should use [FltLoadFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltloadfilter) instead of **ZwLoadDriver** to load a supporting minifilter.

If the call to the **ZwLoadDriver** function occurs in user mode, you should use the name "**NtLoadDriver**" instead of "**ZwLoadDriver**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[FltLoadFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltloadfilter)

[RtlInitUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitunicodestring)

[**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwUnloadDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwunloaddriver)