## Description

The **EVT_ACX_OBJECT_PROCESS_REQUEST** callback is used by the driver to handle a WDFREQUEST.

## Parameters

### `Object`

An ACX object that is associated with the request. Driver normally casts this handle to the ACX object type this property belongs to. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Request`

An I/O WDFREQUEST object.

For more information about working with WDF request objects, see [Creating Framework Request Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-framework-request-objects) and [wdfrequest.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/).

## Remarks

### Example

Example usage is shown below.

```cpp
EVT_ACX_OBJECT_PROCESS_REQUEST      C_EvtAckMessageCallback;

...

VOID
C_EvtAckMessageCallback(
    _In_    WDFOBJECT   Object,
    _In_    WDFREQUEST  Request
    )
{
    NTSTATUS                        status      = STATUS_NOT_SUPPORTED;
    ACXCIRCUIT                      This        = (ACXCIRCUIT)Object;
    CAPTURE_CTRL_CIRCUIT_CONTEXT *  ctrlCtx     = GetCaptureCtrlCircuitContext(This);;
    CAPTURE_DEVICE_CONTEXT *        ctx         = GetCaptureDeviceContext(ctrlCtx->Device);
    PAPX_ACK_MESSAGE                args        = nullptr;
    ULONG                           argsCb      = sizeof(APX_ACK_MESSAGE);
    PLIST_ENTRY                     le          = nullptr;
    PAPX_SYNC_MESSAGE               message     = nullptr;
    ACX_REQUEST_PARAMETERS          params;

    PAGED_CODE();

    //
    // Get request parameters.
    //
    ACX_REQUEST_PARAMETERS_INIT(&params);
    AcxRequestGetParameters(Request, &params);

    ASSERT(params.Type == AcxRequestTypeMethod);
    ASSERT(params.Parameters.Method.Verb == AcxMethodVerbSend);
    ASSERT(params.Parameters.Method.ArgsCb >= argsCb);

    args = (PAPX_ACK_MESSAGE)params.Parameters.Method.Args;
    argsCb = params.Parameters.Method.ArgsCb; // use real value.

    if (args->Size != argsCb)
    {
        status = STATUS_INVALID_PARAMETER;
        ASSERT(FALSE);
        goto exit;
    }

    //
    // Find the message to ack.
    //
    KeWaitForSingleObject(&ctx->Lock, Executive, KernelMode, FALSE, NULL);

    for (le = ctx->ApxPendingMessages.Flink; le != &ctx->ApxPendingMessages; le = le->Flink)
    {
        message = CONTAINING_RECORD(le, APX_SYNC_MESSAGE, ListEntry);
        if (message->MessageId == args->MessageId)
        {
            message->Result = args->Result;
            KeSetEvent(&message->Event, 0, FALSE);
            break;
        }

        message = nullptr;
    }

    KeReleaseMutex(&ctx->Lock, FALSE);

    if (message)
    {
        status = STATUS_SUCCESS;
    }
    else
    {
        // The pending message must have timeout out and thus got cancelled.
        status = STATUS_CANCELLED;
    }

exit:
    WdfRequestComplete(Request, status);
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxrequest.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/)