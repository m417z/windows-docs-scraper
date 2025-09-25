# IUsbTargetPipeContinuousReaderCallbackReadersFailed::OnReaderFailure

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

A driver's **OnReaderFailure** event callback function informs the driver that a continuous reader has reported an error while processing a read request.

## Parameters

### `pPipe` [in]

A pointer to the [IWDFUsbTargetPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbtargetpipe) interface for the USB pipe on which the driver has enabled a continuous reader.

### `hrStatus` [in]

The HRESULT-typed status value that the USB pipe's I/O target returned.

## Return value

The **OnReaderFailure** event callback function must return a Boolean value. If the return value is **TRUE**, the framework resets the USB pipe and then restarts the continuous reader. If the callback function returns **FALSE**, the framework does not reset the device or restart the continuous reader.

## Remarks

To register an **OnReaderFailure** callback function, your driver must provide a pointer to the driver's [IUsbTargetPipeContinuousReaderCallbackReadersFailed](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iusbtargetpipecontinuousreadercallbackreadersfailed) interface when it calls [IWDFUsbTargetPipe2::ConfigureContinuousReader](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetpipe2-configurecontinuousreader).

If a driver has created a continuous reader for a USB pipe, the framework calls the driver's **OnReaderFailure** callback function if the driver's I/O target reports an error when it completes a read request. (If the I/O target successfully completes the request, the framework calls the driver's [IUsbTargetPipeContinuousReaderCallbackReadComplete::OnReaderCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iusbtargetpipecontinuousreadercallbackreadcomplete-onreadercompletion) callback function.)

Before the framework calls a driver's **OnReaderFailure** callback function, it tries to cancel all in-progress read requests. No read requests are in progress when the framework calls the **OnReaderFailure** callback function. The framework does not queue any additional read requests until the **OnReaderFailure** callback function returns.

For information about how the framework synchronizes calls to the **OnReaderFailure** callback function with calls to other callback functions, see the Remarks section of [IUsbTargetPipeContinuousReaderCallbackReadComplete::OnReaderCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iusbtargetpipecontinuousreadercallbackreadcomplete-onreadercompletion).

The **OnReaderFailure** callback function must not call [IWDFIoTargetStateManagement::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotargetstatemanagement-stop) to stop the continuous reader's USB target. (In fact, calling **IWDFIoTargetStateManagement::Stop** in an **OnReaderFailure** callback function causes a deadlock.) In addition, the callback function must not call [IWDFIoTargetStateManagement::Start](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotargetstatemanagement-start) to restart the continuous reader. Instead, the framework restarts the reader if the callback function returns **TRUE**. For more information about when to call **IWDFIoTargetStateManagement::Start** and **IWDFIoTargetStateManagement::Stop** for a continuous reader, see [Working with USB Pipes in UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/working-with-usb-pipes-in-umdf-1-x-drivers).

If a driver does not provide an **OnReaderFailure** callback function and the driver's I/O target reports an error, the framework resets the USB pipe and restarts the continuous reader.

For more information about the **OnReaderFailure** callback function and USB I/O targets, see [Handling a USB I/O Target](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets-in-umdf).

## See also

[IUsbTargetPipeContinuousReaderCallbackReadComplete::OnReaderCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iusbtargetpipecontinuousreadercallbackreadcomplete-onreadercompletion)

[IUsbTargetPipeContinuousReaderCallbackReadersFailed](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iusbtargetpipecontinuousreadercallbackreadersfailed)