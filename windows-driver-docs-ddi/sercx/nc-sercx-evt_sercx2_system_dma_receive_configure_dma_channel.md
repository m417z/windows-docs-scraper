# EVT_SERCX2_SYSTEM_DMA_RECEIVE_CONFIGURE_DMA_CHANNEL callback function

## Description

The *EvtSerCx2SystemDmaReceiveConfigureDmaChannel* event callback function is called by version 2 of the serial framework extension (SerCx2) to let the serial controller driver do any custom configuration of the DMA adapter that might be required before the start of each transfer in a system-DMA-receive transaction.

## Parameters

### `SystemDmaReceive` [in]

A [SERCX2SYSTEMDMARECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a system-DMA-receive object. The serial controller driver previously called the [SerCx2SystemDmaReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivecreate) method to create this object.

### `Mdl` [in]

A pointer to an [MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) that describes the memory pages that are spanned by the read buffer for the system-DMA-receive transaction. The scatter/gather list for the DMA transfer will use the region of this memory that is specified by the *Offset* and *Length* parameters.

### `Offset` [in]

The starting offset for the data transfer. This parameter is a byte offset from the start of the buffer region described by the MDL. If the MDL specifies a total of N bytes of buffer space, possible values of *Offset* are in the range 0 to N–1.

### `Length` [in]

The size, in bytes, of the data transfer. If the MDL specifies a total of N bytes of buffer space, possible values of *Length* are in the range 1 to N–*Offset*.

## Return value

The *EvtSerCx2SystemDmaReceiveConfigureDmaChannel* function returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error status code.

## Remarks

Your serial controller driver can, as an option, implement this function. If implemented, the driver registers the function in the [SerCx2SystemDmaReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivecreate) call that creates the system-DMA-receive object.

Before initiating a system-DMA-receive transaction, SerCx2 calls the *EvtSerCx2SystemDmaReceiveConfigureDmaChannel* function, if it is implemented. This function performs any special configuration of the system DMA controller that might be required before SerCx2 starts the system-DMA-receive transaction.

The serial controller driver can call a method such as [SerCx2SystemDmaReceiveGetDmaEnabler](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivegetdmaenabler) to get the DMA enabler for the system DMA controller used for system-DMA-receive transactions.

For more information, see [SerCx2 System-DMA-Receive Transactions](https://learn.microsoft.com/previous-versions/dn265343(v=vs.85)).

#### Examples

To define an *EvtSerCx2SystemDmaReceiveConfigureDmaChannel* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *EvtSerCx2SystemDmaReceiveConfigureDmaChannel* callback function that is named `MySystemDmaReceiveConfigureDmaChannel`, use the **EVT_SERCX2_SYSTEM_DMA_RECEIVE_CONFIGURE_DMA_CHANNEL** function type, as shown in this code example:

```cpp
EVT_SERCX2_SYSTEM_DMA_RECEIVE_CONFIGURE_DMA_CHANNEL  MySystemDmaReceiveConfigureDmaChannel;
```

Then, implement your callback function as follows:

```cpp
_Use_decl_annotations_
NTSTATUS
  MySystemDmaReceiveConfigureDmaChannel(
    SERCX2SYSTEMDMARECEIVE SystemDmaReceive,
    PMDL Mdl,
    ULONG Offset,
    ULONG Length
    )
  {...}
```

The **EVT_SERCX2_SYSTEM_DMA_RECEIVE_CONFIGURE_DMA_CHANNEL** function type is defined in the Sercx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **EVT_SERCX2_SYSTEM_DMA_RECEIVE_CONFIGURE_DMA_CHANNEL** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)

[SERCX2SYSTEMDMARECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2SystemDmaReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivecreate)

[SerCx2SystemDmaReceiveGetDmaEnabler](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivegetdmaenabler)