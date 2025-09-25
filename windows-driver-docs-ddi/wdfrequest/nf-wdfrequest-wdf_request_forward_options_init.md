# WDF_REQUEST_FORWARD_OPTIONS_INIT function

## Description

[Applies to KMDF only]

The **WDF_REQUEST_FORWARD_OPTIONS_INIT** function initializes a [WDF_REQUEST_FORWARD_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_forward_options) structure.

## Parameters

### `ForwardOptions` [out]

A pointer to a [WDF_REQUEST_FORWARD_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_forward_options) structure.

## Remarks

Before a driver calls [WdfRequestForwardToParentDeviceIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestforwardtoparentdeviceioqueue), it must call **WDF_REQUEST_FORWARD_OPTIONS_INIT** to initialize a [WDF_REQUEST_FORWARD_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_forward_options) structure.

The **WDF_REQUEST_FORWARD_OPTIONS_INIT** function zeros the specified [WDF_REQUEST_FORWARD_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_forward_options) structure and sets the structure's **Size** member. Then the function sets the [WDF_REQUEST_FORWARD_OPTION_SEND_AND_FORGET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_forward_options_flags) flag.

For a code example that uses **WDF_REQUEST_FORWARD_OPTIONS_INIT**, see [WdfRequestForwardToParentDeviceIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestforwardtoparentdeviceioqueue).

## See also

[WDF_REQUEST_FORWARD_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_forward_options)

[WdfRequestForwardToParentDeviceIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestforwardtoparentdeviceioqueue)