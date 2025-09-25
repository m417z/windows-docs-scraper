# EVT_SERCX2_CUSTOM_RECEIVE_TRANSACTION_INITIALIZE callback function

## Description

The *EvtSerCx2CustomReceiveTransactionInitialize* event callback function is called by version 2 of the serial framework extension (SerCx2) to prepare the serial controller hardware to perform a new custom-receive transaction.

## Parameters

### `CustomReceiveTransaction` [in]

A [SERCX2CUSTOMRECEIVETRANSACTION](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a custom-receive-transaction object. The serial controller driver previously called the [SerCx2CustomReceiveTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivetransactioncreate) method to create this object.

### `Mdl` [in]

A pointer to an [MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) that describes the memory pages that are spanned by the read buffer for the custom-receive transaction. The scatter/gather list for the DMA transfer will use the region of this memory that is specified by the *Offset* and *Length* parameters.

### `Offset` [in]

The starting offset for the data transfer. This parameter is a byte offset from the start of the buffer region described by the MDL. If the MDL specifies a total of N bytes of buffer space, possible values of *Offset* are in the range 0 to N–1.

### `Length` [in]

The size, in bytes, of the data transfer. If the MDL specifies a total of N bytes of buffer space, possible values of *Length* are in the range 1 to N–*Offset*.

## Remarks

Your serial controller driver can, as an option, implement this function. If implemented, the driver registers the function in the [SerCx2CustomReceiveTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivetransactioncreate) call that creates the custom-receive object.

Your driver should implement an *EvtSerCx2CustomReceiveTransactionInitialize* function if it needs to initialize the serial controller and associated hardware in preparation for a new custom-receive transaction. SerCx2 calls this function, if it is implemented, before starting the custom-receive transaction. In response to this call, the serial controller driver must call the [SerCx2CustomReceiveTransactionInitializeComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivetransactioninitializecomplete) method to notify SerCx2 after the initialization is finished.

For more information, see [SerCx2 Custom-Receive Transactions](https://learn.microsoft.com/previous-versions/dn265314(v=vs.85)).

#### Examples

To define an *EvtSerCx2CustomReceiveTransactionInitialize* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *EvtSerCx2CustomReceiveTransactionInitialize* callback function that is named `MyCustomReceiveTransactionInitialize`, use the **EVT_SERCX2_CUSTOM_RECEIVE_TRANSACTION_INITIALIZE** function type, as shown in this code example:

```cpp
EVT_SERCX2_CUSTOM_RECEIVE_TRANSACTION_INITIALIZE  MyCustomReceiveTransactionInitialize;
```

Then, implement your callback function as follows:

```cpp
_Use_decl_annotations_
VOID
  MyCustomReceiveTransactionInitialize(
    SERCX2CUSTOMRECEIVETRANSACTION  CustomReceiveTransaction,
    WDFREQUEST  Request,
    PMDL  Mdl,
    ULONG  Offset,
    ULONG  Length
    )
  {...}
```

The **EVT_SERCX2_CUSTOM_RECEIVE_TRANSACTION_INITIALIZE** function type is defined in the Sercx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **EVT_SERCX2_CUSTOM_RECEIVE_TRANSACTION_INITIALIZE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read)

[MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)

[SERCX2CUSTOMRECEIVETRANSACTION](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2CustomReceiveTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivetransactioncreate)

[SerCx2CustomReceiveTransactionInitializeComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivetransactioninitializecomplete)