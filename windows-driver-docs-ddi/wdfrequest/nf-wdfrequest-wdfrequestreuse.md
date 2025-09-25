# WdfRequestReuse function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestReuse** method reinitializes a framework request object so that it can be reused.

## Parameters

### `Request` [in]

A handle to a framework request object.

### `ReuseParams` [in]

A pointer to a caller-allocated [WDF_REQUEST_REUSE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_reuse_params) structure.

## Return value

**WdfRequestReuse** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An input parameter is invalid. |
| **STATUS_WDF_REQUEST_INVALID_STATE** | The driver supplied an IRP in the [WDF_REQUEST_REUSE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_reuse_params) structure, but the specified request object was not obtained from [WdfRequestCreateFromIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreatefromirp). |

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

A framework-based driver can reuse framework request objects that it created by previous calls to [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) or [WdfRequestCreateFromIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreatefromirp). Drivers can also reuse request objects that they have [received from the framework](https://learn.microsoft.com/windows-hardware/drivers/wdf/receiving-i-o-requests), but they cannot set the [WDF_REQUEST_REUSE_SET_NEW_IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_reuse_flags) flag for those request objects.

> [!NOTE]
> Drivers should use caution when reusing request objects received from the framework. Reusing such a request resets the cancel flag of the underlying IRP and may prevent a calling driver from cancelling the request.

A driver can reuse a request object after the original request has been completed. After a driver has called **WdfRequestReuse**, the request's contents must be reinitialized. The driver can specify some request parameters in the [WDF_REQUEST_REUSE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_reuse_params) structure.

If you want the reused request to have a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function, the driver must call [WdfRequestSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsetcompletionroutine) after calling **WdfRequestReuse**.

For more information about **WdfRequestReuse**, see [Reusing Framework Request Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/reusing-framework-request-objects).

#### Examples

The following code example is part of a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function that calls **WdfRequestReuse** so that the driver can reuse a driver-allocated request.

```cpp
VOID
MyRequestCompletionRoutine(
    IN WDFREQUEST  Request,
    IN WDFIOTARGET  Target,
    PWDF_REQUEST_COMPLETION_PARAMS  CompletionParams,
    IN WDFCONTEXT  Context
    )
{
    WDF_REQUEST_REUSE_PARAMS  params;
    NTSTATUS  status;
...
    WDF_REQUEST_REUSE_PARAMS_INIT(
                                  &params,
                                  WDF_REQUEST_REUSE_NO_FLAGS,
                                  STATUS_SUCCESS
                                  );

    status = WdfRequestReuse(
                             Request,
                             &params
                             );
    ASSERT(NT_SUCCESS(status));
...
}
```

## See also

[CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine)

[WDF_REQUEST_REUSE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_reuse_params)

[WDF_REQUEST_REUSE_PARAMS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdf_request_reuse_params_init)

[WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate)

[WdfRequestCreateFromIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreatefromirp)

[WdfRequestSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsetcompletionroutine)