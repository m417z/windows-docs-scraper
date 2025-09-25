# _WDF_REQUEST_SEND_OPTIONS_FLAGS enumeration (wudfddi_types.h)

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **WDF_REQUEST_SEND_OPTIONS_FLAGS** enumeration type defines flags that a driver can specify when it calls [IWDFIoRequest::Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send).

## Constants

### `WDF_REQUEST_SEND_OPTION_TIMEOUT`

If set, the *Timeout* parameter of the [IWDFIoRequest::Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send) method is valid.

### `WDF_REQUEST_SEND_OPTION_SYNCHRONOUS`

If set, UMDF sends the I/O request synchronously.

### `WDF_REQUEST_SEND_OPTION_IGNORE_TARGET_STATE`

If set, UMDF sends the I/O request to the I/O target, regardless of the I/O target's state. If not set, UMDF queues the request if the target is stopped. Setting this flag allows a driver to send a request, such as a request to reset a USB pipe, to a device after the driver has called [IWDFIoTargetStateManagement::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotargetstatemanagement-stop).

### `WDF_REQUEST_SEND_OPTION_SEND_AND_FORGET`

If set, the driver is sending the request asynchronously and does not need to be notified when the request is completed or canceled. The driver does not set an [IRequestCallbackRequestCompletion::OnCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackrequestcompletion-oncompletion) callback function or call [IWDFIoRequest::Complete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-complete) for the request. For more information about this flag, see the following Remarks section.

### `WDF_REQUEST_SEND_OPTION_IMPERSONATE_CLIENT`

If set, and if the I/O request type is [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate), the [Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send) method attempts to pass the client's [impersonation](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-client-impersonation-in-umdf-drivers) level to the driver's I/O target. This value is available in UMDF versions 1.9 and later.

### `WDF_REQUEST_SEND_OPTION_IMPERSONATION_IGNORE_FAILURE`

If set, UMDF ignores impersonation failures. You can use this value only with WDF_REQUEST_SEND_OPTION_IMPERSONATE_CLIENT. This value is available in UMDF versions 1.9 and later.

## Remarks

A driver that sets the WDF_REQUEST_SEND_OPTION_SEND_AND_FORGET flag typically does not format the I/O request before it calls [IWDFIoRequest::Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send) to send the request to an I/O target. In fact, a driver that sets this flag must not call any of the **IWdfIoTarget::FormatRequestFor***Xxx* methods before it calls **IWDFIoRequest::Send**. The driver can use only the [IWDFIoRequest::FormatUsingCurrentType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-formatusingcurrenttype) method to format the request.

Your driver cannot set the WDF_REQUEST_SEND_OPTION_SEND_AND_FORGET flag if the *pIoTarget* parameter of [IWDFIoRequest::Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send) points to a file-handle-based I/O target object. For more information about this type of I/O target, see [Initializing a General I/O Target in UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/initializing-a-general-i-o-target-in-umdf).

If the driver sets the WDF_REQUEST_SEND_OPTION_SEND_AND_FORGET flag, it cannot set any other flags except WDF_REQUEST_SEND_OPTION_IMPERSONATE_CLIENT and WDF_REQUEST_SEND_OPTION_IMPERSONATION_IGNORE_FAILURE.

For more information about client impersonation, see [Handling Client Impersonation](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-client-impersonation-in-umdf-drivers).

For the KMDF version of this enumeration, see [WDF_REQUEST_SEND_OPTIONS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_send_options_flags).

## See also

[IWDFIoRequest::Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send)