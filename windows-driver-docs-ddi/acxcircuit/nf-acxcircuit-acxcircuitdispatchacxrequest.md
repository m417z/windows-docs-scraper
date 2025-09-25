## Description

The **AcxCircuitDispatchAcxRequest** dispatches an ACX WDFREQUEST object to the ACX framework which will manage the request. For more information about working with WDF request objects, see [Creating Framework Request Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-framework-request-objects) and [wdfrequest.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/).

## Parameters

### `Circuit`

An existing ACXCIRCUIT object. For more information, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Request`

A standard WDFREQUEST object.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
    //
    // Just give the request back to ACX.
    //
    status = AcxCircuitDispatchAcxRequest((ACXCIRCUIT)Object, Request);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)