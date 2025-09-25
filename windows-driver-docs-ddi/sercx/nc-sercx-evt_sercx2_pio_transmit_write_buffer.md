# EVT_SERCX2_PIO_TRANSMIT_WRITE_BUFFER callback function

## Description

The *EvtSerCx2PioTransmitWriteBuffer* event callback function is called by version 2 of the serial framework extension (SerCx2) to use programmed I/O (PIO) to transfer the contents of a write buffer to the transmit FIFO in the serial controller.

## Parameters

### `PioTransmit` [in]

A [SERCX2PIOTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a PIO-transmit object. The serial controller driver previously called the [SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate) method to create this object.

### `Buffer` [in]

A pointer to the write buffer. This parameter is the virtual address of a locked-down buffer in system memory.

### `Length` [in]

The number of bytes in the write buffer that are available to be transmitted.

## Return value

The *EvtSerCx2PioTransmitWriteBuffer* function returns the number of bytes of data it successfully transferred from the write buffer to the transmit FIFO in the serial controller hardware.

## Remarks

Your serial controller driver must implement this function. The driver registers the function in the [SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate) call that creates the PIO-transmit object.

SerCx2 might call the *EvtSerCx2PioTransmitWriteBuffer* function more than once during a PIO-transmit transaction. A single *EvtSerCx2PioTransmitWriteBuffer* call is sufficient if this call can transfer the full contents of the write buffer to the transmit FIFO. Otherwise, SerCx2 continues to call this function, as more space becomes available in the transmit FIFO, until the write buffer is emptied.

Starting with the first byte in the write buffer, the *EvtSerCx2PioTransmitWriteBuffer* function uses PIO to transfer as many bytes as it can from the buffer to the transmit FIFO. The function continues to transfer data from the buffer for as long as the buffer is not empty and the *line status register* (LSR) indicates that the FIFO can accept more data. If the LSR indicates that the FIFO can accept no more data, the function returns without emptying the buffer. Otherwise, the function transfers all the bytes in the buffer and returns. In either case, the value returned by this function is the number of bytes of data that were successfully transferred from the write buffer to the transmit FIFO.

Typically, the *EvtSerCx2PioTransmitWriteBuffer* function does not enable any interrupts. Instead, if the function is unable to transfer the entire contents of the write buffer to the transmit FIFO, SerCx2 calls the [EvtSerCx2PioTransmitEnableReadyNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_enable_ready_notification) event callback function to enable a ready notification, and this function enables an interrupt that occurs when the transmit FIFO becomes empty.

For each successive call to the *EvtSerCx2PioTransmitWriteBuffer* function, SerCx2 adjusts *Buffer* to point to the remaining data in the buffer, and sets *Length* to the number of data bytes that remain in the buffer.

The ready notification is never enabled when SerCx2 calls the *EvtSerCx2PioTransmitEnableReadyNotification* function. However, SerCx2 might call this function from the same thread from which the driver called the [SerCx2PioTransmitReady](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitready) method.

If the driver implements an [EvtSerCx2PioTransmitInitializeTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_initialize_transaction) function, SerCx2 calls this function at the start of a PIO-transmit transaction, before the first call to the *EvtSerCx2PioTransmitWriteBuffer* function. If the driver implements an [EvtSerCx2PioTransmitCleanupTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_cleanup_transaction) function, SerCx2 calls this function at the end of a PIO-transmit transaction, after the last *EvtSerCx2PioTransmitWriteBuffer* call, and after any calls to the [EvtSerCx2PioTransmitDrainFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_drain_fifo), [EvtSerCx2PioTransmitCancelDrainFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_cancel_drain_fifo), and [EvtSerCx2PioTransmitPurgeFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_purge_fifo) functions, if they are implemented.

For more information about PIO-transmit transactions, see [SerCx2 PIO-Transmit Transactions](https://learn.microsoft.com/previous-versions/dn265336(v=vs.85)).

#### Examples

To define an *EvtSerCx2PioTransmitWriteBuffer* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *EvtSerCx2PioTransmitWriteBuffer* callback function that is named `MyPioTransmitWriteBuffer`, use the **EVT_SERCX2_PIO_TRANSMIT_WRITE_BUFFER** function type, as shown in this code example:

```cpp
EVT_SERCX2_PIO_TRANSMIT_WRITE_BUFFER  MyPioTransmitWriteBuffer;
```

Then, implement your callback function as follows:

```cpp
_Use_decl_annotations_
ULONG
  MyPioTransmitWriteBuffer(
    SERCX2PIOTRANSMIT  PioTransmit,
    PUCHAR Buffer,
    ULONG Length
    )
  {...}
```

The **EVT_SERCX2_PIO_TRANSMIT_WRITE_BUFFER** function type is defined in the Sercx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **EVT_SERCX2_PIO_TRANSMIT_WRITE_BUFFER** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[EvtSerCx2PioTransmitCancelDrainFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_cancel_drain_fifo)

[EvtSerCx2PioTransmitDrainFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_drain_fifo)

[EvtSerCx2PioTransmitEnableReadyNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_enable_ready_notification)

[EvtSerCx2PioTransmitInitializeTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_initialize_transaction)

[EvtSerCx2PioTransmitPurgeFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_purge_fifo)

[SERCX2PIOTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate)