# EVT_SERCX2_SYSTEM_DMA_RECEIVE_ENABLE_NEW_DATA_NOTIFICATION callback function

## Description

The *EvtSerCx2SystemDmaReceiveEnableNewDataNotification* event callback function is called by version 2 of the serial framework extension (SerCx2) to enable the serial controller driver to notify SerCx2 when the serial controller receives new data.

## Parameters

### `SystemDmaReceive` [in]

A [SERCX2SYSTEMDMARECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a system-DMA-receive object. The serial controller driver previously called the [SerCx2SystemDmaReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivecreate) method to create this object.

## Remarks

Your serial controller driver can, as an option, implement this function. If implemented, the driver registers the function in the [SerCx2SystemDmaReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivecreate) call that creates the system-DMA-receive object.

After the *EvtSerCx2SystemDmaReceiveEnableNewDataNotification* function is called to enable a new-data notification for a system-DMA-receive transaction, the serial controller driver must call the [SerCx2SystemDmaReceiveNewDataNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivenewdatanotification) method to notify SerCx2 when the driver detects that one or more bytes of received data either are ready to be transferred or have already been transferred by the system DMA controller.

The new-data notification enabled by the *EvtSerCx2SystemDmaReceiveEnableNewDataNotification* function is a one-shot notification. After this function is called and the serial controller driver sends a new-data notification to SerCx2, no further notification is sent until SerCx2 calls the function again to enable another notification.

The *EvtSerCx2SystemDmaReceiveEnableNewDataNotification* function typically enables an interrupt to be triggered when the serial controller receives data from the peripheral device.

No more than one new-data notification can be pending at a time. After SerCx2 calls the *EvtSerCx2SystemDmaReceiveEnableNewDataNotification* function to enable a new-data notification, SerCx2 does not call this function again until the controller driver calls **SerCx2SystemDmaReceiveNewDataNotification**.

A pending new-data notification can be canceled if the associated read request times out or is canceled. To cancel a new-data notification for a system-DMA-receive transaction, SerCx2 calls the [EvtSerCx2SystemDmaReceiveCancelNewDataNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_cancel_new_data_notification) event callback function. A driver that implements an *EvtSerCx2SystemDmaReceiveEnableNewDataNotification* function must also implement an *EvtSerCx2SystemDmaReceiveCancelNewDataNotification* function.

SerCx2 uses new-data notifications to efficiently manage interval time-outs that occur during the handling of read requests that are processed as system-DMA-receive transactions.

For more information, see [SerCx2 System-DMA-Receive Transactions](https://learn.microsoft.com/previous-versions/dn265343(v=vs.85)).

#### Examples

To define an *EvtSerCx2SystemDmaReceiveEnableNewDataNotification* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *EvtSerCx2SystemDmaReceiveEnableNewDataNotification* callback function that is named `MySystemDmaReceiveEnableNewDataNotification`, use the **EVT_SERCX2_SYSTEM_DMA_RECEIVE_ENABLE_NEW_DATA_NOTIFICATION** function type, as shown in this code example:

```cpp
EVT_SERCX2_SYSTEM_DMA_RECEIVE_ENABLE_NEW_DATA_NOTIFICATION  MySystemDmaReceiveEnableNewDataNotification;
```

Then, implement your callback function as follows:

```cpp
_Use_decl_annotations_
VOID
  MySystemDmaReceiveEnableNewDataNotification(
    SERCX2SYSTEMDMARECEIVE  SystemDmaReceive
    )
  {...}
```

The **EVT_SERCX2_SYSTEM_DMA_RECEIVE_ENABLE_NEW_DATA_NOTIFICATION** function type is defined in the Sercx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **EVT_SERCX2_SYSTEM_DMA_RECEIVE_ENABLE_NEW_DATA_NOTIFICATION** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[EvtSerCx2SystemDmaReceiveCancelNewDataNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_cancel_new_data_notification)

[EvtSerCx2SystemDmaReceiveCleanupTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_cleanup_transaction)

[ReadDmaCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pread_dma_counter)

[SERCX2SYSTEMDMARECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2SystemDmaReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivecreate)

[SerCx2SystemDmaReceiveNewDataNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivenewdatanotification)