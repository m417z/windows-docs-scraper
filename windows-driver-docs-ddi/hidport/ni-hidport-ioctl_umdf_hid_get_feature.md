# IOCTL_UMDF_HID_GET_FEATURE IOCTL

## Description

The **IOCTL_UMDF_HID_GET_FEATURE**
control code obtains a [feature report](https://learn.microsoft.com/windows-hardware/drivers/hid/introduction-to-hid-concepts) from a HIDClass device.

## Parameters

### Major code

### Input buffer

A UMDF-based driver calls [IWDFRequest::GetInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getinputmemory) to retrieve a requester-allocated input buffer that contains the report ID of the collection.

### Input buffer length

The size of the buffer obtained by calling [IWDFRequest::GetInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getinputmemory).

### Output buffer

A UMDF-based driver calls [IWDFRequest::GetOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getoutputmemory) to retrieve a requester-allocated output buffer. The driver uses the buffer to return a feature report.

### Output buffer length

The size of the buffer that is retrieved by calling [IWDFIoRequest::GetOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getoutputmemory).

### Input/output buffer

### Input/output buffer length

### Status block

HID minidrivers that carry out the I/O to the device must also:

* Call [IWDFRequest::SetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-setinformation) to set the number of bytes transferred from the device.
* Call [IWDFRequest::Complete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-complete) with S_OK to complete the request without error. Otherwise, set the appropriate HRESULT error code.

## See also

[IOCTL_HID_GET_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_feature)

[IOCTL_UMDF_HID_SET_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidport/ni-hidport-ioctl_umdf_hid_set_feature)