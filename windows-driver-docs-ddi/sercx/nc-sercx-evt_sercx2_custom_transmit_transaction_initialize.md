# EVT_SERCX2_CUSTOM_TRANSMIT_TRANSACTION_INITIALIZE callback function

## Description

The *EvtSerCx2CustomTransmitTransactionInitialize* event callback function is called by version 2 of the serial framework extension (SerCx2) to prepare the serial controller driver to perform a custom-transmit transaction.

## Parameters

### `CustomTransmitTransaction` [in]

A [SERCX2CUSTOMTRANSMITTRANSACTION](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a custom-transmit object. The serial controller driver previously called the [SerCx2CustomTransmitTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customtransmittransactioncreate) method to create this object.

### `Mdl` [in]

A pointer to an [MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) that describes the memory pages that are spanned by the write buffer for the custom-transmit transaction. The scatter/gather list for the DMA transfer will use the region of this memory that is specified by the *Offset* and *Length* parameters.

### `Offset` [in]

The starting offset for the data transfer. This parameter is a byte offset from the start of the buffer region described by the MDL. If the MDL specifies a total of N bytes of buffer space, possible values of *Offset* are in the range 0 to N–1.

### `Length` [in]

The size, in bytes, of the data transfer. If the MDL specifies a total of N bytes of buffer space, possible values of *Length* are in the range 1 to N–*Offset*.

## Remarks

Your serial controller driver can, as an option, implement this function. If implemented, the driver registers the function in the [SerCx2CustomTransmitTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customtransmittransactioncreate) call that creates the custom-transmit object.

Your driver should implement an *EvtSerCx2CustomTransmitTransactionInitialize* function if it needs to initialize the serial controller and associated hardware in preparation for a new custom-transmit transaction. SerCx2 calls this function, if it is implemented, before starting the custom-transmit transaction. In response to this call, the serial controller driver must call the [SerCx2CustomTransmitTransactionInitializeComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customtransmittransactioninitializecomplete) method to notify SerCx2 after the initialization is finished.

For more information, see [SerCx2 Custom-Transmit Transactions](https://learn.microsoft.com/previous-versions/dn265320(v=vs.85)).

#### Examples

To define an *EvtSerCx2CustomTransmitTransactionInitialize* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *EvtSerCx2CustomTransmitTransactionInitialize* callback function that is named `MyCustomTransmitTransactionInitialize`, use the **EVT_SERCX2_CUSTOM_TRANSMIT_TRANSACTION_INITIALIZE** function type, as shown in this code example:

```cpp
EVT_SERCX2_CUSTOM_TRANSMIT_TRANSACTION_INITIALIZE  MyCustomTransmitTransactionInitialize;
```

Then, implement your callback function as follows:

```cpp
_Use_decl_annotations_
VOID
  MyCustomTransmitTransactionInitialize(
    SERCX2CUSTOMTRANSMITTRANSACTION  CustomTransmitTransaction,
    WDFREQUEST  Request,
    PMDL  Mdl,
    ULONG  Offset,
    ULONG  Length
    )
  {...}
```

The **EVT_SERCX2_CUSTOM_TRANSMIT_TRANSACTION_INITIALIZE** function type is defined in the Sercx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **EVT_SERCX2_CUSTOM_TRANSMIT_TRANSACTION_INITIALIZE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)

[MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)

[SERCX2CUSTOMTRANSMITTRANSACTION](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2CustomTransmitTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customtransmittransactioncreate)