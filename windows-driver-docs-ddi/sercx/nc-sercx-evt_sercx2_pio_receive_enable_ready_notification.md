# EVT_SERCX2_PIO_RECEIVE_ENABLE_READY_NOTIFICATION callback function

## Description

The *EvtSerCx2PioReceiveEnableReadyNotification* event callback function is called by version 2 of the serial framework extension (SerCx2) to enable the serial controller driver to notify SerCx2 when the serial controller receives new data.

## Parameters

### `PioReceive` [in]

A [SERCX2PIORECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a PIO-receive object. The serial controller driver previously called the [SerCx2PioReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2pioreceivecreate) method to create this object.

## Remarks

Your serial controller driver must implement this function. The driver registers the function in the [SerCx2PioReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2pioreceivecreate) call that creates the PIO-receive object.

After the *EvtSerCx2PioReceiveEnableReadyNotification* function is called to enable a ready notification for a PIO-receive transaction, the serial controller driver must call the [SerCx2PioReceiveReady](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2pioreceiveready) method to notify SerCx2 when the driver detects that one or more bytes of data are available to be read from the receive FIFO in the serial controller hardware. If data is already available in the receive FIFO when the ready notification is enabled, the driver immediately calls this method to notify SerCx2.

The ready notification for a PIO-receive transaction is a one-shot notification. After sending a ready notification to SerCx2, the serial controller driver sends no further notifications until SerCx2 calls the *EvtSerCx2PioReceiveEnableReadyNotification* function to enable another notification.

An [EvtSerCx2PioReceiveReadBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_read_buffer) event callback function call might only partially complete a PIO-receive transaction because no more data is immediately available to be read from the receive FIFO. In this case, SerCx2 calls the *EvtSerCx2PioReceiveEnableReadyNotification* function to enable a ready notification, in which case the serial controller driver must notify SerCx2 when the receive FIFO contains more data. In response to this notification, SerCx2 resumes the partially completed receive transaction by calling the *EvtSerCx2PioReceiveReadBuffer* function again.

Typically, an *EvtSerCx2PioReceiveEnableReadyNotification* function enables an interrupt that occurs when the serial controller has more data available to be read. In response to this interrupt, the serial controller driver calls **SerCx2PioReceiveReady**.

No more than one ready notification can be pending at a time. After SerCx2 calls the *EvtSerCx2PioReceiveEnableReadyNotification* function to enable a ready notification, SerCx2 does not call this function again until the controller driver calls **SerCx2PioReceiveReady**.

SerCx2 never calls the *EvtSerCx2PioReceiveReadBuffer* function when the ready notification is enabled.

A pending ready notification can be canceled if the associated read request times out or is canceled. To cancel a ready notification for a PIO-receive transaction, SerCx2 calls the [EvtSerCx2PioReceiveCancelReadyNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_cancel_ready_notification) event callback function.

SerCx2 uses ready notifications to efficiently manage interval time-outs that occur during the handling of read requests that are processed as PIO-receive transactions.

For more information, see [SerCx2 PIO-Receive Transactions](https://learn.microsoft.com/previous-versions/dn265332(v=vs.85)).

#### Examples

To define an *EvtSerCx2PioReceiveEnableReadyNotification* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *EvtSerCx2PioReceiveEnableReadyNotification* callback function that is named `MyPioReceiveEnableReadyNotification`, use the **EVT_SERCX2_PIO_RECEIVE_ENABLE_READY_NOTIFICATION** function type, as shown in this code example:

```cpp
EVT_SERCX2_PIO_RECEIVE_ENABLE_READY_NOTIFICATION  MyPioReceiveEnableReadyNotification;
```

Then, implement your callback function as follows:

```cpp
_Use_decl_annotations_
VOID
  MyPioReceiveEnableReadyNotification(
    SERCX2PIORECEIVE  PioReceive
    )
  {...}
```

The **EVT_SERCX2_PIO_RECEIVE_ENABLE_READY_NOTIFICATION** function type is defined in the Sercx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **EVT_SERCX2_PIO_RECEIVE_ENABLE_READY_NOTIFICATION** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[EvtSerCx2PioReceiveCancelReadyNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_cancel_ready_notification)

[EvtSerCx2PioReceiveCleanupTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_cleanup_transaction)

[IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read)

[SERCX2PIORECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2PioReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2pioreceivecreate)

[SerCx2PioReceiveReady](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2pioreceiveready)