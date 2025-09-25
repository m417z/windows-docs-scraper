# EVT_SERCX2_PURGE_FIFOS callback function

## Description

The *EvtSerCx2PurgeFifos* event callback function is called by version 2 of the serial framework extension (SerCx2) to purge the FIFO buffers in the serial controller hardware.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller. The serial controller driver created this object in its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function. For more information, see [SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice).

### `PurgeRxFifo` [in]

Whether to purge the receive FIFO. If this parameter is set to **TRUE**, purge the receive FIFO. If **FALSE**, do not purge the receive FIFO.

### `PurgeTxFifo` [in]

Whether to purge the transmit FIFO. If this parameter is set to **TRUE**, purge the transmit FIFO. If **FALSE**, do not purge the transmit FIFO.

## Remarks

Your serial controller driver must implement this function. The driver registers the function in the call to the [SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice) method that finishes the initialization of the framework device object for the serial controller.

SerCx2 calls the *EvtSerCx2PurgeFifos* function when a client (peripheral driver) sends an [IOCTL_SERIAL_PURGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_purge) control request that requires either one or both of the FIFO buffers in the serial controller hardware to be purged. If the **IOCTL_SERIAL_PURGE** control request requires pending read or write ([IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read) or [IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)) requests to be canceled, SerCx2 cancels these requests before it calls the *EvtSerCx2PurgeFifos* function.

SerCx2 also calls the *EvtSerCx2PurgeFifos* function when a client opens a logical connection to the serial controller device and obtains a file handle to this connection. For more information, see [Framework File Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-file-objects).

#### Examples

To define an *EvtSerCx2PurgeFifos* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *EvtSerCx2PurgeFifos* callback function that is named `MyPurgeFifos`, use the **EVT_SERCX2_PURGE_FIFOS** function type, as shown in this code example:

```cpp
EVT_SERCX2_PURGE_FIFOS  MyPurgeFifos;
```

Then, implement your callback function as follows:

```cpp
_Use_decl_annotations_
VOID
  MyPurgeFifos(
    WDFDEVICE  Device,
    BOOLEAN PurgeRxFifo,
    BOOLEAN PurgeTxFifo
    )
  {...}
```

The **EVT_SERCX2_PURGE_FIFOS** function type is defined in the Sercx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **EVT_SERCX2_PURGE_FIFOS** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[IOCTL_SERIAL_PURGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_purge)

[SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice)