# EVT_SERCX2_PIO_RECEIVE_READ_BUFFER callback function

## Description

The *EvtSerCx2PioReceiveReadBuffer* event callback function is called by version 2 of the serial framework extension (SerCx2) to use programmed I/O (PIO) to transfer data from the receive FIFO in the serial controller to a read buffer.

## Parameters

### `PioReceive` [in]

A [SERCX2PIORECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a PIO-receive object. The serial controller driver previously called the [SerCx2PioReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2pioreceivecreate) method to create this object.

### `Buffer` [out]

A pointer to the read buffer. This parameter is the virtual address of a locked-down buffer in system memory.

### `Length` [in]

The number of bytes in the read buffer that are available to store received data.

## Return value

The *EvtSerCx2PioReceiveReadBuffer* function returns the number of bytes of data that it successfully transferred from the receive FIFO in the serial controller hardware to the read buffer.

## Remarks

Your serial controller driver must implement this function. The driver registers the function in the [SerCx2PioReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2pioreceivecreate) call that creates the PIO-receive object.

SerCx2 might call the *EvtSerCx2PioReceiveReadBuffer* function more than once during a PIO-receive transaction. A single *EvtSerCx2PioReceiveReadBuffer* call is sufficient if this call can fill the read buffer with data from the receive FIFO. Otherwise, SerCx2 continues to call this function, as more data becomes available in the receive FIFO, until the read buffer is filled.

The *EvtSerCx2PioReceiveReadBuffer* function uses PIO to transfer as many bytes as it can from the receive FIFO to the read buffer. The function continues to transfer data from the FIFO for as long as the buffer passed to this function is not full and the line status register (LSR) indicates that more data is available from the FIFO. If the LSR indicates that the FIFO is empty, the function returns without filling the buffer. Otherwise, the function fills the buffer and returns. In either case, the value returned by this function is the number of bytes of data that were successfully transferred to the read buffer from the receive FIFO.

Typically, the *EvtSerCx2PioReceiveReadBuffer* function does not enable any interrupts. Instead, if the receive FIFO runs out of data before the function can fill the read buffer, SerCx2 calls the [EvtSerCx2PioReceiveEnableReadyNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_enable_ready_notification) event callback function to enable a ready notification, and this function enables an interrupt that occurs when more data is available in the receive FIFO.

For each successive call to the *EvtSerCx2PioReceiveReadBuffer* function, SerCx2 adjusts *Buffer* to point to the next buffer region to be filled, and sets *Length* to the number of bytes of unfilled space that remain in the buffer.

The ready notification is never enabled when SerCx2 calls the *EvtSerCx2PioReceiveEnableReadyNotification* function. However, SerCx2 might call this function from the same thread from which the driver called the [SerCx2PioReceiveReady](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2pioreceiveready) method.

If the driver implements an [EvtSerCx2PioReceiveInitializeTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_initialize_transaction) function, SerCx2 calls this function at the start of a PIO-transmit transaction, before the first call to the *EvtSerCx2PioReceiveReadBuffer* function. If the driver implements an [EvtSerCx2PioReceiveCleanupTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_cleanup_transaction) function, SerCx2 calls this function at the end of a PIO-receive transaction, after the final call to the *EvtSerCx2PioReceiveReadBuffer* function.

In addition to calling the *EvtSerCx2PioReceiveReadBuffer* function during PIO-receive transactions, SerCx2 calls this function to save the state of the receive FIFO just before the serial controller exits the D0 device power state. For more information, see [SerCx2SaveReceiveFifoOnD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2savereceivefifoond0exit).

For more information about PIO-receive transactions, see [SerCx2 PIO-Receive Transactions](https://learn.microsoft.com/previous-versions/dn265332(v=vs.85)).

#### Examples

To define an *EvtSerCx2PioReceiveReadBuffer* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *EvtSerCx2PioReceiveReadBuffer* callback function that is named `MyPioReceiveReadBuffer`, use the **EVT_SERCX2_PIO_RECEIVE_READ_BUFFER** function type, as shown in this code example:

```cpp
EVT_SERCX2_PIO_RECEIVE_READ_BUFFER  MyPioReceiveReadBuffer;
```

Then, implement your callback function as follows:

```cpp
_Use_decl_annotations_
ULONG
  MyPioReceiveReadBuffer(
    SERCX2PIORECEIVE  PioReceive,
    PUCHAR  Buffer,
    ULONG  Length

    )
  {...}
```

The **EVT_SERCX2_PIO_RECEIVE_READ_BUFFER** function type is defined in the Sercx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **EVT_SERCX2_PIO_RECEIVE_READ_BUFFER** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[EvtSerCx2PioReceiveCleanupTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_cleanup_transaction)

[EvtSerCx2PioReceiveEnableReadyNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_enable_ready_notification)

[EvtSerCx2PioReceiveInitializeTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_initialize_transaction)

[SERCX2PIORECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2PioReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2pioreceivecreate)