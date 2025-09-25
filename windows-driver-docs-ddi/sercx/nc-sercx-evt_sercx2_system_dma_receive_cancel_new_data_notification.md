# EVT_SERCX2_SYSTEM_DMA_RECEIVE_CANCEL_NEW_DATA_NOTIFICATION callback function

## Description

The *EvtSerCx2SystemDmaReceiveCancelNewDataNotification* event callback function is called by version 2 of the serial framework extension (SerCx2) to cancel a new-data notification that SerCx2 enabled in a previous call to the [EvtSerCx2SystemDmaReceiveEnableNewDataNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_enable_new_data_notification) event callback function.

## Parameters

### `SystemDmaReceive` [in]

A [SERCX2SYSTEMDMARECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a system-DMA-receive object. The serial controller driver previously called the [SerCx2SystemDmaReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivecreate) method to create this object.

## Return value

The *EvtSerCx2SystemDmaReceiveCancelNewDataNotification* function returns **TRUE** if the new-data notification was successfully canceled and the serial controller driver can guarantee that this notification will not cause the [SerCx2SystemDmaReceiveNewDataNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivenewdatanotification) method to be called. The function returns **FALSE** if the driver has already called the **SerCx2SystemDmaReceiveNewDataNotification** method, or is about to call this method.

## Remarks

Your serial controller driver can, as an option, implement this function. If implemented, the driver registers the function in the [SerCx2SystemDmaReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivecreate) call that creates the system-DMA-receive object. A driver that implements this function must also implement an [EvtSerCx2SystemDmaReceiveEnableNewDataNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_enable_new_data_notification) event callback function.

If the associated read request times out or is canceled while a new-data notification request is pending, SerCx2 calls the *EvtSerCx2SystemDmaReceiveCancelNewDataNotification* function to cancel the pending notification. If this call returns **FALSE**, SerCx2 expects the serial controller driver to call [SerCx2SystemDmaReceiveNewDataNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivenewdatanotification); only after this call does SerCx2 call the [EvtSerCx2SystemDmaReceiveCleanupTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_cleanup_transaction) function, if it is implemented, and complete the request.

To cancel the new-data notification, the *EvtSerCx2SystemDmaReceiveCancelNewDataNotification* function typically disables the interrupt in the serial controller that indicates that more data is available to be read from the receive FIFO. This interrupt was enabled by a previous call to the *EvtSerCx2SystemDmaReceiveEnableNewDataNotification* function.

For more information, see [SerCx2 System-DMA-Receive Transactions](https://learn.microsoft.com/previous-versions/dn265343(v=vs.85)).

#### Examples

To define an *EvtSerCx2SystemDmaReceiveCancelNewDataNotification* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *EvtSerCx2SystemDmaReceiveCancelNewDataNotification* callback function that is named `MySystemDmaReceiveCancelNewDataNotification`, use the **EVT_SERCX2_SYSTEM_DMA_RECEIVE_CANCEL_NEW_DATA_NOTIFICATION** function type, as shown in this code example:

```cpp
EVT_SERCX2_SYSTEM_DMA_RECEIVE_CANCEL_NEW_DATA_NOTIFICATION  MySystemDmaReceiveCancelNewDataNotification;
```

Then, implement your callback function as follows:

```cpp
_Use_decl_annotations_
BOOLEAN
  MySystemDmaReceiveCancelNewDataNotification(
    SERCX2SYSTEMDMARECEIVE  SystemDmaReceive
    )
  {...}
```

The **EVT_SERCX2_SYSTEM_DMA_RECEIVE_CANCEL_NEW_DATA_NOTIFICATION** function type is defined in the Sercx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **EVT_SERCX2_SYSTEM_DMA_RECEIVE_CANCEL_NEW_DATA_NOTIFICATION** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[EvtSerCx2SystemDmaReceiveEnableNewDataNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_receive_enable_new_data_notification)

[SERCX2SYSTEMDMARECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2SystemDmaReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivecreate)

[SerCx2SystemDmaReceiveNewDataNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivenewdatanotification)