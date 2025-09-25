# EVT_SERCX2_PIO_TRANSMIT_CANCEL_READY_NOTIFICATION callback function

## Description

The *EvtSerCx2PioTransmitCancelReadyNotification* event callback function is called by version 2 of the serial framework extension (SerCx2) to cancel a ready notification that SerCx2 enabled in a previous call to the [EvtSerCx2PioTransmitEnableReadyNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_enable_ready_notification) event callback function.

## Parameters

### `PioTransmit` [in]

A [SERCX2PIOTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a PIO-transmit object. The serial controller driver previously called the [SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate) method to create this object.

## Return value

The *EvtSerCx2PioTransmitCancelReadyNotification* function returns **TRUE** if the ready notification was successfully disabled and the serial controller driver can guarantee that this notification will not cause the [SerCx2PioTransmitReady](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitready) method to be called.

The function returns **FALSE** if the driver has already called **SerCx2PioTransmitReady**, or is about to call this method.

## Remarks

Your serial controller driver must implement this function. The driver registers the function in the [SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate) call that creates the PIO-transmit object.

If the associated write request times out or is canceled while a ready notification is enabled, SerCx2 calls the *EvtSerCx2PioTransmitCancelReadyNotification* function to cancel the pending notification. If this call returns **FALSE**, SerCx2 expects the serial controller driver to call [SerCx2PioTransmitReady](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitready); only after this call does SerCx2 call the [EvtSerCx2PioTransmitCleanupTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_cleanup_transaction) event callback function, if it is implemented, and complete the request.

To cancel a previously enabled ready notification, the *EvtSerCx2PioTransmitCancelReadyNotification* function typically disables the interrupt in the serial controller that indicates that the transmit FIFO is ready to accept more data. SerCx2 enabled this interrupt in a previous call to the [EvtSerCx2PioTransmitEnableReadyNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_enable_ready_notification) function.

For more information, see [SerCx2 PIO-Transmit Transactions](https://learn.microsoft.com/previous-versions/dn265336(v=vs.85)).

#### Examples

To define an *EvtSerCx2PioTransmitCancelReadyNotification* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *EvtSerCx2PioTransmitCancelReadyNotification* callback function that is named `MyPioTransmitCancelReadyNotification`, use the **EVT_SERCX2_PIO_TRANSMIT_CANCEL_READY_NOTIFICATION** function type, as shown in this code example:

```cpp
EVT_SERCX2_PIO_TRANSMIT_CANCEL_READY_NOTIFICATION  MyPioTransmitCancelReadyNotification;
```

Then, implement your callback function as follows:

```cpp
_Use_decl_annotations_
BOOLEAN
  MyPioTransmitCancelReadyNotification(
    SERCX2PIOTRANSMIT  PioTransmit
    )
  {...}
```

The **EVT_SERCX2_PIO_TRANSMIT_CANCEL_READY_NOTIFICATION** function type is defined in the Sercx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **EVT_SERCX2_PIO_TRANSMIT_CANCEL_READY_NOTIFICATION** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[EvtSerCx2PioTransmitEnableReadyNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_enable_ready_notification)

[SERCX2PIOTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate)

[SerCx2PioTransmitReady](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitready)