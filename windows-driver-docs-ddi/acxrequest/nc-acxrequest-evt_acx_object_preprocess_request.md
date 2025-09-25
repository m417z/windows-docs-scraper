## Description

The **EVT_ACX_OBJECT_PREPROCESS_REQUEST** callback is used by the driver to preprocess I/O WDFREQUESTs.

## Parameters

### `Object`

An ACX object associated with the request. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `DriverContext`

The driver context defined by the ACXCONTEXT object.

### `Request`

An WDFREQUEST object.

For more information about working with WDF request objects, see [Creating Framework Request Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-framework-request-objects) and [wdfrequest.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/).

## Remarks

### Example

Example usage is shown below.

```cpp
EVT_ACX_OBJECT_PREPROCESS_REQUEST   CodecR_EvtCircuitRequestPreprocess;

...

VOID
CodecR_EvtCircuitRequestPreprocess(
    _In_    ACXOBJECT  Object,
    _In_    ACXCONTEXT DriverContext,
    _In_    WDFREQUEST Request
    )
/*++

Routine Description:

    This function is an example of a preprocess routine.

--*/
{
    PAGED_CODE();

    UNREFERENCED_PARAMETER(DriverContext);

    ASSERT(Object != NULL);
    ASSERT(DriverContext);
    ASSERT(Request);

    // Add the handling of the request here.
    // Driver is responsible for completing the request when done.

    //
    // Else, just give the request back to ACX.
    //
    (VOID)AcxCircuitDispatchAcxRequest((ACXCIRCUIT)Object, Request);
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxrequest.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/)