## Description

The **AcxTargetCircuitFormatRequestForProperty** formats a WDFREQUEST as an ACX property request to be used on specified circuit target.

## Parameters

### `TargetCircuit`

An ACXTARGETCIRCUIT handle. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Request`

A WDFREQUEST handle described in [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects). For general information about WDF requests, see [Creating Framework Request Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-framework-request-objects).

### `Params`

An initialized [ACX_REQUEST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ns-acxrequest-acx_request_parameters) structure that is used to store property request parameter information.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

A WDFREQUEST is a driver created I/O requests. Framework-based drivers process each I/O request by calling framework request object methods. For more information, see [Framework Request Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-request-objects).

### Example

```cpp

    ACX_REQUEST_PARAMETERS      params;
    WDFREQUEST                  req;
    ACXTARGETCIRCUIT            targetCircuit;

...

    //
    // Format a WDF request as an ACX property request for the ACX circuit target.
    //
    status = AcxTargetCircuitFormatRequestForProperty(targetCircuit, req, &params);

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxtargets.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/)