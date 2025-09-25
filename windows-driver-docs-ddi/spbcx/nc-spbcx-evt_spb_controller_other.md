# EVT_SPB_CONTROLLER_OTHER callback function

## Description

An SPB controller driver's *EvtSpbControllerIoOther* event callback function handles device I/O control requests that are not handled by other event callback functions or by the SPB framework extension (SpbCx).

## Parameters

### `Controller` [in]

A WDFDEVICE handle to the [framework device object](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-device-object) that represents the SPB controller.

### `Target` [in]

An [SPBTARGET](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles) handle to the target for this I/O request. The target is a peripheral device or port that is attached to the bus. The SPB framework extension (SpbCx) previously assigned this handle to the target in the [EvtSpbTargetConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_target_connect) callback that opened the connection to the target.

### `Request` [in]

The [SPBREQUEST](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles) handle to the I/O request. Your SPB controller driver must complete this request. For more information, see Remarks.

### `OutputBufferLength` [in]

The length, in bytes, of the output buffer, if an output buffer is supplied with the request.

### `InputBufferLength` [in]

The length, in bytes, of the input buffer, if an input buffer is supplied with the request.

### `IoControlCode` [in]

The I/O control code (IOCTL) for the request. This value is an IOCTL that the SPB framework extension (SpbCx) does not recognize. For more information, see Remarks.

## Remarks

SpbCx manages the I/O queue for the SPB controller. If the SPB controller driver registers an *EvtSpbControllerIoOther* callback function, SpbCx calls this function when a device I/O control request that SpbCx does not support arrives in the controller's I/O queue. The *Request* parameter value is a handle that encapsulates this request. The SPB controller driver must complete this request either by performing the requested operation or by returning an error status. If the driver does not support the specified IOCTL, the driver should return the STATUS_NOT_SUPPORTED error status. For a list of IOCTLs that SpbCx supports, see [SpbCx I/O Control Codes](https://learn.microsoft.com/previous-versions/hh450915(v=vs.85)).

The *EvtSpbControllerIoOther* callback enables bus-specific or driver-specific commands to be dispatched to the SPB controller driver as IOCTLs. For example, clients (peripheral drivers) might use these IOCTLs to coordinate bus-specific operations, such as full-duplex data exchanges with a target device on an SPI bus. Such IOCTLs are subject to the same flow-control as the IOCTLs that are supported by SpbCx.

The *EvtSpbControllerIoOther* callback function is similar to the [EvtIoDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_device_control) and processes IOCTLs in a similar way. For general information about how WDF drivers handle I/O requests, see [Framework Request Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-request-objects).

An *EvtSpbControllerIoOther* callback does not return a status value. Instead, the SPB controller driver indicates the status of the requested operation in the completion status for the I/O request.

If an I/O request cannot be completed immediately, the callback function should return without waiting for the SPB controller driver to finish processing the request. The SPB controller driver can later complete the request asynchronously.

An *EvtSpbControllerIoOther* function must validate the parameter values in the I/O control requests that it receives from user-mode clients. For all *EvtSpb*Xxx callback functions other than *EvtSpbControllerIoOther*, SpbCx validates the user-mode parameters before it calls the function.

To register an *EvtSpbControllerIoOther* callback function, call the [SpbControllerSetIoOther](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbcontrollersetioothercallback) method.

#### Examples

To define an *EvtSpbControllerIoOther* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *EvtSpbControllerIoOther* callback function that is named `MyEvtSpbControllerIoOther`, use the EVT_SPB_CONTROLLER_OTHER function type, as shown in this code example:

```
EVT_SPB_CONTROLLER_OTHER  MyEvtSpbControllerIoOther;
```

Then, implement your callback function as follows:

```
_Use_decl_annotations_
VOID
  MyEvtSpbControllerIoOther(
    WDFDEVICE Controller,
    SPBTARGET Target,
    SPBREQUEST Request,
    size_t OutputBufferLength,
    size_t InputBufferLength,
    ULONG IoControlCode
    )
{ ... }
```

The EVT_SPB_CONTROLLER_OTHER function type is defined in the Spbcx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the EVT_SPB_CONTROLLER_OTHER function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[EvtIoDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_device_control)

[EvtSpbTargetConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_target_connect)

[SPBREQUEST](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles)

[SPBTARGET](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles)

[SpbControllerSetIoOther](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbcontrollersetioothercallback)