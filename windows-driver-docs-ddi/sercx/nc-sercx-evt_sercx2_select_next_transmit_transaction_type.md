# EVT_SERCX2_SELECT_NEXT_TRANSMIT_TRANSACTION_TYPE callback function

## Description

The *EvtSerCx2SelectNextTransmitTransactionType* event callback function is called by version 2 of the serial framework extension (SerCx2) to determine which data-transfer mechanism to use for the next write operation.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller. The serial controller driver created this object in its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function. For more information, see [SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice).

### `Mdl` [in]

A pointer to an [MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) that describes the memory pages that are spanned by the write buffer for the next transmit transaction. The scatter/gather list for the DMA transfer will use the region of this memory that is specified by the *Offset* and *Length* parameters.

### `Offset` [in]

The starting offset for the next data transfer. This parameter is a byte offset from the start of the buffer region described by the MDL. If the MDL specifies a total of N bytes of buffer space, possible values of *Offset* are in the range 0 to N–1.

### `RemainingLength` [in]

The total number of bytes of data that remain to be transferred in the current write ([IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)) request. If the MDL specifies a total of N bytes of buffer space, possible values of *Length* are in the range 1 to N–*Offset*.

### `CustomTransmit` [out]

A pointer to a location to which the function writes the [SERCX2CUSTOMTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to the custom-transmit object. If the function returns **SerCx2TransactionTypeCustom**, the function must supply the object handle that the serial controller driver created in a previous call to the [SerCx2CustomTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customtransmitcreate) method. If the return value is not **SerCx2TransactionTypeCustom**, this output value is ignored by SerCx2.

### `NextTransactionLength` [out]

A pointer to a location to which the function writes the number of bytes to transfer in the next transmit transaction. If the return value is **SerCx2TransactionTypeDefault**, this output value is ignored by SerCx2.

## Return value

The *EvtSerCx2SelectNextTransmitTransactionType* function returns a [SERCX2_TRANSACTION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ne-sercx-_sercx2_transaction_type) enumeration constant to indicate whether to use a driver-selected transaction type (programmed I/O (PIO), system DMA, or custom data transfer), or to let SerCx2 choose which transaction type to use for the next transmit transaction.

## Remarks

Your serial controller driver can, as an option, implement this function. If implemented, the driver registers this function in the call to the [SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice) method that finishes the initialization of the framework device object for the serial controller.

If your serial controller driver does not implement an *EvtSerCx2SelectNextTransmitTransactionType* function, then SerCx2 always decides what type of data-transfer mechanism (PIO, system DMA, or custom) to use for the next transmit transaction. SerCx2 bases its decisions on the I/O configuration information supplied by the serial controller driver. A driver that supports system-DMA-transmit transactions supplies a [SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_transmit_config) structure that contains this information. A driver that supports custom-transmit transactions supplies a [SERCX2_CUSTOM_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_transmit_config) structure that contains this information.

If your serial controller driver implements an *EvtSerCx2SelectNextTransmitTransactionType* function, SerCx2 calls this function to determine what type of data-transfer mechanism (PIO, system DMA, or custom) to use for the next transmit transaction. You might want to implement this function if the serial controller has special hardware capabilities that cannot adequately be described by the I/O configuration information in the **SERCX2_*XXX*_TRANSMIT_CONFIG** structures.

**Note** Even if a serial controller driver implements an *EvtSerCx2SelectNextTransmitTransactionType* function, SerCx2 uses PIO-transmit transactions to perform certain types of data transfers without first calling this function.

For more information, see [Overview of SerCx2 I/O Transactions](https://learn.microsoft.com/previous-versions/dn265243(v=vs.85)).

#### Examples

To define an *EvtSerCx2CustomTransmitSelectNextTransactionType* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *EvtSerCx2CustomTransmitSelectNextTransactionType* callback function that is named `MyCustomTransmitSelectNextTransactionType`, use the **EVT_SERCX2_CUSTOM_TRANSMIT_SELECT_NEXT_TRANSACTION_TYPE** function type, as shown in this code example:

```cpp
EVT_SERCX2_CUSTOM_TRANSMIT_SELECT_NEXT_TRANSACTION_TYPE  MyCustomTransmitTransactionStart;
```

Then, implement your callback function as follows:

```cpp
_Use_decl_annotations_
SERCX2_TRANSACTION_TYPE
  EvtSerCx2SelectNextTransmitTransactionType(
    WDFDEVICE  Device,
    PMDL  Mdl,
    ULONG  Offset,
    ULONG  RemainingLength,
    SERCX2CUSTOMTRANSMIT  *CustomTransmit,
    PULONG  NextTransactionLength
    )
  {...}
```

The **EVT_SERCX2_CUSTOM_TRANSMIT_SELECT_NEXT_TRANSACTION_TYPE** function type is defined in the Sercx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **EVT_SERCX2_CUSTOM_TRANSMIT_SELECT_NEXT_TRANSACTION_TYPE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)

[MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)

[SERCX2CUSTOMTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SERCX2_CUSTOM_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_custom_transmit_config)

[SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_transmit_config)

[SERCX2_TRANSACTION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ne-sercx-_sercx2_transaction_type)

[SerCx2CustomTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customtransmitcreate)

[SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice)