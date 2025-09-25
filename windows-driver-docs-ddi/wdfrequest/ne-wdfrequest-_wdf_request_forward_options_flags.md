# _WDF_REQUEST_FORWARD_OPTIONS_FLAGS enumeration

## Description

[Applies to KMDF only]

The **WDF_REQUEST_FORWARD_OPTIONS_FLAGS** enumeration type defines flags that are used in a driver's [WDF_REQUEST_FORWARD_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_forward_options) structure.

## Constants

### `WDF_REQUEST_FORWARD_OPTION_SEND_AND_FORGET:0x00000001`

If set, the driver does not need to be notified when the request is completed or canceled. The driver does not set a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function or call [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete) for the request.

## Remarks

Currently, drivers must set the WDF_REQUEST_FORWARD_OPTION_SEND_AND_FORGET flag.

## See also

[WDF_REQUEST_FORWARD_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_forward_options)