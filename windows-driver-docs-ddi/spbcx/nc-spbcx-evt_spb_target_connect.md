# EVT_SPB_TARGET_CONNECT callback function

## Description

An SPB controller driver's *EvtSpbTargetConnect* event callback function opens a connection to a target device on the bus.

## Parameters

### `Controller` [in]

A WDFDEVICE handle to the [framework device object](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-device-object) that represents the SPB controller.

### `Target` [in]

An [SPBTARGET](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles) handle to the target to open. The target is a peripheral device or port that is attached to the bus.

## Return value

*EvtSpbTargetConnect* returns STATUS_SUCCESS if the driver successfully opens the connection to the target. Otherwise, the function returns an appropriate NTSTATUS error code.

## Remarks

Implementation of this function by the SPB controller driver is optional.

The SPB framework extension (SpbCx) manages the I/O queue for the SPB controller. If the SPB controller driver registers an *EvtSpbTargetConnect* callback function, SpbCx calls this function when a client (peripheral driver) of the controller sends an [IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create) request to open a connection to a target device on the bus. If the *EvtSpbTargetConnect* function returns an error code, SpbCx fails the **IRP_MJ_CREATE** request. A client that successfully opens a connection to a target has exclusive access to the target until the connection is closed.

Call the [SpbTargetGetConnectionParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbtargetgetconnectionparameters) method to get the connection parameters for the target device. An SPB controller driver typically calls this method from the driver's *EvtSpbTargetConnect* function. **SpbTargetGetConnectionParameters** writes the connection parameters to a caller-supplied [SPB_CONNECTION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/ns-spbcx-_spb_connection_parameters) structure. The **ConnectionParameters** member of this structure is a pointer to a buffer that contains the connection settings for the target device. The driver uses these settings to configure the SPB controller to communicate with the device. For more information, see [How to Get the Connection Settings for a Device](https://learn.microsoft.com/windows-hardware/drivers/spb/how-to-get-the-connection-settings-for-a-device).

The *EvtSpbTargetConnect* callback function is called synchronously from the context of the client thread that requests the connection to the target.

SpbCx calls the [EvtSpbTargetDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_target_disconnect) callback function to close a target connection that was previously opened by an *EvtSpbTargetConnect* callback.

To register an *EvtSpbTargetConnect* callback function, call the [SpbDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbdeviceinitialize) method.

#### Examples

To define an *EvtSpbTargetConnect* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *EvtSpbTargetConnect* callback function that is named `MyEvtSpbTargetConnect`, use the EVT_SPB_TARGET_CONNECT function type, as shown in this code example:

```
EVT_SPB_TARGET_CONNECT  MyEvtSpbTargetConnect;
```

Then, implement your callback function as follows:

```
_Use_decl_annotations_
NTSTATUS
  MyEvtSpbTargetConnect(
    WDFDEVICE Controller,
    SPBTARGET Target
    )
{ ... }
```

The EVT_SPB_TARGET_CONNECT function type is defined in the Spbcx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the EVT_SPB_TARGET_CONNECT function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[EvtSpbTargetDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_target_disconnect)

[IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create)

[SPBTARGET](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles)

[SPB_CONNECTION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/ns-spbcx-_spb_connection_parameters)

[SpbDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbdeviceinitialize)