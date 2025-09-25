# WdfRequestGetParameters function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestGetParameters** method retrieves the parameters that are associated with a specified framework request object.

## Parameters

### `Request` [in]

A handle to a framework request object.

### `Parameters` [in, out]

A pointer to a caller-allocated [WDF_REQUEST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_parameters) structure that the [WDF_REQUEST_PARAMETERS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdf_request_parameters_init) routine initialized and filled in.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

A driver cannot retrieve parameters from a driver-created request by calling **WdfRequestGetParameters** because the framework does not allocate a stack location for the current driver.

For more information about **WdfRequestGetParameters**, see [Obtaining Information About an I/O Request](https://learn.microsoft.com/windows-hardware/drivers/wdf/obtaining-information-about-an-i-o-request).

#### Examples

For a code example that uses **WdfRequestGetParameters**, see [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete).

## See also

[WDF_REQUEST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_parameters)

[WDF_REQUEST_PARAMETERS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdf_request_parameters_init)

[WdfRequestWdmGetIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestwdmgetirp)