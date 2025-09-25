# HidD_GetNumInputBuffers function

## Description

The **HidD_GetNumInputBuffers** routine returns the current size, in number of reports, of the ring buffer that the HID class driver uses to queue input reports from a specified [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections).

## Parameters

### `HidDeviceObject` [in]

Specifies an open handle to a top-level collection.

### `NumberBuffers` [out]

Pointer to a caller-allocated variable that the routine uses to return the maximum number of input reports the ring buffer can hold.

## Return value

**HidD_GetNumInputBuffers** returns **TRUE** if it succeeds; otherwise, it returns **FALSE**. Use [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information.

## Remarks

Only user-mode applications can call **HidD_GetNumInputBuffers**. Kernel-mode drivers can use the [IOCTL_GET_NUM_DEVICE_INPUT_BUFFERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_get_num_device_input_buffers) request.

For more information, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[HidD_SetNumInputBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_setnuminputbuffers)

[IOCTL_GET_NUM_DEVICE_INPUT_BUFFERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_get_num_device_input_buffers)

[IOCTL_SET_NUM_DEVICE_INPUT_BUFFERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_set_num_device_input_buffers)