# IOCTL_UMDF_HID_SET_OUTPUT_REPORT IOCTL

## Description

The **IOCTL_UMDF_HID_SET_OUTPUT_REPORT**
control code sends an [output report](https://learn.microsoft.com/windows-hardware/drivers/hid/introduction-to-hid-concepts) to a [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections).

## Parameters

### Major code

### Input buffer

A UMDF-based driver calls [IWDFRequest::GetInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getinputmemory) to retrieve a requester-allocated input buffer that contains an output report.

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

[IOCTL_HID_SET_OUTPUT_REPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_set_output_report)

[IOCTL_UMDF_HID_GET_INPUT_REPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidport/ni-hidport-ioctl_umdf_hid_get_input_report)