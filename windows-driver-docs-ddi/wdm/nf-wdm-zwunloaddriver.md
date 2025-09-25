## Description

The **ZwUnloadDriver** routine unloads a driver from the system. Use this routine with extreme caution (see the **Remarks** section below).

## Parameters

### `DriverServiceName` [in]

Pointer to a counted Unicode string that specifies a path to the driver's registry key, `\Registry\Machine\System\CurrentControlSet\Services\`, where *DriverName* is the name of the driver.

## Return value

**ZwUnloadDriver** returns STATUS_SUCCESS or an error NTSTATUS value such as STATUS_INVALID_DEVICE_REQUEST.

If the driver specified in *DriverServiceName* has no *DriverUnload* callback routine set in its [**DRIVER_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object) structure, **ZwUnloadDriver** returns STATUS_INVALID_DEVICE_REQUEST.

## Remarks

**ZwUnloadDriver** dynamically unloads a device or file system driver from the currently running system. It is not recommended that a driver call **ZwUnloadDriver** on itself.

A file system filter driver cannot safely be unloaded from a running system. Thus a filter should only use **ZwUnloadDriver** for debugging purposes. It should not call this routine in a retail version of the filter.

If *DriverName* is the name of a PnP device driver, **ZwUnloadDriver** returns STATUS_INVALID_DEVICE_REQUEST and does not unload the driver.

A minifilter should use [FltUnloadFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltunloadfilter) instead of **ZwUnloadDriver** to unload a supporting minifilter.

If the call to the **ZwUnloadDriver** function occurs in user mode, you should use the name "NtUnloadDriver" instead of "**ZwUnloadDriver**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[FltUnloadFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltunloadfilter)

[RtlInitUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitunicodestring)

[**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)