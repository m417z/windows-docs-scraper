# IOCTL_UMDF_GET_PHYSICAL_DESCRIPTOR IOCTL

## Description

The **IOCTL_UMDF_GET_PHYSICAL_DESCRIPTOR**
control code obtains the physical descriptor of a HIDClass device.

## Parameters

### Major code

### Input buffer

A UMDF-based driver obtains the size, in bytes, of the buffer by calling [IWDFRequest::GetDeviceIoControlParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getdeviceiocontrolparameters) and providing the *pOutBufferSize* parameter.

### Input buffer length

### Output buffer

The driver copies the physical descriptor to the user buffer that is retrieved by calling [IWDFIoRequest::GetOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getoutputmemory).

### Output buffer length

The size of the buffer that is retrieved by calling [IWDFIoRequest::GetOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getoutputmemory).

### Input/output buffer

### Input/output buffer length

### Status block

HID minidrivers that carry out the I/O to the device must also:

* Call [IWDFRequest::SetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-setinformation) to set the number of bytes transferred from the device.
* Call [IWDFRequest::Complete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-complete) with S_OK to complete the request without error. Otherwise, set the appropriate HRESULT error code.

## See also

[IOCTL_GET_PHYSICAL_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_get_physical_descriptor)