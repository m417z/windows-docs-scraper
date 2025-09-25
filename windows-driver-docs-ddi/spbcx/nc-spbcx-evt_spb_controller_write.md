# EVT_SPB_CONTROLLER_WRITE callback function

## Description

An SPB controller driver's *EvtSpbControllerIoWrite* event callback function writes data to the specified target device from the buffers that are supplied with the write request.

## Parameters

### `Controller` [in]

A WDFDEVICE handle to the [framework device object](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-device-object) that represents the SPB controller.

### `Target` [in]

An [SPBTARGET](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles) handle to the target for this I/O request. The target is a peripheral device or port that is attached to the bus. The SPB framework extension (SpbCx) previously assigned this handle to the target in the [EvtSpbTargetConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_target_connect) callback that opened the connection to the target.

### `Request` [in]

An [SPBREQUEST](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles) handle to the I/O request. Your SPB controller driver must complete this request either by performing the requested operation or by returning an error status. For more information, see [Remarks](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_write#remarks).

### `Length` [in]

The number of bytes to write to the target device.

## Remarks

SpbCx manages the I/O queue for the SPB controller. SpbCx calls the SPB controller driver's *EvtSpbControllerIoWrite* callback function when a client (peripheral driver) of the SPB controller sends an [IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write) request to a target device that is attached to the bus. The *Request* parameter value is a handle that encapsulates this request.

An *EvtSpbControllerIoWrite* callback does not return a status value. Instead, the SPB controller driver indicates the status of the write operation in the completion status for the I/O request.

An *EvtSpbControllerIoWrite* callback is asynchronous. That is, the callback function should initiate the requested write operation and then return without waiting for the operation to complete. Later, the SPB controller driver completes the write request during an interrupt DPC or a timer DPC.

An *EvtSpbControllerIoWrite* callback does not return a status value. Instead, the SPB controller driver indicates the status of the write operation in the completion status for the I/O request.

If the write operation completes in full, the callback function should set the completion status to STATUS_SUCCESS. If the target device indicates that it cannot accept any more data before a transmission completes, the driver should set the completion status to STATUS_SUCCESS and specify the number of bytes transmitted.

If a transmission error occurs during the write operation, the driver should set the completion status in the I/O request to an appropriate error code. Not all buses provide a mechanism for a target device to report a transport error or a partially completed transfer, and not all controllers can detect these conditions.

To register an *EvtSpbControllerIoWrite* callback function, call the [SpbDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbdeviceinitialize) method.

### Examples

To define an *EvtSpbControllerIoWrite* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *EvtSpbControllerIoWrite* callback function that is named `MyEvtSpbControllerIoWrite`, use the EVT_SPB_CONTROLLER_WRITE function type, as shown in this code example:

```cpp
EVT_SPB_CONTROLLER_WRITE  MyEvtSpbControllerIoWrite;
```

Then, implement your callback function as follows:

```cpp
_Use_decl_annotations_
VOID
  MyEvtSpbControllerIoWrite(
    WDFDEVICE Controller,
    SPBTARGET Target,
    SPBREQUEST Request,
    size_t Length
    )
{ ... }
```

The EVT_SPB_CONTROLLER_WRITE function type is defined in the Spbcx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the *Use_decl_annotations* annotation to your function definition. The *Use_decl_annotations* annotation ensures that the annotations that are applied to the EVT_SPB_CONTROLLER_WRITE function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about *Use_decl_annotations*, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

* [EvtSpbControllerIoRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_read)
* [EvtSpbTargetConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_target_connect)
* [IOCTL_SPB_EXECUTE_SEQUENCE](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_execute_sequence)
* [IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)
* [SPBREQUEST](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles)
* [SPBTARGET](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles)
* [SpbDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbdeviceinitialize)