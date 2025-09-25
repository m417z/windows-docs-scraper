# HidD_FlushQueue function

## Description

The **HidD_FlushQueue** routine deletes all pending input reports in a [top-level collection's](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) input queue.

## Parameters

### `HidDeviceObject` [in]

Specifies an open handle to the top-level collection whose input queue is flushed.

## Return value

**HidD_FlushQueue** returns **TRUE** if it successfully flushes the queue. Otherwise, it returns **FALSE**. Use [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information.

## Remarks

Only user-mode applications can call **HidD_FlushQueue**. Kernel-mode drivers can use an [IOCTL_HID_FLUSH_QUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_flush_queue) request.

For more information, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[IOCTL_HID_FLUSH_QUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_flush_queue)