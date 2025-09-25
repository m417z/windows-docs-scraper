# EVT_SERCX2_PIO_TRANSMIT_CLEANUP_TRANSACTION callback function

## Description

The *EvtSerCx2PioTransmitCleanupTransaction* event callback function is called by version 2 of the serial framework extension (SerCx2) to clean up the serial controller state after a PIO-transmit transaction ends.

## Parameters

### `PioTransmit` [in]

A [SERCX2PIOTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a PIO-transmit object. The serial controller driver previously called the [SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate) method to create this object.

## Remarks

Your serial controller driver can, as an option, implement this function. If implemented, the driver registers the function in the [SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate) call that creates the PIO-transmit object.

Your serial controller driver should implement an *EvtSerCx2PioTransmitCleanupTransaction* function if it needs to clean up the serial controller state at the end of a PIO-transmit transaction. SerCx2 calls this function, if it is implemented, after a PIO-transmit transaction ends. In response to the *EvtSerCx2PioTransmitCleanupTransaction* call, the serial controller driver must call the [SerCx2PioTransmitCleanupTransactionComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcleanuptransactioncomplete) method to notify SerCx2 after the clean-up work is done.

For more information, see [SerCx2 PIO-Transmit Transactions](https://learn.microsoft.com/previous-versions/dn265336(v=vs.85)).

#### Examples

To define an *EvtSerCx2PioTransmitCleanupTransaction* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *EvtSerCx2PioTransmitCleanupTransaction* callback function that is named `MyPioTransmitCleanupTransaction`, use the **EVT_SERCX2_PIO_TRANSMIT_CLEANUP_TRANSACTION** function type, as shown in this code example:

```cpp
EVT_SERCX2_PIO_TRANSMIT_CLEANUP_TRANSACTION  MyPioTransmitCleanupTransaction;
```

Then, implement your callback function as follows:

```cpp
_Use_decl_annotations_
VOID
  MyPioTransmitCleanupTransaction(
    SERCX2PIOTRANSMIT  PioTransmit
    )
  {...}
```

The **EVT_SERCX2_PIO_TRANSMIT_CLEANUP_TRANSACTION** function type is defined in the Sercx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **EVT_SERCX2_PIO_TRANSMIT_CLEANUP_TRANSACTION** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[SERCX2PIOTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2PioTransmitCleanupTransactionComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcleanuptransactioncomplete)

[SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate)