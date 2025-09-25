# EVT_SPB_TARGET_DISCONNECT callback function

## Description

An SPB controller driver's *EvtSpbTargetDisconnect* event callback function closes a connection to a target device that was previously opened by a call to the driver's [EvtSpbTargetConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_target_connect) event callback function.

## Parameters

### `Controller` [in]

A WDFDEVICE handle to the [framework device object](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-device-object) that represents the SPB controller.

### `Target` [in]

A [SPBTARGET](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles) handle to the target to close. The target is a peripheral device or port that is attached to the bus. The SPB framework extension (SpbCx) previously assigned this handle to the target in the [EvtSpbTargetConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_target_connect) callback that opened the connection to the target.

## Remarks

Implementation of this function by the SPB controller driver is optional.

SpbCx manages the I/O queue for the SPB controller. If the SPB controller driver registers an *EvtSpbTargetDisconnect* callback function, SpbCx calls this function when a client (peripheral driver) of the controller driver sends an [IRP_MJ_CLOSE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-close) request to close an SPBTARGET handle. This handle represents a connection to a target device on the bus that the client opened in a previous [IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create) request. If the *EvtSpbTargetDisconnect* function returns an error code, SpbCx fails the **IRP_MJ_CLOSE** request.

The *EvtSpbTargetDisconnect* function is called synchronously from the context of the client's closing thread after all client-initiated I/O operations have ended and after the client has unlocked the controller (if the client previously locked the controller).

If the SPB controller driver has allocated I/O requests and sent them to the next-lower driver in the I/O-request chain for the target device, the *EvtSpbTargetDisconnect* function should cancel these requests before it returns.

A client driver's [DispatchCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_dispatch) and [CreateProcessNotifyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreateprocessnotifyroutine) callback routines can be called at any time after the *EvtSpbTargetDisconnect* callback returns. When the client driver's process exits, its *CreateProcessNotifyEx* routine is called just before the last thread to exit the process is destroyed.

To register an *EvtSpbTargetDisconnect* callback function, call the [SpbDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbdeviceinitialize) method.

#### Examples

To define an *EvtSpbTargetDisconnect* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *EvtSpbTargetDisconnect* callback function that is named `MyEvtSpbTargetDisconnect`, use the EVT_SPB_TARGET_DISCONNECT function type, as shown in this code example:

```
EVT_SPB_TARGET_DISCONNECT  MyEvtSpbTargetDisconnect;
```

Then, implement your callback function as follows:

```
_Use_decl_annotations_
VOID
  MyEvtSpbTargetDisconnect(
    WDFDEVICE Controller,
    SPBTARGET Target
    )
{ ... }
```

The EVT_SPB_TARGET_DISCONNECT function type is defined in the Spbcx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the EVT_SPB_TARGET_DISCONNECT function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[EvtSpbTargetConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_target_connect)

[IRP_MJ_CLOSE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-close)

[IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create)

[SPBTARGET](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles)

[SpbDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbdeviceinitialize)