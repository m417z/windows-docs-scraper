# MRxDevFcbXXXControlFile routine

The *MRxDevFcbXXXControlFile* routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to pass a device FCB control request (an IOCTL or FSCTL request) to the network mini-redirector.

## Parameters

*RxContext* \[in, out\]
A pointer to the RX\_CONTEXT structure. This parameter contains the IRP that is requesting the operation.

## Return value

*MRxDevFcbXXXControlFile* returns STATUS\_SUCCESS on success or an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_ACCESS_DENIED** | A request was made to stop or start the network mini-redirector, but the caller lacked the proper security for this operation. |
| **STATUS_INVALID_DEVICE_REQUEST** | An invalid device request was sent to the network mini-redirector. |
| **STATUS_REDIRECTOR_HAS_OPEN_HANDLES** | This was a request to stop the network mini-redirector, but the redirector has open handles that prevent it from stopping at this time. |
| **STATUS_REDIRECTOR_NOT_STARTED** | This was a request to stop the network mini-redirector, but the redirector was not started. |
| **STATUS_REDIRECTOR_STARTED** | This was a request to start the network mini-redirector, but the redirector was already started. |

## Remarks

*MRxDevFcbXXXControlFile* handles IOCTL and FSCTL requests related to the device FCB that are sent to the network mini-redirector.

Before calling *MRxDevFcbXXXControlFile*, RDBSS modifies the following member in the RX\_CONTEXT structure pointed to by the *RxContext* parameter:

**MajorFunction** is set to the major function of the IRP

If this was an IRP\_MJ\_FILE\_SYSTEM\_CONTROL request, then RDBSS modifies the following members in the RX\_CONTEXT structure pointed to by the *RxContext* parameter:

**LowIoContext.ParamsFor.FsCtl.MinorFunction** is set to the minor function code for the FSCTL code

**LowIoContext.ParamsFor.FsCtl.FsControlCode** is set to the FSCTL code for the IRP

If this was an IRP\_MJ\_DEVICE\_CONTROL or IRP\_MJ\_INTERNAL\_DEVICE\_CONTROL request, then RDBSS modifies the following member in the RX\_CONTEXT structure pointed to by the *RxContext* parameter:

**LowIoContext.ParamsFor.FsCtl.FsControlCode** is set to the control code for the IRP.

If *MRxDevFcbXXXControlFile* returns STATUS\_SUCCESS, then the routine was successful. Any other return value indicates that an error occurred.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Mrx.h (include Mrx.h) |

## See also

[**MRxStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_calldown_ctx)

[**MRxStop**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxstop)

