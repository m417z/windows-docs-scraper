# EVT_SERCX2_PIO_TRANSMIT_PURGE_FIFO callback function

## Description

The *EvtSerCx2PioTransmitPurgeFifo* event callback function is called by version 2 of the serial framework extension (SerCx2) to discard any bytes of unsent data that remain in the transmit FIFO in the serial controller.

## Parameters

### `PioTransmit` [in]

A [SERCX2PIOTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a PIO-transmit object. The serial controller driver previously called the [SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate) method to create this object.

### `BytesAlreadyTransmittedToHardware` [in]

The number of bytes that have already been loaded into the transmit FIFO during the current PIO-transmit transaction. This parameter is the sum of all the bytes transferred in previous calls to the [EvtSerCx2PioTransmitWriteBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_write_buffer) event callback function that are part of this transaction.

## Remarks

Your serial controller driver can, as an option, implement this function. If implemented, the driver registers the function in the [SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate) call that creates the PIO-transmit object.

Your driver should implement an *EvtSerCx2PioTransmitPurgeFifo* function if the serial controller has a hardware FIFO (or similar buffering mechanism) to hold transmit data. If your driver implements this function, it must also implement the [EvtSerCx2PioTransmitDrainFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_drain_fifo) and [EvtSerCx2PioTransmitCancelDrainFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_cancel_drain_fifo) event callback functions.

SerCx2 initiates a PIO-transmit transaction in response to a write ([IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)) request from a client. If this request times out or is canceled before it completes, SerCx2 calls the *EvtSerCx2PioTransmitPurgeFifo* function, if it is implemented, to purge any unsent data that might remain the transmit FIFO.

After the transmit FIFO is purged, the *EvtSerCx2PioTransmitPurgeFifo* function must call the [SerCx2PioTransmitPurgeFifoComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitpurgefifocomplete) method to notify SerCx2 that the FIFO was purged, and SerCx2 then completes the write request.

For more information, see [SerCx2 PIO-Transmit Transactions](https://learn.microsoft.com/previous-versions/dn265336(v=vs.85)).

#### Examples

To define an *EvtSerCx2PioTransmitPurgeFifo* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *EvtSerCx2PioTransmitPurgeFifo* callback function that is named `MyPioTransmitPurgeFifo`, use the **EVT_SERCX2_PIO_TRANSMIT_PURGE_FIFO** function type, as shown in this code example:

```cpp
EVT_SERCX2_PIO_TRANSMIT_PURGE_FIFO  MyPioTransmitPurgeFifo;
```

Then, implement your callback function as follows:

```cpp
_Use_decl_annotations_
VOID
  MyPioTransmitPurgeFifo(
    SERCX2PIOTRANSMIT  PioTransmit,
    ULONG  BytesAlreadyTransmittedToHardware

    )
  {...}
```

The **EVT_SERCX2_PIO_TRANSMIT_PURGE_FIFO** function type is defined in the Sercx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **EVT_SERCX2_PIO_TRANSMIT_PURGE_FIFO** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[EvtSerCx2SystemDmaTransmitCancelDrainFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_transmit_cancel_drain_fifo)

[EvtSerCx2SystemDmaTransmitDrainFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_transmit_drain_fifo)

[IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)

[SERCX2PIOTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate)

[SerCx2PioTransmitPurgeFifoComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitpurgefifocomplete)