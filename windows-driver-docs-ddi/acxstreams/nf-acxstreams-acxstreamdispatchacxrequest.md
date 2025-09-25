## Description

The **AcxStreamDispatchAcxRequest** dispatches an ACX request using a WDFREQUEST framework request object. AcxStreamDispatchAcxRequest is called within the context of an [EVT_ACX_OBJECT_PREPROCESS_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/nc-acxrequest-evt_acx_object_preprocess_request) event handler registered through [AcxStreamInitAssignAcxRequestPreprocessCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nf-acxstreams-acxstreaminitassignacxrequestpreprocesscallback) to indicate the request should be handled by the ACX framework.

## Parameters

### `Stream`

An existing *ACXSTREAM* Object. An ACXSTREAM object represents an audio stream created by a circuit. For more information, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Request`

The WDFREQUEST object handle that was passes to the *EVT_ACX_OBJECT_PREPROCESS_REQUEST* event handler. For general information about WDF requests, see [Creating Framework Request Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-framework-request-objects).

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

For any call to the driver's EVT_ACX_OBJECT_PREPROCESS_REQUEST for an AcxStream object, the driver should either call WdfRequestComplete or AcxStreamDispatchAcxRequest, but not both.

### Example

Example usage is shown below.

```cpp
VOID
Codec_EvtStreamRequestPreprocess(
    _In_    ACXOBJECT  Object,
    _In_    ACXCONTEXT DriverContext,
    _In_    WDFREQUEST Request
    )
/*++

Routine Description:

    This function is an example of a preprocess routine.

--*/
{
    //
    // Just give the request back to ACX. Normally the driver would take steps to examine
    // the Request and take action if necessary.
    //
    AcxStreamDispatchAcxRequest((ACXSTREAM)Object, Request);
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)