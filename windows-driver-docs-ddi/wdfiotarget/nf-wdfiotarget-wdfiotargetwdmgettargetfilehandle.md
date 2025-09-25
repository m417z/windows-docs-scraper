# WdfIoTargetWdmGetTargetFileHandle function

## Description

[Applies to KMDF and UMDF]

The **WdfIoTargetWdmGetTargetFileHandle** method returns a handle to the file that is associated with a specified remote I/O target.

## Parameters

### `IoTarget` [in]

A handle to a remote I/O target object. This handle was obtained from a previous call to [WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate).

## Return value

If the driver specified an object name when it called [WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen), **WdfIoTargetWdmGetTargetFileHandle** returns the file handle that is associated with the specified I/O target. Otherwise **WdfIoTargetWdmGetTargetFileHandle** returns **NULL**.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For KMDF, the returned file handle is a kernel-mode handle that is valid in an arbitrary thread context. For information about how a driver can use this file handle, see [Using a File Handle](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-a-file-handle).

The file handle that the **WdfIoTargetWdmGetTargetFileHandle** method returns is valid until the driver calls [WdfIoTargetClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetclose) or [WdfIoTargetCloseForQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcloseforqueryremove), or until the remote I/O target object is deleted. If the driver provides an [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) function for the remote I/O target object, and if the object is deleted before the remote I/O target is closed, the pointer is valid until the *EvtCleanupCallback* function returns.

If the driver attempts to access the WDM device object after it has been removed, the driver can cause the system to crash. The [toastmon](https://learn.microsoft.com/samples/browse/?redirectedfrom=MSDN-samples) sample demonstrates how the driver can provide an [EvtIoTargetQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_query_remove) callback function so that it is notified if the I/O target is removed.

For UMDF, **WdfIoTargetWdmGetTargetFileHandle** returns a Win32 HANDLE valid only in the current process. A legacy UMDF driver (version 1.*x*) calls [IWDFDevice::RetrieveDeviceName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-retrievedevicename) to get the name of the underlying kernel-mode device and then opens a handle to it with **CreateFile**. The driver can then send I/O directly to the lower device(s) using **DeviceIoControl**. Starting in UMDF 2.15, UMDF v2 drivers can open the local I/O target by file (WDF_IO_TARGET_OPEN_PARAMS_INIT_OPEN_BY_FILE) and retrieve the file handle using **WdfIoTargetWdmGetTargetFileHandle**. The framework opens and closes the file handle when the remote target is closed or deleted. The file handle remains valid within the contract of **WdfIoTargetWdmGetTargetFileHandle** described above.

> [!WARNING]
> If a UMDF v2 driver calls **WdfIoTargetWdmGetTargetFileHandle** to obtain the Win32 handle from a remote target opened using WDF_IO_TARGET_OPEN_PARAMS_INIT_OPEN_BY_FILE, do not submit overlapped/asynchronous I/O with APIs like **DeviceIoControl**. Doing so can crash the process hosting the driver. If the driver must submit overlapped I/O, it must also set the low-order bit of the **hEvent** member of the **OVERLAPPED** structure. This is because the framework internally binds the handle to an I/O completion port. A valid event handle whose low-order bit is set keeps I/O completion from being queued to the completion port.

For more information about **WdfIoTargetWdmGetTargetFileHandle**, see [Obtaining Information About a General I/O Target](https://learn.microsoft.com/windows-hardware/drivers/wdf/obtaining-information-about-a-general-i-o-target).

For more information about I/O targets, see [Using I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets).

#### Examples

The following code example obtains a handle to the file that is associated with a specified remote I/O target.

```cpp
HANDLE h;

h = WdfIoTargetWdmGetTargetFileHandle(IoTarget);
```
A legacy UMDF driver (version 1.*x*) calls [IWDFDevice::RetrieveDeviceName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-retrievedevicename) to get the name of the underlying kernel-mode device and then open a handle to it with **CreateFile**. The driver then sends I/O directly to the device using **DeviceIoControl**.

Starting in UMDF 2.15, the driver opens the local I/O target by file and retrieves its handle. The framework opens and closes the file handle. The file handle remains valid within the contract of **WdfIoTargetWdmGetTargetFileHandle**.

```cpp
NTSTATUS status;

WDF_IO_TARGET_OPEN_PARAMS params;

WDFIOTARGET ioTarget = NULL;

HANDLE handle = NULL;

status = WdfIoTargetCreate(Device, &attr, &ioTarget);

if (!NT_SUCCESS(status)) {

    // error handling

}

WDF_IO_TARGET_OPEN_PARAMS_INIT_OPEN_BY_FILE(&params, NULL);

status = WdfIoTargetOpen(ioTarget, &params);

if (!NT_SUCCESS(status)) {

    // error handling

}

handle = WdfIoTargetWdmGetTargetFileHandle(ioTarget);

if (handle == NULL) {

    // error handling

}

if (ioTarget != NULL) {
    WdfIoTargetClose(ioTarget);
}
// You can now call DeviceIoControl(handle, ...) etc.
// NOTE: See Warning above on submitting overlapped or asynchronous I/O

```

## See also

[WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate)

[WdfIoTargetWdmGetTargetFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetwdmgettargetfileobject)