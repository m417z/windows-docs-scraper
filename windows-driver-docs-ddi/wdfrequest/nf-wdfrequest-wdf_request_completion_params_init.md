# WDF_REQUEST_COMPLETION_PARAMS_INIT function

## Description

[Applies to KMDF and UMDF]

The **WDF_REQUEST_COMPLETION_PARAMS_INIT** function initializes a [WDF_REQUEST_COMPLETION_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_completion_params) structure.

## Parameters

### `Params` [out]

A pointer to a caller-supplied [WDF_REQUEST_COMPLETION_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_completion_params) structure.

## Remarks

Drivers must call **WDF_REQUEST_COMPLETION_PARAMS_INIT** to initialize a [WDF_REQUEST_COMPLETION_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_completion_params) structure before calling [WdfRequestGetCompletionParams](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetcompletionparams).

The **WDF_REQUEST_COMPLETION_PARAMS_INIT** function zeros the specified [WDF_REQUEST_COMPLETION_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_completion_params) structure and sets the structure's **Size** member. It also sets the structure's **Type** member to **WdfRequestTypeNoFormat**.

#### Examples

For a code example that uses **WDF_REQUEST_COMPLETION_PARAMS_INIT**, see [WdfRequestGetCompletionParams](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetcompletionparams).

## See also

[WDF_REQUEST_COMPLETION_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_completion_params)