## Description

The **AcxTargetPinFormatRequestForMethod** function function formats a WDFREQUEST as an ACX method request to be used on specified pin target.

## Parameters

### `TargetPin`

An existing ACXTARGETPIN object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Request`

A WDFREQUEST handle described in [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects). For general information about WDF requests, see [Creating Framework Request Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-framework-request-objects).

### `Params`

An initialized [ACX_REQUEST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ns-acxrequest-acx_request_parameters) structure that is used to store method request parameter information.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

A WDFREQUEST is a driver created I/O requests. Framework-based drivers process each I/O request by calling framework request object methods. For more information, see [Framework Request Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-request-objects).

### Example

```cpp
...
    _In_    ACXTARGETCIRCUIT TargetCircuit,
    _In_    ULONG            TargetPinId
    )

    NTSTATUS                    status;
    WDFREQUEST                  req;
    ACX_REQUEST_PARAMETERS      params;
    ACXTARGETPIN                targetPin = NULL;

...

    //
    // Get the target pin obj.
    //
    targetPin = AcxTargetCircuitGetTargetPin(TargetCircuit, TargetPinId);

    //
    // Format a WDF request for the target.
    //
    status = AcxTargetPinFormatRequestForMethod(targetPin, req, &params);

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxtargets.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/)