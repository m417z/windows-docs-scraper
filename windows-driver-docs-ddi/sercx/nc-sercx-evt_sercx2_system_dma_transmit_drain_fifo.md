# EVT_SERCX2_SYSTEM_DMA_TRANSMIT_DRAIN_FIFO callback function

## Description

The *EvtSerCx2SystemDmaTransmitDrainFifo* event callback function is called by version 2 of the serial framework extension (SerCx2) to drain the transmit FIFO in the serial controller hardware.

## Parameters

### `SystemDmaTransmit` [in]

A [SERCX2SYSTEMDMATRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a system-DMA-transmit object. The serial controller driver previously called the [SerCx2SystemDmaTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmatransmitcreate) method to create this object.

## Remarks

Your serial controller driver can, as an option, implement this function. If your driver implements this function, it must also implement the [EvtSerCx2SystemDmaTransmitCancelDrainFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_transmit_cancel_drain_fifo) and [EvtSerCx2SystemDmaTransmitPurgeFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_transmit_purge_fifo) event callback functions. A driver that implements these functions registers them in the [SerCx2SystemDmaTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmatransmitcreate) call that creates the system-DMA-transmit object.

SerCx2 calls the *EvtSerCx2SystemDmaTransmitDrainFifo* function, if it is implemented, to drain the transmit FIFO in the serial controller hardware at the end of a system-DMA-transmit transaction. This function makes sure that any data bytes that remain in the FIFO are transmitted to the serially connected peripheral device. After the last byte is transmitted from the FIFO, the *EvtSerCx2SystemDmaTransmitDrainFifo* function calls the [SerCx2SystemDmaTransmitDrainFifoComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmatransmitdrainfifocomplete) method to notify SerCx2.

If the serial controller driver implements an *EvtSerCx2SystemDmaTransmitDrainFifo* function, SerCx2 does not complete a pending write ([IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)) request until the driver calls **SerCx2SystemDmaTransmitDrainFifoComplete**.

If your serial controller has a hardware FIFO (or similar buffering mechanism) to hold transmit data, your driver should implement an *EvtSerCx2SystemDmaTransmitDrainFifo* function. Otherwise, SerCx2 cannot confirm that the transmit FIFO has drained before the pending write request is completed. Instead, SerCx2 completes this request after the last byte in the write buffer is written to the transmit FIFO. There can be no guarantee that data written to the transmit FIFO will be transmitted without a significant delay. Any data that remains in the FIFO after the write request is completed might be lost before it can be transmitted to the serially connected peripheral device. This unexpected data loss in a successfully completed write request can create reliability problems for the peripheral driver.

For more information, see [SerCx2 System-DMA-Transmit Transactions](https://learn.microsoft.com/previous-versions/dn265338(v=vs.85)).

#### Examples

To define an *EvtSerCx2SystemDmaTransmitDrainFifo* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *EvtSerCx2SystemDmaTransmitDrainFifo* callback function that is named `MySystemDmaTransmitDrainFifo`, use the **EVT_SERCX2_SYSTEM_DMA_TRANSMIT_DRAIN_FIFO** function type, as shown in this code example:

```cpp
EVT_SERCX2_SYSTEM_DMA_TRANSMIT_DRAIN_FIFO  MySystemDmaTransmitDrainFifo;
```

Then, implement your callback function as follows:

```cpp
_Use_decl_annotations_
VOID
  MySystemDmaTransmitDrainFifo(
    SERCX2SYSTEMDMATRANSMIT  SystemDmaTransmit
    )
  {...}
```

The **EVT_SERCX2_SYSTEM_DMA_TRANSMIT_DRAIN_FIFO** function type is defined in the Sercx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **EVT_SERCX2_SYSTEM_DMA_TRANSMIT_DRAIN_FIFO** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[EvtSerCx2SystemDmaTransmitCancelDrainFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_transmit_cancel_drain_fifo)

[EvtSerCx2SystemDmaTransmitPurgeFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_transmit_purge_fifo)

[IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)

[SERCX2SYSTEMDMATRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2SystemDmaTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmatransmitcreate)

[SerCx2SystemDmaTransmitDrainFifoComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmatransmitdrainfifocomplete)