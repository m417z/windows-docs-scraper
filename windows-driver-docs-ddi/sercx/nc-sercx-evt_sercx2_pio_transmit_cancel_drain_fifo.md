# EVT_SERCX2_PIO_TRANSMIT_CANCEL_DRAIN_FIFO callback function

## Description

The *EvtSerCx2PioTransmitCancelDrainFifo* event callback function is called by version 2 of the serial framework extension (SerCx2) to cancel a previous request to drain the transmit FIFO in the serial controller hardware.

## Parameters

### `PioTransmit` [in]

A [SERCX2PIOTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a PIO-transmit object. The serial controller driver previously called the [SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate) method to create this object.

## Return value

The *EvtSerCx2PioTransmitCancelDrainFifo* function returns **TRUE** if it successfully cancels the pending drain request, and the serial controller driver can guarantee that it will not call the [SerCx2PioTransmitDrainFifoComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitdrainfifocomplete) method to notify SerCx2 that the FIFO is drained. Otherwise, this function returns **FALSE** to indicate that the driver has already called or is about to call **SerCx2PioTransmitDrainFifoComplete**.

## Remarks

Your serial controller driver can, as an option, implement this function. If implemented, the driver registers the function in the [SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate) call that creates the PIO-transmit object.

Your driver should implement an *EvtSerCx2PioTransmitCancelDrainFifo* function if the serial controller has a hardware FIFO (or similar buffering mechanism) to hold transmit data. If your driver implements this function, it must also implement the [EvtSerCx2PioTransmitDrainFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_drain_fifo) and [EvtSerCx2PioTransmitPurgeFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_purge_fifo) event callback functions.

SerCx2 calls the *EvtSerCx2PioTransmitDrainFifo* event callback function to ask the serial controller driver to drain the transmit FIFO, and then waits for the serial controller driver to call [SerCx2PioTransmitDrainFifoComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitdrainfifocomplete). A drain operation can take an indefinite amount of time to finish. Thus, if the write request times out or is canceled while the drain operation is in progress, SerCx2 calls the *EvtSerCx2PioTransmitCancelDrainFifo* function to cancel the pending drain operation before it finishes.

For more information, see [SerCx2 PIO-Transmit Transactions](https://learn.microsoft.com/previous-versions/dn265336(v=vs.85)).

#### Examples

To define an *EvtSerCx2PioTransmitCancelDrainFifo* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *EvtSerCx2PioTransmitCancelDrainFifo* callback function that is named `MyPioTransmitCancelDrainFifo`, use the **EVT_SERCX2_PIO_TRANSMIT_CANCEL_DRAIN_FIFO** function type, as shown in this code example:

```cpp
EVT_SERCX2_PIO_TRANSMIT_CANCEL_DRAIN_FIFO  MyPioTransmitCancelDrainFifo;
```

Then, implement your callback function as follows:

```cpp
_Use_decl_annotations_
BOOLEAN
  MyPioTransmitCancelDrainFifo(
    SERCX2PIOTRANSMIT  PioTransmit
    )
  {...}
```

The **EVT_SERCX2_PIO_TRANSMIT_CANCEL_DRAIN_FIFO** function type is defined in the Sercx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **EVT_SERCX2_PIO_TRANSMIT_CANCEL_DRAIN_FIFO** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[EvtSerCx2PioTransmitDrainFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_drain_fifo)

[EvtSerCx2PioTransmitPurgeFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_purge_fifo)

[IOCTL_SERIAL_PURGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_purge)

[IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)

[SERCX2PIOTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate)

[SerCx2PioTransmitDrainFifoComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitdrainfifocomplete)