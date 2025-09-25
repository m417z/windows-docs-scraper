# SpbRequestGetParameters function

## Description

The **SpbRequestGetParameters** method retrieves a set of SPB-specific parameter values from an I/O request.

## Parameters

### `SpbRequest` [in]

An [SPBREQUEST](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles) handle to the I/O request. The SPB controller driver previously received this handle through one of its registered [event callback functions](https://learn.microsoft.com/previous-versions/hh450911(v=vs.85)).

### `Parameters` [out]

A pointer to a caller-allocated [SPB_REQUEST_PARAMETERS](https://learn.microsoft.com/previous-versions/hh406209(v=vs.85)) structure into which the method writes the SPB-specific parameter values from the I/O request. The caller must have previously initialized this structure by calling the [SPB_REQUEST_PARAMETERS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spb_request_parameters_init) function.

## Remarks

**SpbRequestGetParameters** is similar to the [WdfRequestGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetparameters) method, but retrieves only SPB-specific information. Your SPB controller driver can call **SpbRequestGetParameters** to retrieve SPB-specific information from I/O requests that it receives from the SPB framework extension (SpbCx). The SPB controller driver can call **WdfRequestGetParameters** to retrieve the generic request parameters from I/O requests that it receives.

#### Examples

The following code example shows how to use **SpbRequestGetParameters** to retrieve the SPB-specific parameters from an I/O request. The *spbRequest* variable contains an SPBREQUEST handle to the I/O request.

```
SPB_REQUEST_PARAMETERS parameters;

SPB_REQUEST_PARAMETERS_INIT(&parameters);

SpbRequestGetParameters(spbRequest, &parameters);

```

## See also

[SPBREQUEST](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles)

[SPB_REQUEST_PARAMETERS](https://learn.microsoft.com/previous-versions/hh406209(v=vs.85))

[SPB_REQUEST_PARAMETERS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spb_request_parameters_init)

[WdfRequestGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetparameters)