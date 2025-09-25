# EVT_WDF_REQUEST_COMPLETION_ROUTINE callback function

## Description

[Applies to KMDF and UMDF]

A driver's *CompletionRoutine* event callback function executes when another driver completes a specified I/O request.

## Parameters

### `Request` [in]

A handle to a framework request object that represents the completed I/O request.

### `Target` [in]

A handle to an I/O target object that represents the I/O target that completed the request.

### `Params` [in]

A pointer to a [WDF_REQUEST_COMPLETION_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_completion_params) structure that contains information about the completed request. See note below regarding validity of the completion parameters.

### `Context` [in]

Driver-supplied context information, which the driver specified in a previous call to [WdfRequestSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsetcompletionroutine).

## Remarks

To register a *CompletionRoutine* callback function for an I/O request, a driver must call [WdfRequestSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsetcompletionroutine). For more information about this callback function, see [Completing I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

The completion parameters structure is fully populated with valid information only if the driver formatted the request by calling one of the following:

* **WdfIoTargetFormat***Xxx* methods, for example [WdfIoTargetFormatRequestForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetformatrequestforread)
* **WdfUsbTargetDeviceFormatRequestFor***Xxx* methods, for example [**WdfUsbTargetDeviceFormatRequestForString**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceformatrequestforstring)
* **WdfUsbTargetPipeFormatRequestFor***Xxx* methods, for example [**WdfUsbTargetPipeFormatRequestForWrite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipeformatrequestforwrite)

If the driver formatted the request using either [**WdfRequestFormatRequestUsingCurrentType**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestformatrequestusingcurrenttype) or [**WdfRequestWdmFormatUsingStackLocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestwdmformatusingstacklocation), only the **IoStatus** field in the completion parameters structure is valid.

A KMDF driver's *CompletionRoutine* can run at IRQL <= DISPATCH_LEVEL regardless of the **ExecutionLevel** specified in the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure for the I/O request object.

#### Examples

The function type is declared in *Wdfrequest.h*, as follows.

```
typedef VOID
  (EVT_WDF_REQUEST_COMPLETION_ROUTINE)(
    IN WDFREQUEST  Request,
    IN WDFIOTARGET  Target,
    IN PWDF_REQUEST_COMPLETION_PARAMS  Params,
    IN WDFCONTEXT  Context
    );

```

To define a *CompletionRoutine* callback function that is named **MyCompletionRoutine**, you must first provide a function declaration that SDV and other verification tools require, as follows:

```
EVT_WDF_REQUEST_COMPLETION_ROUTINE  MyCompletionRoutine;
```

Then, implement your callback function as follows:

```
VOID
 MyCompletionRoutine (
    IN WDFREQUEST  Request,
    IN WDFIOTARGET  Target,
    IN PWDF_REQUEST_COMPLETION_PARAMS  Params,
    IN WDFCONTEXT  Context
    )
  {...}
```

## See also

[WDF_REQUEST_COMPLETION_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_completion_params)

[WdfRequestSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsetcompletionroutine)