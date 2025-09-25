## Description

The **AcxRequestGetParameters** function gets ACX request parameters from a WDFREQUEST.

## Parameters

### `Request`

An I/O WDFREQUEST object.

For more information about working with WDF request objects, see [Creating Framework Request Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-framework-request-objects) and [wdfrequest.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/).

### `Parameters`

An [ACX_REQUEST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ns-acxrequest-acx_request_parameters) structure that is initialized with the WDFREQUEST.

## Remarks

### Example

Example usage is shown below.

```cpp
    ACX_REQUEST_PARAMETERS      params;
    WDFREQUEST                  request;

    ACX_REQUEST_PARAMETERS_INIT(&params);

    AcxRequestGetParameters(Request, &params);

    request = elementCtx->Request;
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxrequest.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/)