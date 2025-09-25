# _WDF_REQUEST_STOP_ACTION_FLAGS enumeration (wudfddi_types.h)

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The [WDF_REQUEST_STOP_ACTION_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_request_stop_action_flags) enumeration contains values that identify the state of a stop action request in a call to the driver's [IQueueCallbackIoStop::OnIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackiostop-oniostop) method.

## Constants

### `WdfRequestStopActionInvalid`

If this value is set to 1, the request is invalid.

### `WdfRequestStopActionSuspend`

If this value is set to 1, the device is suspended.

### `WdfRequestStopActionPurge`

If this value is set to 1, the device and queue are removed.

### `WdfRequestStopRequestCancelable`

If this value is set to 1, the request is marked as cancelable.

## See also

[IQueueCallbackIoStop::OnIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackiostop-oniostop)