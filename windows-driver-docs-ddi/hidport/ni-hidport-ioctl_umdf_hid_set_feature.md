# IOCTL_UMDF_HID_SET_FEATURE IOCTL

## Description

The [IOCTL_UMDF_HID_GET_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidport/ni-hidport-ioctl_umdf_hid_get_feature)
control code sends a [feature report](https://learn.microsoft.com/windows-hardware/drivers/hid/introduction-to-hid-concepts) to a HIDClass device.

## Parameters

### Major code

### Input buffer

A UMDF-based driver calls [IWDFRequest::GetInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getinputmemory) to retrieve a requester-allocated input buffer that contains a feature report.

The driver retrieves the report ID associated with the top-level collection by calling [IWDFRequest::GetDeviceIoControlParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getdeviceiocontrolparameters) and providing the *pOutBufferSize* parameter, as shown in the following example.
```
UCHAR reportId;
SIZE_T outBufferSize;

FxRequest->GetDeviceIoControlParameters(NULL, NULL, &outBufferSize);
reportId = (UCHAR)outBufferSize;

```

### Input buffer length

None.

### Output buffer

None.

### Output buffer length

The size of the buffer that is retrieved by calling [IWDFIoRequest::GetOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getoutputmemory).

### Input/output buffer

### Input/output buffer length

### Status block

HID minidrivers that carry out the I/O to the device must also:

* Call [IWDFRequest::SetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-setinformation) to set the number of bytes transferred to the device.
* Call [IWDFRequest::Complete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-complete) with S_OK to complete the request without error. Otherwise, set the appropriate HRESULT error code.

## See also

[IOCTL_HID_SET_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_set_feature)

[IOCTL_UMDF_HID_GET_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidport/ni-hidport-ioctl_umdf_hid_get_feature)