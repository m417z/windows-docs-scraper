# IUsbTargetPipeContinuousReaderCallbackReadComplete::OnReaderCompletion

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

A driver's **OnReaderCompletion** event callback function informs the driver that a continuous reader has successfully completed a read request.

## Parameters

### `pPipe` [in]

A pointer to the [IWDFUsbTargetPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbtargetpipe) interface for the USB pipe on which the driver has enabled a continuous reader.

### `pMemory` [in]

A pointer to the [IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory) interface for a read buffer that contains data that was read from the USB pipe.

### `NumBytesTransferred` [in]

The number of bytes that the read buffer contains.

### `Context` [in]

A pointer to driver-supplied context information that the driver provided when it previously called [IWDFUsbTargetPipe2::ConfigureContinuousReader](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetpipe2-configurecontinuousreader).

## Remarks

To register an **IUsbTargetPipeContinuousReaderCallbackReadComplete::OnReaderCompletion** callback function, your driver must provide a pointer to the driver's [IUsbTargetPipeContinuousReaderCallbackReadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iusbtargetpipecontinuousreadercallbackreadcomplete) interface when it calls [IWDFUsbTargetPipe2::ConfigureContinuousReader](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetpipe2-configurecontinuousreader).

If a driver has created a continuous reader for a USB pipe, the framework calls the driver's **OnReaderCompletion** callback function each time the driver's I/O target successfully completes a read request. If the I/O target does not successfully complete a request, the framework calls the driver's [IUsbTargetPipeContinuousReaderCallbackReadersFailed::OnReaderFailure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iusbtargetpipecontinuousreadercallbackreadersfailed-onreaderfailure) callback function.

To access the buffer that contains data that was read from the device, the driver can call [IWDFMemory::GetDataBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfmemory-getdatabuffer). The framework writes the data into the buffer, after the header that is defined by the *HeaderLength* parameter of [IWDFUsbTargetPipe2::ConfigureContinuousReader](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetpipe2-configurecontinuousreader). Note that the pointer that **IWDFMemory::GetDataBuffer** returns points to the beginning of the header, but the **OnReaderCompletion** callback function's *NumBytesTransferred* parameter does not include the header's length.

By default, the framework deletes the buffer's memory object after the **OnReaderCompletion** callback function returns. However, you might want the memory object to remain valid after the callback function returns. For example, you might want your driver to store the memory object's interface pointer in the framework pipe object's [context space](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfobject-assigncontext) so that the driver can process the memory object's contents after the callback function returns. To extend the lifetime of the memory object, the callback function must call the buffer's [IWDFMemory::AddRef](https://learn.microsoft.com/windows-hardware/drivers/wdf/umdf-based-on-com-subset) method. Subsequently, the driver must call the buffer's [IWDFMemory::Release](https://learn.microsoft.com/windows-hardware/drivers/wdf/umdf-based-on-com-subset) method so that the framework can delete the object.

The framework synchronizes calls to the **OnReaderCompletion** and [IUsbTargetPipeContinuousReaderCallbackReadersFailed::OnReaderFailure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iusbtargetpipecontinuousreadercallbackreadersfailed-onreaderfailure) callback functions according to the following rules:

* These callback functions do not run simultaneously for an individual USB pipe.
* If the driver creates multiple continuous readers for multiple USB pipes, with multiple **OnReaderCompletion** and [OnReaderFailure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iusbtargetpipecontinuousreadercallbackreadersfailed-onreaderfailure) callback functions, the multiple callback functions can run simultaneously.
* If the driver has specified the default *NumPendingReads* value when it calls [IWDFUsbTargetPipe2::ConfigureContinuousReader](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetpipe2-configurecontinuousreader) (or if it specifies any *NumPendingReads* value that is greater than 1), and if a read request completes while the **OnReaderCompletion** callback function is executing, the framework can call the **OnReaderCompletion** callback function again before the callback function returns.
* The framework does not synchronize these callback functions with any other callback functions.

When your driver calls [IWDFUsbTargetPipe2::ConfigureContinuousReader](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetpipe2-configurecontinuousreader), it can specify an [IObjectCleanup::OnCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iobjectcleanup-oncleanup) callback function. The framework will call that callback function when it attempts to delete the memory object, after the **OnReaderCompletion** callback function returns.

For more information about the **OnReaderCompletion** callback function and USB I/O targets, see [Handling a USB I/O Target](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets-in-umdf).

## See also

[IUsbTargetPipeContinuousReaderCallbackReadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iusbtargetpipecontinuousreadercallbackreadcomplete)

[IUsbTargetPipeContinuousReaderCallbackReadersFailed::OnReaderFailure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iusbtargetpipecontinuousreadercallbackreadersfailed-onreaderfailure)