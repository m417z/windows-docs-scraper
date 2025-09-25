# EVT_SERCX2_CUSTOM_RECEIVE_TRANSACTION_START callback function

## Description

The *EvtSerCx2CustomReceiveTransactionStart* event callback function is called by version 2 of the serial framework extension (SerCx2) to start a custom-receive transaction.

## Parameters

### `CustomReceiveTransaction` [in]

A [SERCX2CUSTOMRECEIVETRANSACTION](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a custom-receive-transaction object. The serial controller driver previously called the [SerCx2CustomReceiveTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivetransactioncreate) method to create this object.

### `Request` [in]

A handle to the framework request object associated with the custom-receive transaction. The driver is responsible for completing this request. This request might not be the [IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read) request sent by the client, and thus the serial controller driver should not try to use this request to access the read buffer. This request is primarily used for cancellation, completion, and queue forwarding (if needed). To access the read buffer for the client's read request, use the *Mdl*, *Offset*, and *Length* parameters.

### `Mdl` [in]

A pointer to an [MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) that describes the memory pages that are spanned by the read buffer for the custom-receive transaction. The scatter/gather list for the data transfer will use the region of this memory that is specified by the *Offset* and *Length* parameters.

### `Offset` [in]

The starting offset for the data transfer. This parameter is a byte offset from the start of the buffer region described by the MDL. If the MDL specifies a total of N bytes of buffer space, possible values of *Offset* are in the range 0 to N–1.

### `Length` [in]

The size, in bytes, of the data transfer. If the MDL specifies a total of N bytes of buffer space, possible values of *Length* are in the range 1 to N–*Offset*.

## Remarks

Your serial controller driver must implement this function if it creates a custom-receive-transaction object. The driver registers the function in the [SerCx2CustomReceiveTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivetransactioncreate) call that creates this object.

After SerCx2 calls the *EvtSerCx2CustomReceiveTransactionStart* function, the serial controller driver initiates the transaction by programming the custom data-transfer mechanism to move data from the receive FIFO in the serial controller hardware to the buffer in the read request. Unless the request can be completed immediately, before the *EvtSerCx2CustomReceiveTransactionStart* function returns, the driver must call a method such as [WdfRequestMarkCancelableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelableex) to mark the request as cancelable.

After the *EvtSerCx2CustomReceiveTransactionStart* function starts the transaction, SerCx2 periodically calls the [EvtSerCx2CustomReceiveTransactionQueryProgress](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn265203(v=vs.85)) event callback function to monitor progress made by the serial controller driver in performing this transaction. After the transaction finishes and the driver completes the pending read request, SerCx2 calls the [EvtSerCx2CustomReceiveTransactionCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_custom_receive_transaction_cleanup) event callback function, if the driver implements this function.

If the serial controller driver implements an [EvtSerCx2CustomReceiveTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_custom_receive_transaction_initialize) event callback function, SerCx2 calls this function before calling the *EvtSerCx2CustomReceiveTransactionStart* function. Just before the *EvtSerCx2CustomReceiveTransactionStart* call, and after the *EvtSerCx2CustomReceiveTransactionInitialize* call returns, SerCx2 starts the timer that detects whether the read request times out. For more information, see the discussion of total time-outs in [SERIAL_TIMEOUTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_timeouts).

If the custom data-transfer mechanism is a bus-master DMA device, the *EvtSerCx2CustomReceiveTransactionStart* function can call a method such as [WdfDmaTransactionInitializeUsingOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitializeusingoffset) to initiate a DMA transaction that uses the read buffer described by the *Mdl*, *Offset*, and *Length* parameters.

If the request object identified by the *Request* parameter contains storage for a private context, this storage might be uninitialized the first time the serial controller driver accesses the context. On first access, the driver typically should fill the context with zeros, and then, if needed, explicitly set any fields in the context that require nonzero initial values.

For more information, see [SerCx2 Custom-Receive Transactions](https://learn.microsoft.com/previous-versions/dn265314(v=vs.85)).

#### Examples

To define an *EvtSerCx2CustomReceiveTransactionStart* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *EvtSerCx2CustomReceiveTransactionStart* callback function that is named `MyCustomReceiveTransactionStart`, use the **EVT_SERCX2_CUSTOM_RECEIVE_TRANSACTION_START** function type, as shown in this code example:

```cpp
EVT_SERCX2_CUSTOM_RECEIVE_TRANSACTION_START  MyCustomReceiveTransactionStart;
```

Then, implement your callback function as follows:

```cpp
_Use_decl_annotations_
VOID
  MyCustomReceiveTransactionStart(
    SERCX2CUSTOMRECEIVETRANSACTION  CustomReceiveTransaction,
    WDFREQUEST  Request,
    PMDL  Mdl,
    ULONG  Offset,
    ULONG  Length
    )
  {...}
```

The **EVT_SERCX2_CUSTOM_RECEIVE_TRANSACTION_START** function type is defined in the Sercx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **EVT_SERCX2_CUSTOM_RECEIVE_TRANSACTION_START** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read)

[MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)

[SERCX2CUSTOMRECEIVETRANSACTION](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SERIAL_TIMEOUTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_timeouts)

[SerCx2CustomReceiveTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivetransactioncreate)

[WdfDmaTransactionInitializeUsingOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitializeusingoffset)

[WdfRequestMarkCancelableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelableex)